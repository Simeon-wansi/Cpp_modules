#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>
#include <map>
#include <poll.h>

// Forward declarations
class Client;
class Channel;

class Server {
private:
    // Network configuration
    int _port;
    std::string _password;
    int _server_fd;
    
    // Client management
    static const int MAX_CLIENTS = 100;
    struct pollfd _poll_fds[MAX_CLIENTS];
    std::map<int, Client*> _clients;  // fd -> Client object
    
    // IRC data
    std::map<std::string, Channel*> _channels;  // channel name -> Channel object
    
public:
    // Constructor & Destructor
    Server(int port, const std::string& password);
    ~Server();
    
    // Main server operations
    void start();
    void stop();
    
    // Network event handlers
    void handleNewConnection();
    void handleClientMessage(int client_fd);
    void handleClientDisconnection(int client_fd);
    
    // Utility functions
    Client* getClientByFd(int fd);
    Client* getClientByNick(const std::string& nickname);
    Channel* getChannel(const std::string& name);
    Channel* createChannel(const std::string& name, Client* creator);
    
    // Getters
    const std::string& getPassword() const { return _password; }
    
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