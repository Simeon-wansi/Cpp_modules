#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "CommandDispatcher.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <cstring>
#include <cerrno>

Server::Server(int port, const std::string& password) 
    : _port(port), _password(password), _serverName("irc.server.com"), _server_fd(-1) {
    
        //initialiase command dispatcher
    _commandDispatcher =  new CommandDispatcher();

    // Initialize poll array
    for (int i = 0; i < MAX_CLIENTS; i++) {
        _poll_fds[i].fd = -1;
        _poll_fds[i].events = POLLIN;
        _poll_fds[i].revents = 0;
    }
    setupSocket();
}

// Server::Server(const std::string& name, const std::string& password)
//     : _port(8080), _password(password), _serverName(name), _server_fd(-1){
//          // Initialize poll array
//     for (int i = 0; i < MAX_CLIENTS; i++) {
//         _poll_fds[i].fd = -1;
//         _poll_fds[i].events = POLLIN;
//         _poll_fds[i].revents = 0;
//     }
//     setupSocket();
// }

// Server::Server()
//     : _port(8080), _password("password"), _serverName("irc.server.com"), _server_fd(-1)
// {
//     for (int i = 0; i < MAX_CLIENTS; i++) {
//         _poll_fds[i].fd = -1;
//         _poll_fds[i].events = POLLIN;
//         _poll_fds[i].revents = 0;
//     }
//     setupSocket();
// }

Server::~Server() {
    delete _commandDispatcher;
    cleanup();
}

void Server::setupSocket() {
    // Create socket
    _server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_server_fd < 0) {
        throw std::runtime_error("Failed to create socket");
    }
    
    // Set socket options
    int opt = 1;
    if (setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        close(_server_fd);
        throw std::runtime_error("Failed to set socket options");
    }
    
    // Make socket non-blocking
    if (fcntl(_server_fd, F_SETFL, O_NONBLOCK) < 0) {
        close(_server_fd);
        throw std::runtime_error("Failed to set non-blocking mode");
    }
    
    // Setup server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(_port);
    
    // Bind
    if (bind(_server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        close(_server_fd);
        throw std::runtime_error("Failed to bind socket");
    }
    
    // Listen
    if (listen(_server_fd, 10) < 0) {
        close(_server_fd);
        throw std::runtime_error("Failed to listen on socket");
    }
    
    // Add server socket to poll array (always at index 0)
    _poll_fds[0].fd = _server_fd;
    _poll_fds[0].events = POLLIN;
    
    std::cout << "Server listening on port " << _port << std::endl;
}

void Server::start() {
    std::cout << "IRC Server started. Waiting for connections..." << std::endl;
    
    while (true) {
        // Poll all file descriptors
        int poll_result = poll(_poll_fds, MAX_CLIENTS, -1);
        
        if (poll_result < 0) {
            if (errno == EINTR) continue;  // Interrupted by signal, retry
            std::cerr << "Poll error: " << strerror(errno) << std::endl;
            break;
        }
        
        // Check server socket for new connections
        if (_poll_fds[0].revents & POLLIN) {
            handleNewConnection();
        }
        
        // Check all client sockets for activity
        for (int i = 1; i < MAX_CLIENTS; i++) {
            if (_poll_fds[i].fd == -1) continue;  // Empty slot
            
            if (_poll_fds[i].revents & POLLIN) {
                handleClientMessage(_poll_fds[i].fd);
            }
            
            if (_poll_fds[i].revents & (POLLHUP | POLLERR)) {
                handleClientDisconnection(_poll_fds[i].fd);
            }
        }
    }
}


void Server::stop()
{
    cleanup();
}

// void Server::addClient(Client* client)
// {
//     addToPoll(client->getSocketFd());
// }

void Server::handleNewConnection() {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    int client_fd = accept(_server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        if (errno != EAGAIN && errno != EWOULDBLOCK) {
            std::cerr << "Accept error: " << strerror(errno) << std::endl;
        }
        return;
    }
    
    // Make client socket non-blocking
    if (fcntl(client_fd, F_SETFL, O_NONBLOCK) < 0) {
        std::cerr << "Failed to set client socket non-blocking" << std::endl;
        close(client_fd);
        return;
    }
    
    // Find empty slot in poll array
    int slot = findEmptySlot();
    if (slot == -1) {
        std::cerr << "Server full, rejecting client" << std::endl;
        close(client_fd);
        return;
    }
    
    // Add to poll array
    _poll_fds[slot].fd = client_fd;
    _poll_fds[slot].events = POLLIN;
    _poll_fds[slot].revents = 0;
    
    // Create Client object with merged constructor
    Client* client = new Client(client_fd, "127.0.0.1", "");
    _clients[client_fd] = client;
    
    std::cout << "New client connected: fd " << client_fd << " (slot " << slot << ")" << std::endl;
}

