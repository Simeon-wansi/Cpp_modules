#include "Client.hpp"
#include "Channel.hpp"
#include <unistd.h>
#include <sys/socket.h>
#include <sstream>

Client::Client(int socketFd, const std::string& ipAddress, const std::string& nickName)
    : _socketFd(socketFd), _ipAddress(ipAddress), _hostname("localhost"), 
      _state(CONNECTED), _nickName(nickName), _channelCount(0) {
    // Client starts in CONNECTED state, needs to authenticate
}

Client::~Client() {
    // Leave all channels before destruction
    std::set<Channel*> channels_copy = _channels;  // Copy to avoid iterator invalidation
    for (std::set<Channel*>::iterator it = channels_copy.begin(); it != channels_copy.end(); ++it) {
        leaveChannel(*it);
    }
}

void Client::write(const std::string& message) {
    std::string full_message = message;
    
    // Add CRLF if not present (IRC protocol requirement)
    if (full_message.size() == 0 || full_message[full_message.size() - 1] != '\n') {
        full_message += "\r\n";
    }
    
    send(_socketFd, full_message.c_str(), full_message.length(), 0);
}

void Client::addToBuffer(const std::string& data) {
    _inputBuffer += data;
}

std::vector<std::string> Client::extractCompleteMessages() {
    std::vector<std::string> messages;
    std::string::size_type pos;
    
    // Find complete lines ending with \n or \r\n
    while ((pos = _inputBuffer.find('\n')) != std::string::npos) {
        std::string line = _inputBuffer.substr(0, pos);
        
        // Remove \r if present (handle \r\n)
        if (!line.empty() && line[line.length() - 1] == '\r') {
            line.erase(line.length() - 1);
        }
        
        messages.push_back(line);
        _inputBuffer.erase(0, pos + 1);
    }
    
    return messages;
}

void Client::joinChannel(Channel* channel) {
    if (channel) {
        _channels.insert(channel);
    }
}

void Client::leaveChannel(Channel* channel) {
    if (channel) {
        _channels.erase(channel);
    }
}

bool Client::isInChannel(Channel* channel) const {
    return _channels.find(channel) != _channels.end();
}

std::string Client::getPrefix() const {
    // IRC prefix format: :nickname!username@hostname
    std::string prefix = ":";
    prefix += _nickName.empty() ? "*" : _nickName;
    prefix += "!";
    prefix += _userName.empty() ? "*" : _userName;
    prefix += "@";
    prefix += _hostname;
    return prefix;
}