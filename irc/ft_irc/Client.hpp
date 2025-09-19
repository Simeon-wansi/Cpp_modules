#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>
#include <set>

// Forward declaration
class Channel;

// Client states for IRC protocol
enum clientState {
    CONNECTED,      // Just connected, no auth yet
    AUTHENTICATED,  // Password verified
    REGISTERED      // Has NICK + USER, fully ready
};

class Client {
private:
    // Network info
    int _socketFd;
    std::string _ipAddress;
    std::string _hostname;
    
    // Authentication and state
    clientState _state;
    
    // IRC identity
    std::string _nickName;
    std::string _userName;
    std::string _realName;
    
    // Channel management
    int _channelCount;
    std::set<Channel*> _channels;
    
    // Message buffering (for partial messages)
    std::string _inputBuffer;

public:
    // Constructor & Destructor
    Client(int socketFd, const std::string& ipAddress = "127.0.0.1", const std::string& nickName = "");
    ~Client();
    
    // State management
    clientState getState() const { return _state; }
    void setState(clientState state) { _state = state; }
    
    // Identity getters/setters
    const std::string& getNickName() const { return _nickName; }
    const std::string& getUserName() const { return _userName; }
    const std::string& getRealName() const { return _realName; }
    const std::string& getIpAddress() const { return _ipAddress; }
    // std::set<Channel*> getChannels() const { return _channels; }
    
    void setNickName(const std::string& nick) { _nickName = nick; }
    void setUserName(const std::string& user) { _userName = user; }
    void setRealName(const std::string& real) { _realName = real; }
    
    // Network operations
    int getSocketFd() const { return _socketFd; }
    void write(const std::string& message);  //  method name
    
    // Message buffering (our approach)
    void addToBuffer(const std::string& data);
    std::vector<std::string> extractCompleteMessages();
    
    // Channel operations
    void joinChannel(Channel* channel);
    void leaveChannel(Channel* channel);
    bool isInChannel(Channel* channel) const;
    const std::set<Channel*>& getChannels() const { return _channels; }
    
    int getChannelCount() const { return _channelCount; }
    void incrementChannelCount() { _channelCount++; }
    void decrementChannelCount() { if (_channelCount > 0) _channelCount--; }
    
    // IRC utility
    std::string getPrefix() const;  // Returns ":nick!user@host"
};

#endif // CLIENT_HPP