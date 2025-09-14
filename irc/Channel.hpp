#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <set>
#include <vector>

// Forward declaration
class Client;

class Channel {
private:
    // Basic channel info
    std::string _name;
    std::string _topic;
    std::string _key;  // Channel password
    
    // Members and operators
    std::set<Client*> _members;
    std::set<Client*> _operators;
    std::set<Client*> _invited;  // Invited users (for +i mode)
    
    // Channel modes
    bool _invite_only;      // +i mode
    bool _topic_restricted; // +t mode (only ops can change topic)
    bool _has_key;         // +k mode (channel has password)
    bool _has_user_limit;  // +l mode
    int _user_limit;       // Maximum users allowed
    
public:
    // Constructor & Destructor
    Channel(const std::string& name, Client* creator);
    ~Channel();
    
    // Basic info
    const std::string& getName() const { return _name; }
    const std::string& getTopic() const { return _topic; }
    void setTopic(const std::string& topic) { _topic = topic; }
    
    // Member management
    void addMember(Client* client);
    void removeMember(Client* client);
    bool hasMember(Client* client) const;
    const std::set<Client*>& getMembers() const { return _members; }
    int getMemberCount() const { return _members.size(); }
    
    // Operator management
    void addOperator(Client* client);
    void removeOperator(Client* client);
    bool isOperator(Client* client) const;
    const std::set<Client*>& getOperators() const { return _operators; }
    
    // Invitation system (for +i mode)
    void inviteUser(Client* client);
    void removeInvitation(Client* client);
    bool isInvited(Client* client) const;
    
    // Channel modes
    bool isInviteOnly() const { return _invite_only; }
    bool isTopicRestricted() const { return _topic_restricted; }
    bool hasKey() const { return _has_key; }
    bool hasUserLimit() const { return _has_user_limit; }
    int getUserLimit() const { return _user_limit; }
    
    void setInviteOnly(bool enable) { _invite_only = enable; }
    void setTopicRestricted(bool enable) { _topic_restricted = enable; }
    void setKey(const std::string& key);
    void removeKey();
    void setUserLimit(int limit);
    void removeUserLimit();
    
    // Key validation
    bool checkKey(const std::string& key) const;
    
    // Utility functions
    void broadcastToMembers(const std::string& message, Client* sender = NULL);
    void broadcastToMembersExcept(const std::string& message, Client* excluded);
    bool canJoin(Client* client, const std::string& key = "") const;
    bool isEmpty() const { return _members.empty(); }
    
    // Channel info formatting
    std::string getModeString() const;
    std::string getMemberList() const;
    std::string getOperatorList() const;
    
private:
    void removeFromAllSets(Client* client);  // Helper for cleanup
};

#endif // CHANNEL_HPP