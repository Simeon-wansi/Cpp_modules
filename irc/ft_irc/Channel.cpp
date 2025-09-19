#include "Channel.hpp"
#include "Client.hpp"  // Include our merged Client class

Channel::Channel(const std::string& name, const std::string& password) 
    : _name(name), _channelKey(password), _topic(""), _userLimit(0), 
      _inviteOnly(false), _topicPrivilege(false) {
    // Channel starts with default settings
}

Channel::Channel(const std::string& name, Client* creator) 
    : _name(name), _channelKey(""), _topic(""), _userLimit(0), 
      _inviteOnly(false), _topicPrivilege(false) {
    
    if (creator) {
        addClient(creator);
        addOperator(creator);
    }
}

Channel::~Channel() {
    // Remove this channel from all clients when destroyed
    for (std::vector<Client*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it) {
        (*it)->leaveChannel(this);
    }
}

std::vector<std::string> Channel::getNickNames() const {
    std::vector<std::string> nicknames;
    std::vector<Client*>::const_iterator it = _clientList.begin();
    while (it != _clientList.end()) {
        nicknames.push_back((isOperator(*it) ? "@" : "") + (*it)->getNickName());
        ++it;
    }
    return nicknames;
}

std::string Channel::getChannelMode() const {
    std::string modeStr = "";
    
    if (this->getTopicPrivilege())
        modeStr.append("t");
    if (this->getUserLimit() > 0)  
        modeStr.append("l");
    if (this->getInviteOnly())
        modeStr.append("i");
    if (!this->getChannelKey().empty())
        modeStr.append("k");
    
    return modeStr;
}

void Channel::setInvited(Client* client) {
    std::vector<Client*>::iterator it = _invitedList.begin();
    while (it != _invitedList.end()) {
        if (*it == client)
            return;  // Already invited
        ++it;
    }
    _invitedList.push_back(client);
}

void Channel::addClient(Client* client) {
    if (!client) return;
    
    _clientList.push_back(client);
    _operators[client->getNickName()] = false;  // Start as regular user
    client->incrementChannelCount();
    client->joinChannel(this);  // Bidirectional relationship
}

void Channel::removeClient(Client* client) {
    if (!client) return;
    
    std::vector<Client*>::iterator it = _clientList.begin();
    while (it != _clientList.end()) {
        if (*it == client) {
            _clientList.erase(it);
            break;
        }
        ++it;
    }
    
    // Remove from invited list too
    it = _invitedList.begin();
    while (it != _invitedList.end()) {
        if (*it == client) {
            _invitedList.erase(it);
            break;
        }
        ++it;
    }
    
    _operators.erase(client->getNickName());
    client->decrementChannelCount();
    client->leaveChannel(this);  // Bidirectional relationship
}

void Channel::addOperator(const Client* client) {
    if (client) {
        _operators[client->getNickName()] = true;
    }
}

void Channel::removeOperator(const Client* client) {
    if (client) {
        _operators[client->getNickName()] = false;
    }
}

void Channel::broadcast(const std::string& message) {
    std::vector<Client*>::iterator it = _clientList.begin();
    while (it != _clientList.end()) {
        (*it)->write(message);
        ++it;
    }
}

void Channel::broadcast(const std::string& message, const Client* excludeClient) {
    std::vector<Client*>::iterator it = _clientList.begin();
    while (it != _clientList.end()) {
        if (*it != excludeClient)
            (*it)->write(message);
        ++it;
    }
}

bool Channel::isOperator(const Client* client) const {
    if (!client) return false;
    
    std::map<std::string, bool>::const_iterator it = _operators.find(client->getNickName());
    if (it != _operators.end())
        return it->second;
    return false;    
}

bool Channel::isInvited(const Client* client) {
    if (!client) return false;
    
    std::vector<Client*>::iterator it = _invitedList.begin();
    while (it != _invitedList.end()) {
        if (*it == client)
            return true;
        ++it;
    }
    return false;
}

bool Channel::isClientInChannel(const Client* client) const {
    if (!client) return false;
    
    std::vector<Client*>::const_iterator it = _clientList.begin();
    while (it != _clientList.end()) {
        if (*it == client)
            return true;
        ++it;
    }
    return false;
}

Client* Channel::getClientWithNickname(const std::string& nickname) {
    std::vector<Client*>::const_iterator it = _clientList.begin();
    while (it != _clientList.end()) {
        if ((*it)->getNickName() == nickname)
            return *it;
        ++it;
    }
    return NULL; 
}

// # include "Channel.hpp"

// Channel::Channel() :_channelKey(""),_topic("") , _userLimit(0), _inviteOnly(false){}

// Channel::Channel(std::string name, std::string password) 
//     :_name(name), _channelKey(password), _topic("") , _userLimit(0), _inviteOnly(false),_topicPrivilege(false){}

// Channel::Channel(const Channel &other) 
// {
//     _name = other._name;
//     _topic = other._topic;
//     _channelKey = other._channelKey;
//     _inviteOnly = other._inviteOnly;
//     _userLimit = other._userLimit;
//     _topicPrivilege = other._topicPrivilege;
// }