void Server::handleClientMessage(int client_fd) {
    Client* client = getClientByFd(client_fd);
    if (!client) return;
    
    char buffer[1024];
    ssize_t bytes = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes <= 0) {
        if (bytes == 0 || (errno != EAGAIN && errno != EWOULDBLOCK)) {
            handleClientDisconnection(client_fd);
        }
        return;
    }
    
    buffer[bytes] = '\0';
    client->addToBuffer(buffer);
    
    // Process complete messages
    std::vector<std::string> messages = client->extractCompleteMessages();
    for (size_t i = 0; i < messages.size(); i++) {
        processClientCommand(client, messages[i]);
    }
}

void Server::handleClientDisconnection(int client_fd) {
    std::cout << "Client " << client_fd << " disconnected" << std::endl;
    
    // Remove from poll array
    removeFromPoll(client_fd);
    
    // Clean up client object
    Client* client = getClientByFd(client_fd);
    if (client) {
        // Client destructor will handle leaving channels
        delete client;
        _clients.erase(client_fd);
    }
    
    close(client_fd);
}

void Server::processClientCommand(Client* client, const std::string& command) {
    std::cout << "Client " << client->getSocketFd() << " sent: " << command << std::endl;
    
    if (!_commandDispatcher) {
        std::cerr << "Error: CommandDispatcher not initialized" << std::endl;
        return;
    }
    _commandDispatcher->executeCommand(*this, *client, command);
}

// Utility functions
Client* Server::getClientByFd(int fd) {
    std::map<int, Client*>::iterator it = _clients.find(fd);
    return (it != _clients.end()) ? it->second : NULL;
}

Client* Server::getClientByNick(const std::string& nickname) {
    for (std::map<int, Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        if (it->second->getNickName() == nickname) {
            return it->second;
        }
    }
    return NULL;
}

Channel* Server::getChannel(const std::string& name) {
    std::map<std::string, Channel*>::iterator it = _channels.find(name);
    return (it != _channels.end()) ? it->second : NULL;
}

std::set<Channel*> Server::getChannelsByClient(Client* client)
{
    return (client->getChannels());
}


std::map<std::string, Channel*> Server::getChannels()
{
    return _channels;    
}

Channel* Server::createChannel(const std::string& name, Client* creator) {
    if (getChannel(name) != NULL) {
        return NULL;  // Channel already exists
    }
    
    Channel* channel = new Channel(name, creator);
    _channels[name] = channel;
    return channel;
}

// Methods needed command handlers
std::string Server::getServerName() const {
    return _serverName;
}

std::vector<Client*> Server::getClients() const {
    std::vector<Client*> result;
    for (std::map<int, Client*>::const_iterator it = _clients.begin(); it != _clients.end(); ++it) {
        result.push_back(it->second);
    }
    return result;
}

void Server::registerChannel(Channel* channel) {
    if (channel) {
        _channels[channel->getName()] = channel;
    }
}

bool Server::isNickNameInUse(const std::string& nickName) {
    for (std::map<int, Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        if (it->second->getNickName() == nickName) {
            return true;
        }
    }
    return false;
}

void Server::removeChannel(const std::string& channelName) {
    std::map<std::string, Channel*>::iterator it = _channels.find(channelName);
    if (it != _channels.end()) {
        delete it->second;
        _channels.erase(it);
    }
}

void Server::removeClient(int socketFd, const std::string& reason) {
    Client* client = getClientByFd(socketFd);
    if (client) {
        // Inform all channels about quit
        for (std::map<std::string, Channel*>::iterator ch = _channels.begin(); ch != _channels.end(); ++ch) {
            if (ch->second->isClientInChannel(client)) {
                ch->second->broadcast(":" + client->getPrefix() + " QUIT :" + reason + "\r\n");
                ch->second->removeClient(client);
            }
        }
        
        // Remove from server's client list and clean up
        handleClientDisconnection(socketFd);
    }
}

// Cleanup and utility methods
void Server::cleanup() {
    // Close all client connections
    for (std::map<int, Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        close(it->first);
        delete it->second;
    }
    _clients.clear();
    
    // Delete all channels
    for (std::map<std::string, Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it) {
        delete it->second;
    }
    _channels.clear();
    
    // Close server socket
    if (_server_fd >= 0) {
        close(_server_fd);
        _server_fd = -1;
    }
}

int Server::findEmptySlot() {
    for (int i = 1; i < MAX_CLIENTS; i++) {  // Start at 1, slot 0 is server
        if (_poll_fds[i].fd == -1) {
            return i;
        }
    }
    return -1;
}

void Server::removeFromPoll(int fd) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (_poll_fds[i].fd == fd) {
            _poll_fds[i].fd = -1;
            _poll_fds[i].revents = 0;
            break;
        }
    }
}


void Server::addToPoll(int fd) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (_poll_fds[i].fd == -1) {
            _poll_fds[i].fd = fd;
            _poll_fds[i].events = POLLIN;
            _poll_fds[i].revents = 0;      // Clear any previous events
            return;
        }
    }
    std::cerr << "Warning: Poll array full, cannot add fd " << fd << std::endl;
}

int Server::findPollIndex(int fd) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (_poll_fds[i].fd == fd)
            return i;
    }
    return -1;  // Not found
}
