#include "Channel.hpp"
#include "Client.hpp"
#include <sstream>
#include <algorithm>

Channel::Channel(const std::string& name, Client* creator) 
    : _name(name), _invite_only(false), _topic_restricted(false), 
      _has_key(false), _has_user_limit(false), _user_limit(0) {
    
    // Creator automatically becomes first member and operator
    if (creator) {
        _members.insert(creator);
        _operators.insert(creator);
        creator->joinChannel(this);
    }
}

Channel::~Channel() {
    // Remove this channel from all clients when destroyed
    std::set<Client*> members_copy = _members;  // Copy to avoid iterator invalidation
    for (std::set<Client*>::iterator it = members_copy.begin(); it != members_copy.end(); ++it) {
        (*it)->leaveChannel(this);
    }
}

void Channel::addMember(Client* client) {
    if (client && _members.find(client) == _members.end()) {
        _members.insert(client);
        client->joinChannel(this);
        
        // Remove from invited list if they were invited
        _invited.erase(client);
    }
}

void Channel::removeMember(Client* client) {
    if (client) {
        removeFromAllSets(client);
        client->leaveChannel(this);
    }
}

bool Channel::hasMember(Client* client) const {
    return client && _members.find(client) != _members.end();
}

void Channel::addOperator(Client* client) {
    if (client && hasMember(client)) {
        _operators.insert(client);
    }
}

void Channel::removeOperator(Client* client) {
    if (client) {
        _operators.erase(client);
    }
}

bool Channel::isOperator(Client* client) const {
    return client && _operators.find(client) != _operators.end();
}

void Channel::inviteUser(Client* client) {
    if (client) {
        _invited.insert(client);
    }
}

void Channel::removeInvitation(Client* client) {
    if (client) {
        _invited.erase(client);
    }
}

bool Channel::isInvited(Client* client) const {
    return client && _invited.find(client) != _invited.end();
}

void Channel::setKey(const std::string& key) {
    _key = key;
    _has_key = !key.empty();
}

void Channel::removeKey() {
    _key.clear();
    _has_key = false;
}

void Channel::setUserLimit(int limit) {
    _user_limit = limit;
    _has_user_limit = (limit > 0);
}

void Channel::removeUserLimit() {
    _user_limit = 0;
    _has_user_limit = false;
}

bool Channel::checkKey(const std::string& key) const {
    return !_has_key || _key == key;
}

bool Channel::canJoin(Client* client, const std::string& key) const {
    if (!client) return false;
    
    // Already a member
    if (hasMember(client)) return false;
    
    // Check invite-only mode
    if (_invite_only && !isInvited(client)) return false;
    
    // Check key
    if (!checkKey(key)) return false;
    
    // Check user limit
    if (_has_user_limit && getMemberCount() >= _user_limit) return false;
    
    return true;
}

void Channel::broadcastToMembers(const std::string& message, Client* sender) {
    for (std::set<Client*>::iterator it = _members.begin(); it != _members.end(); ++it) {
        if (*it != sender) {  // Don't send to sender unless sender is NULL
            (*it)->sendMessage(message);
        }
    }
}

void Channel::broadcastToMembersExcept(const std::string& message, Client* excluded) {
    for (std::set<Client*>::iterator it = _members.begin(); it != _members.end(); ++it) {
        if (*it != excluded) {
            (*it)->sendMessage(message);
        }
    }
}

std::string Channel::getModeString() const {
    std::string modes = "+";
    
    if (_invite_only) modes += "i";
    if (_topic_restricted) modes += "t";
    if (_has_key) modes += "k";
    if (_has_user_limit) modes += "l";
    
    // Add parameters for modes that need them
    std::string params = "";
    if (_has_key) params += " " + _key;
    if (_has_user_limit) {
        std::ostringstream oss;
        oss << " " << _user_limit;
        params += oss.str();
    }
    
    return modes + params;
}

std::string Channel::getMemberList() const {
    std::string list;
    for (std::set<Client*>::const_iterator it = _members.begin(); it != _members.end(); ++it) {
        if (!list.empty()) list += " ";
        
        // Add operator prefix if user is an operator
        if (isOperator(*it)) list += "@";
        
        list += (*it)->getNickname();
    }
    return list;
}

std::string Channel::getOperatorList() const {
    std::string list;
    for (std::set<Client*>::const_iterator it = _operators.begin(); it != _operators.end(); ++it) {
        if (!list.empty()) list += " ";
        list += (*it)->getNickname();
    }
    return list;
}

void Channel::removeFromAllSets(Client* client) {
    if (client) {
        _members.erase(client);
        _operators.erase(client);
        _invited.erase(client);
    }
}