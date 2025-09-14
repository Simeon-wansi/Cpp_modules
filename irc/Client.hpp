#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>
#include <set>

// Forward declaration
class Channel;

class Client {
private:
    // Network info
    int _fd;
    std::string _hostname;
    
    // Authentication state
    bool _password_authenticated;
    bool _registered;  // Has completed NICK + USER commands
    
    // IRC identity
    std::string _nickname;
    std::string _username;
    std::string _realname;
    
    // Message buffering (for partial messages)
    std::string _input_buffer;
    
    // Channel membership
    std::set<Channel*> _channels;

public:
    // Constructor & Destructor
    Client(int fd);
    ~Client();
    
    // Authentication
    void setPasswordAuthenticated(bool auth) { _password_authenticated = auth; }
    bool isPasswordAuthenticated() const { return _password_authenticated; }
    bool isRegistered() const { return _registered; }
    void updateRegistrationStatus();  // Check if NICK+USER are both set
    
    // Identity management
    void setNickname(const std::string& nick);
    void setUsername(const std::string& user, const std::string& realname);
    
    const std::string& getNickname() const { return _nickname; }
    const std::string& getUsername() const { return _username; }
    const std::string& getRealname() const { return _realname; }
    
    // Network operations
    int getFd() const { return _fd; }
    void sendMessage(const std::string& message);
    
    // Message buffering
    void addToBuffer(const std::string& data);
    std::vector<std::string> extractCompleteMessages();
    
    // Channel operations
    void joinChannel(Channel* channel);
    void leaveChannel(Channel* channel);
    bool isInChannel(Channel* channel) const;
    const std::set<Channel*>& getChannels() const { return _channels; }
    
    // Utility
    std::string getPrefix() const;  // Returns ":nick!user@host"
    
private:
    void updateRegistration();
};

#endif // CLIENT_HPP