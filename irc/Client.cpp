#include "Client.hpp"
#include "Channel.hpp"  // We'll create this later
#include <unistd.h>
#include <sys/socket.h>
#include <sstream>

Client::Client(int fd) 
    : _fd(fd), _password_authenticated(false), _registered(false) {
    _hostname = "localhost";  // Default hostname
}

Client::~Client() {
    // Leave all channels before destruction
    std::set<Channel*> channels_copy = _channels;  // Copy to avoid iterator invalidation
    for (std::set<Channel*>::iterator it = channels_copy.begin(); it != channels_copy.end(); ++it) {
        leaveChannel(*it);
    }
}

void Client::setNickname(const std::string& nick) {
    _nickname = nick;
    updateRegistrationStatus();
}

void Client::setUsername(const std::string& user, const std::string& realname) {
    _username = user;
    _realname = realname;
    updateRegistrationStatus();
}

void Client::updateRegistrationStatus() {
    // Client is registered when they have both nickname and username set
    bool was_registered = _registered;
    _registered = !_nickname.empty() && !_username.empty() && _password_authenticated;
    
    // If client just became registered, we could send welcome messages here
    if (_registered && !was_registered) {
        // Welcome sequence will be handled by Server class
    }
}

void Client::sendMessage(const std::string& message) {
    std::string full_message = message;
    if (full_message.size() == 0 || full_message[full_message.size() - 1] != '\n') {
        full_message += "\r\n";  // IRC protocol requires CRLF
    }
    send(_fd, full_message.c_str(), full_message.length(), 0);
}

void Client::addToBuffer(const std::string& data) {
    _input_buffer += data;
}

std::vector<std::string> Client::extractCompleteMessages() {
    std::vector<std::string> messages;
    std::string::size_type pos;
    
    // Find complete lines ending with \n or \r\n
    while ((pos = _input_buffer.find('\n')) != std::string::npos) {
        std::string line = _input_buffer.substr(0, pos);
        
        // Remove \r if present (handle \r\n)
        if (!line.empty() && line[line.length() - 1] == '\r') {
            line.erase(line.length() - 1);
        }
        
        messages.push_back(line);
        _input_buffer.erase(0, pos + 1);
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
    prefix += _nickname.empty() ? "*" : _nickname;
    prefix += "!";
    prefix += _username.empty() ? "*" : _username;
    prefix += "@";
    prefix += _hostname;
    return prefix;
}