// Channel & Channel::operator = (const Channel &other)
// {
//     if(this != &other)
//     {
//         _name = other._name;
//         _topic = other._topic;
//         _channelKey = other._channelKey;
//         _inviteOnly = other._inviteOnly;
//         _userLimit = other._userLimit;
//         _topicPrivilege = other._topicPrivilege;
//     }
//     return (*this);
// }

// Channel::~Channel() {}

// std::string Channel::getName() const
// {
//     return (_name);
// }

// std::string Channel::getTopic() const
// {
//     return(_topic);
// }

// std::string Channel::getChannelKey() const
// {
//     return(_channelKey);
// }

// size_t Channel::getUserLimit() const
// {
//     return(_userLimit);
// }

// std::vector<Client *> Channel::getClients() const
// {
//     return(_clientList);
// }

// std::vector<std::string> Channel::getNickNames() const
// {
//     std::vector<std::string> nicknames;
//     std::vector<Client *>::const_iterator it = _clientList.begin();
//     while(it != _clientList.end())
//     {
//        nicknames.push_back((isOperator(*it) ? "@" : "" ) + (*it)->getNickName());
//        ++it;
//     }
//     return (nicknames);
// }

// bool Channel::getInviteOnly() const
// {
//     return(_inviteOnly);
// }

// bool Channel::getTopicPrivilege() const
// {
//     return(_topicPrivilege);
// }

// std::string Channel::getChannelMode() const
// {
//   std::string modeStr = "";

//   if(this->getTopicPrivilege())
//     modeStr.append("t");
//   if(this->getUserLimit() > 0)  
//     modeStr.append("l");
//   if(this->getInviteOnly())
//     modeStr.append("i");
//   if(!this->getChannelKey().empty())
//     modeStr.append("k");

//   return (modeStr);
// }

// void Channel::setChannelKey(const std::string &key)
// {
//     _channelKey = key;
// }

// void Channel::setName(const std::string &name)
// {
//     _name = name;
// }

// void Channel::setTopic(const std::string &topic)
// {
//     _topic = topic;
// }

// void Channel::setUserLimit(const size_t limit)
// {
//     _userLimit = limit;
// }

// void Channel::setInviteOnly(bool inviteValue)
// {
//     _inviteOnly = inviteValue;
// }

// void Channel::setTopicPrivilege(bool topicPriv)
// {
//     _topicPrivilege = topicPriv;
// }
// void Channel::setInvited(Client *client)
// {
//     std::vector<Client *> :: iterator it = _invitedList.begin();
//      while (it != _invitedList.end())
//     {
//        if(*it == client)
//             return;
//        ++it;
//     }
//     _invitedList.push_back(client);
// }

// void Channel::addClient(Client *client)
// {
//     _clientList.push_back(client);
//     _operators[client->getNickName()] = false;
//     client->incrementChannelCount();
// }

// void Channel::removeClient(Client *client)
// {
//     std::vector<Client *>::iterator it = _clientList.begin();
//     while (it != _clientList.end())
//     {
//         if(*it == client)
//         {
//             _clientList.erase(it);
//             break;
//         }
//         ++it;
        
//     }
//     it = _invitedList.begin();
//     while (it != _invitedList.end())
//     {
//         if(*it == client)
//         {
//             _invitedList.erase(it);
//             break;
//         }
//         ++it;
//     }
//     _operators.erase(client->getNickName());
//     client->decrementChannelCount();
// }

// void Channel::addOperator(const Client *client)
// {
//     _operators[client->getNickName()] = true;
// }

// void Channel::removeOperator(const Client *client)
// {
//       _operators[client->getNickName()] = false;
// }

// void Channel::broadcast(const std::string &message)
// {
//     std::vector<Client *>::iterator it = _clientList.begin();
//     while (it != _clientList.end())
//     {
//         (*it)->write(message);
//         ++it;
//     }
// }

// void Channel::broadcast(const std::string &message,const Client *excludeClient)
// {
//     std::vector<Client *>::iterator it = _clientList.begin();
//     while (it != _clientList.end())
//     {
//         if(*it != excludeClient)
//             (*it)->write(message);
//         ++it;
//     }
// }

// bool Channel::isOperator(const Client *client) const
// {
//     std::map<std::string, bool> ::const_iterator it = _operators.find(client->getNickName());
//     if(it != _operators.end())
//         return (it->second);
//     return (false);    
// }

// bool Channel::isInvited(const Client *client)
// {
//     std::vector<Client *> :: iterator it = _invitedList.begin();
//      while (it != _invitedList.end())
//     {
//         if(*it == client)
//             return (true);
//         ++it;
//     }
//     return (false);
// }

// bool Channel::isClientInChannel(const Client *client) const
// {
//     std::vector<Client *>::const_iterator it = _clientList.begin();
//     while (it != _clientList.end())
//     {
//         if(*it == client)
//             return (true);
//         ++it;
//     }
//     return (false);
// }

// Client * Channel::getClientWithNickname(const std::string &nickname)
// {
//     std::vector<Client *>::const_iterator it = _clientList.begin();
//     while (it != _clientList.end())
//     {
//         if((*it)->getNickName() == nickname)
//             return (*it);
//         ++it;
//     }
//     return (NULL); 
// }
