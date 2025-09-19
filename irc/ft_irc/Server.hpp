#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>
#include <map>
#include <poll.h>
#include <set>

#define MAX_CLIENTS 100
// Forward declarations
class Client;
class Channel;
class CommandDispatcher;

class Server {
private:
    // Network configuration
    int _port;
    std::string _password;
    std::string _serverName;
    int _server_fd;
    
    // Client management
    struct pollfd _poll_fds[MAX_CLIENTS];
    std::map<int, Client*> _clients;  // fd -> Client object
    
    // IRC data
    std::map<std::string, Channel*> _channels;  // channel name -> Channel object

    // Command processing 
    CommandDispatcher* _commandDispatcher;
    
public:
    // Constructor & Destructor
    Server(int port, const std::string& password);
    // Server(const std::string& name, const std::string& password);
    // Server();
    ~Server();
    
    // Main server operations
    void start();
    void stop();
    
    // Network event handlers
    void handleNewConnection();
    void handleClientMessage(int client_fd);
    void handleClientDisconnection(int client_fd);
    void processClientCommand(Client* client, const std::string& command);
    
    // Client management
    Client* getClientByFd(int fd);
    Client* getClientByNick(const std::string& nickname);
    std::vector<Client*> getClients() const;
    void removeClient(int socketFd, const std::string& reason);
    bool isNickNameInUse(const std::string& nickName);
      
    // void addClient(Client* client);
    
    // Channel management
    Channel* getChannel(const std::string& name);
    Channel* createChannel(const std::string& name, Client* creator);
    std::set<Channel*> getChannelsByClient(Client* client);
    void registerChannel(Channel* channel);
    void removeChannel(const std::string& channelName);
    std::map<std::string, Channel*> getChannels();

    // Getters needed by command handlers
    const std::string& getPassword() const { return _password; }
    std::string getServerName() const;
    
private:
    // Internal setup
    void setupSocket();
    void cleanup();
    
    // Poll management
    void addToPoll(int fd);
    void removeFromPoll(int fd);
    int findPollIndex(int fd);
    int findEmptySlot();
};

#endif // SERVER_HPP










// #ifndef SERVER_HPP
// #define SERVER_HPP

// #include <string>
// #include <vector>
// #include <map>
// #include "Channel.hpp"
// #include "mockClient.hpp"


// class Client;
// class Channel;

// class Server
// {
// private:
//     //network config
//     std::string _serverName;
//     std::string _password;
//     int port;

//     std::map<std::string, Channel*> _channels;
//     std::map<std::string, Client*> _clients;
    

// public:
//     //constructor and destructor 
//     Server(const std::string& name = "irc.server.com", const std::string& password = "pass")
//         : _serverName(name), _password(password) {}

//     ~Server();    

//     // Your command handlers will need these methods
//     std::string getServerName() const { return _serverName; }
//     std::string getPassword() const { return _password; }
//     std::vector<Channel*> getChannelsByClient(Client* client);
//     std::vector<Client*> getClients() const;
  

//     Channel* getChannel(const std::string& name);
//     void registerChannel(Channel* channel);
    
//     // The `nick.cpp` file uses this to check for existing nicknames
//     bool isNickNameInUse(const std::string& nickName);

//     // Add mock clients for testing
//     void addClient(Client* client);
    
//     // Your `privmsg.cpp` needs this
//     Client* getClientWithNick(const std::string& nickname);
//     void removeChannel(const std::string& channelName);
    
//     void removeClient(int socketFd, const std::string& reason);
//     const std::map<std::string, Channel*>& getChannels() const { return _channels; }
// };

// #endif