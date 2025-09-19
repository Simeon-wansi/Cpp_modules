#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>

// Forward declaration - remove dependency on mockClient.hpp
class Client;

#define MAX_CHANNEL_COUNT 10

class Channel {
private:
    std::string _name;
    std::string _channelKey;
    std::string _topic;
    size_t _userLimit;
    std::vector<Client*> _clientList;
    std::map<std::string, bool> _operators;
    std::vector<Client*> _invitedList;
    bool _inviteOnly;
    bool _topicPrivilege;

public:
    // Constructors
    Channel(const std::string& name, const std::string& password = "");
	Channel(const std::string& name, Client* creator);
    ~Channel();

    // Getters
    std::string getName() const { return _name; }
    std::string getTopic() const { return _topic; }
    std::string getChannelKey() const { return _channelKey; }
    size_t getUserLimit() const { return _userLimit; }
    std::vector<Client*> getClients() const { return _clientList; }
    std::vector<std::string> getNickNames() const;
    bool getInviteOnly() const { return _inviteOnly; }
    bool getTopicPrivilege() const { return _topicPrivilege; }
    std::string getChannelMode() const;

    // Setters
    void setChannelKey(const std::string& key) { _channelKey = key; }
    void setName(const std::string& name) { _name = name; }
    void setTopic(const std::string& topic) { _topic = topic; }
    void setUserLimit(const size_t limit) { _userLimit = limit; }
    void setInviteOnly(bool inviteValue) { _inviteOnly = inviteValue; }
    void setTopicPrivilege(bool topicPriv) { _topicPrivilege = topicPriv; }
    void setInvited(Client* client);

    // Member functions
    void addClient(Client* client);
    void removeClient(Client* client);
    void addOperator(const Client* client);
    void removeOperator(const Client* client);
    void broadcast(const std::string& message);
    void broadcast(const std::string& message, const Client* excludeClient);
    bool isOperator(const Client* client) const;
    bool isInvited(const Client* client);
    bool isClientInChannel(const Client* client) const;
    Client* getClientWithNickname(const std::string& nickname);
};

#endif


// # ifndef CHANNEL_HPP
// # define CHANNEL_HPP

// # include <iostream>
// # include <vector>
// # include <map>

// // # include "Client.hpp"


// # define MAX_CHANNEL_COUNT   10


// class Client;

// class Channel
// {
// 	private:
// 		std::string             	_name;
// 		std::string					_channelKey;
// 		std::string					_topic;
// 		size_t						_userLimit;
// 		std::vector<Client *>		_clientList;
// 		std::map<std::string, bool>	_operators;
// 		std::vector<Client *>		_invitedList;
// 		bool						_inviteOnly;
// 		bool						_topicPrivilege;
// 		Channel();
// 		Channel(const Channel &other);
// 		Channel &operator= (const Channel &other);

// 	public:
// 		Channel(std::string name, std::string password);
// 		~Channel();

// 		//getters
// 		std::string					getName() const;
// 		std::string					getTopic() const;
// 		std::string					getChannelKey() const;
// 		size_t						getUserLimit() const;
// 		std::vector<Client *>		getClients() const;
// 		std::vector<std::string>	getNickNames() const;
// 		bool						getInviteOnly() const;
// 		bool						getTopicPrivilege() const;
// 		std::string					getChannelMode() const;

// 		//setters
// 		void						setChannelKey(const std::string &key);
// 		void						setName(const std::string &name);
// 		void						setTopic(const std::string &topic);
// 		void						setUserLimit(const size_t limit);
// 		void						setInviteOnly(bool inviteValue);
// 		void						setTopicPrivilege(bool topicPriv);
// 		void						setInvited(Client *client);
	
// 		//member functions
// 		void						addClient(Client *client);
// 		void						removeClient(Client *client);
// 		void						addOperator(const Client *client);
// 		void						removeOperator(const Client *client);
// 		void						broadcast(const std::string &message);
// 		void						broadcast(const std::string &message, const Client *excludeClient);
// 		bool						isOperator(const Client *client) const;
// 		bool						isInvited(const Client *client);
// 		bool						isClientInChannel(const Client *client) const;
// 		Client						*getClientWithNickname(const std::string &nickname);
// };

// # endif