
# include "irc.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "utils.hpp"


bool isNickNameInUse(Server &server, const std::string& nickName) {
	const std::vector<Client*>& clients = server.getClients();
	for (std::vector<Client*>::const_iterator it = clients.begin(); it != clients.end(); ++it) {
		if ((*it)->getNickName() == nickName)
			return true;
	}
	return false;
}

bool isValidNickName(const std::string& nickName) {
	if (nickName.empty() || nickName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-") != std::string::npos || nickName.length() > 9) {
		return false;
	}
	return true;
}

void handleNick(Server &server, Client &client, std::vector<std::string>& params)
{
	if(params.empty() || params[0].empty())
	{
		if(client.getNickName().empty())
			client.write(ERR_NONICKNAMEGIVEN);
		else
			client.write("431" + client.getNickName() + ":No nickname given\r\n");	
		return;
	}
	if (!isValidNickName(params[0]))
		client.write(":" + server.getServerName() + " 432 " + params[0] + " " + params[0] + " :Erroneous nickname\r\n");
	else if (isNickNameInUse(server, params[0]))
		client.write(":" + server.getServerName() + " 433 " + params[0] + " " + params[0] + " :Nickname is already in use\r\n");
	else {
			if (client.getNickName().empty())
			{
				client.setNickName(params[0]);
				if (!client.getUserName().empty())
				{
					client.setState(REGISTERED);
					client.write(":" + server.getServerName() +" 001 " + client.getNickName() + " :Welcome to the " + server.getServerName() + " Network, " +client.getNickName() + "\r\n");	
					std::cout << ":" + server.getServerName() +" 001 " + client.getNickName() + " :Welcome to the " + server.getServerName() + " Network, " +client.getNickName() + "\r\n";
				}
			}
			else
			{
				std::string oldNick = client.getNickName();
				client.setNickName(params[0]);
				std::string newNick = client.getNickName();

				std::string nickChangeMsg = ":" + oldNick + "!" + client.getUserName() + "@" + server.getServerName() + " NICK :" + newNick + "\r\n";
			// 	std::vector<Channel *> channels = server.getChannelsByClient(&client);
			// 	for (size_t i = 0; i < channels.size(); ++i) {
			// 		channels[i]->broadcast(nickChangeMsg);
			// }
            const std::set<Channel*>& channels = client.getChannels(); // Get directly from client
            for (std::set<Channel*>::const_iterator it = channels.begin(); it != channels.end(); ++it) {
                (*it)->broadcast(nickChangeMsg);
            }
		}
	}
}

void handleJoin(Server &server, Client &client, std::vector<std::string>  &params)
{
	if(params.empty()){
		client.write(":"+ server.getServerName()+ " 461 " + client.getNickName() + " JOIN :Not enough parameters\r\n");
		return;
	}
	std::vector<std::string> channels = split(params[0], ',');
	std::vector<std::string> keys;
	if(params.size() == 2)
		keys = split(params[1],',');
	for(size_t i = 0; i < channels.size(); i++)
	{
		std::string name = channels[i];
		std::string channelKey = keys.size() > i ? keys[i] : "" ;

		if(client.getChannelCount() >= MAX_CHANNEL_COUNT){
			client.write(":"+server.getServerName()+" 405 "+ client.getNickName() + " " + name +  " :You have joined too many channels!\r\n");
			return;
		}
		if(name[0] !='#' && name[0] != '&'){
			client.write(":"+server.getServerName()+" 403 "+ client.getNickName() + " " + name +  " :No such channel!\r\n");
			return;
		}
		Channel *channel = server.getChannel(name);
		if(!channel)
		{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
			channel = new Channel(name, channelKey);
			server.registerChannel(channel);
			channel->addClient(&client);
			channel->addOperator(&client);
			std::string users;
			std::vector<std::string> nicknames = channel->getNickNames();
			for(std::vector<std::string> :: iterator it = nicknames.begin();it != nicknames.end(); ++it)
				users.append(*it + " ");
			client.write(":" + client.getPrefix() + "@" + server.getServerName() + " JOIN " + name + "\r\n");
			channel->setTopicPrivilege(true);
			client.write(":"+ client.getNickName()+ " MODE " + channel->getName() + " +t\r\n");     
			client.write(":"+ server.getServerName() + " 353 " + client.getNickName()+ " = " + channel->getName() + " :" + users + "\r\n");
			client.write(":"+ server.getServerName() + " 366 " + client.getNickName()+ " " + channel->getName() + " :End of /NAMES list.\r\n");
			std::cout << ":" << client.getPrefix() + "@" + server.getServerName() + " JOIN " + name << "\r\n";
			channel->broadcast(":" + client.getPrefix() + "@" + server.getServerName() + " JOIN " + name + "\r\n", &client);
			continue;
		}  

		if(channel->isClientInChannel(&client)){
			client.write(": 443 " + server.getServerName() + " " + client.getNickName() + " " + name + "  :is already on channel.\r\n");
			return;
		}
		if(channel->getUserLimit() > 0 && channel->getClients().size() > channel->getUserLimit()){
			client.write(":"+ server.getServerName() + " 471 " + name + " :Cannot join channel (+l) \r\n");
			return;
		}  
		if(!channel->getChannelKey().empty()){
			if(channelKey.empty() || channel->getChannelKey() != channelKey)
			{
				client.write(":"+ server.getServerName() + " 475 " + name + " :Cannot join channel (+k) - bad key\r\n");
				return;
			}  
		}
		if(channel->getInviteOnly() && !channel->isInvited(&client)){
			client.write(":"+ server.getServerName() + " 473 " + name + " :Cannot join channel (+i) - you must be invited\r\n");
			return;
		}
		channel->addClient(&client);
		std::string users;
		std::vector<std::string> nicknames = channel->getNickNames();
		for(std::vector<std::string> :: iterator it = nicknames.begin();it != nicknames.end(); ++it)
			users.append(*it + " ");
		client.write(":" + client.getPrefix() + "@" + client.getIpAddress() + " JOIN " + name + "\r\n");
		if(channel->getTopic().empty())
			client.write(":" + server.getServerName() + " 331 " + client.getNickName() + " " + channel->getName() + " :No topic is set\r\n");  
		else
			client.write(":" + server.getServerName() + " 332 " + client.getNickName() + " " + channel->getName() + " :" + channel->getTopic() + "\r\n");
		client.write(":"+ server.getServerName() + " 353 " + client.getNickName()+ " = " + channel->getName() + " :" + users + "\r\n");
		client.write(":"+ server.getServerName() + " 366 " + client.getNickName()+ " " + channel->getName() + " :End of /NAMES list.\r\n");
		std::cout << ":" << client.getPrefix() + "@" + server.getServerName() + " JOIN " + name << "\r\n";
		channel->broadcast(":" + client.getPrefix() + "@" + server.getServerName() + " JOIN " + name + "\r\n", &client);
   }
}


void handleMode(Server &server, Client &client, std::vector<std::string> &params)
{
	
	if(params.empty())
	{
		client.write(":"+ server.getServerName()+ " 461 " + client.getNickName() + " MODE :Not enough parameters\r\n");
		return;
	}
	std::string target = params[0];
	Channel *channel = server.getChannel(target);
	if (!channel){
		client.write(":"+server.getServerName()+" 403 "+ client.getNickName() + " " + target +  " :No such channel!\r\n");
		return;
	}
	if (params.size() < 2){
		client.write(":" + server.getServerName() + " 324 " + client.getNickName() + " " + target + " :+" + channel->getChannelMode() + "\r\n");
		return;
	}
	if(!channel->isOperator(&client)){
		client.write(":" + server.getServerName() + " 482 " + client.getNickName() + " " + target + " :You're not channel operator\r\n");
		return;
	}
	std::vector <std::string> reqArgs;
	for (size_t i = 2; i < params.size(); i++)
		reqArgs.push_back(params[i]);
	bool isAdded = true;
	std::string channelModes = "";
	Client *targetClient;
	for (size_t i = 0; i < params[1].size(); i++)
	{
	   switch (params[1][i])
	   {
		case '+':  
					isAdded = true;
					break;
		case '-':
					isAdded = false;
					break;
		case 'i': 
					if(isAdded && channel->getInviteOnly() == false)
					{
						channel->setInviteOnly(true);
						channelModes.append("+i ");
					}
					else if (!isAdded)
					{
						channel->setInviteOnly(false);
						channelModes.append("-i ");
					}
					break;
		case 't':
					if(isAdded)
					{
						channel->setTopicPrivilege(true);
						channelModes.append(" +t ");
					}
					else if (!isAdded)
					{
						channel->setTopicPrivilege(false);
						channelModes.append(" -t ");
					}
					break;
		case 'l':
					if(reqArgs.empty() && isAdded)
					{
						client.write(":"+ server.getServerName()+ " 461 " + client.getNickName() + " MODE :Not enough parameters\r\n");
						return;
					}
					if(isAdded && channel->getUserLimit() == 0)
					{
						size_t limit;
						limit = stringToNumber(reqArgs[0]);
						if(limit >= INT_MAX ||( limit == 0 && reqArgs[0] != "0"))
						{
							client.write(":" + server.getServerName() + " 501 " + client.getNickName() + " " + target + " :Unknown MODE flag\r\n");
							return;
						}
						try
						{
							channel->setUserLimit(limit);
						}
						catch(const std::exception& e)
						{
							std::cerr << e.what() << '\n';
							client.write(":"+ server.getServerName()+ " 461 " + client.getNickName() + " MODE :Not enough parameters\r\n");
							return;
						}
						channelModes.append("+l " + reqArgs[0]);
					}
					else if(!isAdded)
					{
						channelModes.append("-l * ");
						channel->setUserLimit(0);
					}
					if(reqArgs.size() > 0)
						reqArgs.erase(reqArgs.begin());
					break;
		case 'k':
					if(reqArgs.empty() && isAdded)
					{
						client.write(":"+ server.getServerName()+ " 461 " + client.getNickName() + " MODE :Not enough parameters\r\n");
						return;
					}
					if(isAdded && channel->getChannelKey().empty())
					{
						channel->setChannelKey(reqArgs[0]);
						channelModes.append("+k " + reqArgs[0]);
					}
					else if (!isAdded && reqArgs.size() > 0 && channel->getChannelKey() == reqArgs[0])
					{
						channel->setChannelKey("");  
						channelModes.append("-k " + reqArgs[0]);
					}
					reqArgs.erase(reqArgs.begin());
					break;
		case 'o':
				{
					if(reqArgs.empty())
					{
						client.write(":"+ server.getServerName()+ " 461 " + client.getNickName() + " MODE :Not enough parameters\r\n");
						return;
					}
					targetClient = channel->getClientWithNickname(reqArgs[0]);
					if(!targetClient)
					{
						client.write(":" + server.getServerName() + " 441 " + client.getNickName() + " " + target + " :They aren't on that channel\r\n");
						return;
					}
					if(isAdded && !channel->isOperator(targetClient))
					{
						channel->addOperator(targetClient);
						channelModes.append(" +o " + reqArgs[0]);
					}
					else
					{
						channel->removeOperator(targetClient);
						channelModes.append(" -o " + reqArgs[0]);
					}
					reqArgs.erase(reqArgs.begin());   
					break;
				}
		default:
				return;
		}
	}
	if(!channelModes.empty())
		channel->broadcast(":" + client.getPrefix() + " MODE " + target + " " + channelModes + " \r\n");
}


void handleTopic(Server &server, Client &client, std::vector<std::string> &params)
{
    if(params.empty())
    {
        client.write(":"+ server.getServerName()+ " 461 " + client.getNickName() + " TOPIC :Not enough parameters\r\n");
        return;
    }
    
    std::string name = params[0];
    Channel *channel = server.getChannel(name);

    if(!channel){
            client.write(":"+server.getServerName()+" 403 "+ client.getNickName() + " " + name +  " :No such channel!\r\n");
            return;
    }
    else if (!channel->isClientInChannel(&client)) {
        client.write(":" + server.getServerName() + " 442 " + client.getNickName() + " " + channel->getName() + " :You're not on that channel\r\n");
        return;
    }

    if(params.size() == 1)
    {
        if(channel->getTopic().empty())
            client.write(":" + server.getServerName() + " 331 " + client.getNickName() + " " + channel->getName() + " :No topic is set\r\n");  
        else
            client.write(":" + server.getServerName() + " 332 " + client.getNickName() + " " + channel->getName() + " :" + channel->getTopic() + "\r\n");
        return;    
    }   
    
    if(channel->getTopicPrivilege() && !channel->isOperator(&client)){
        client.write(":" + server.getServerName() + " 482 " + client.getNickName() + " " + channel->getName() + " :You're not channel operator\r\n");
        return;
    }

    //setting new topic
    std::string newTopic = "";
    if(params.size() >= 2)
    {
        newTopic = params[1];
        if(newTopic[0] == ':')
            newTopic.erase(0,1);

        for(size_t i = 2; i < params.size(); ++i)
                newTopic += " " + params[i];    
    }

    channel->setTopic(newTopic);
    channel->broadcast(":" + client.getPrefix() + " " + " TOPIC " + channel->getName() + " :" + newTopic + "\r\n");

}


void handlePass(Server &server, Client &client, std::vector<std::string>& params)
 {
	if(params.empty())
	{
		client.write(server.getServerName() + ERR_NEEDMOREPARAMS);
		return;
	}
	if(client.getState() == AUTHENTICATED || client.getState() == REGISTERED)
	{
		client.write(server.getServerName() + ERR_ALREADYREGISTERED);
		return;
	}
	if(params[0] != server.getPassword())
	{
		client.write(server.getServerName() + ERR_PASSWDMISMATCH);
		return;
	}
	client.setState(AUTHENTICATED);
}

void handleUser(Server &server, Client &client, std::vector<std::string>& params) 
{
	if(client.getState() == REGISTERED)
	{
		client.write(server.getServerName() + ERR_ALREADYREGISTERED);
		return;
	}
	if(params.empty() || params.size() < 4)
	{
		client.write(server.getServerName() + ERR_NEEDMOREPARAMS);
		return;
	}

	client.setUserName(params[0]);
	client.setRealName(params[3]);
	if(!client.getNickName().empty())
	{
		client.setState(REGISTERED);
		client.write(":" + server.getServerName() +" 001 " + client.getNickName() + " :Welcome to the " + server.getServerName() + " Network, " +client.getNickName() + "\r\n");	
		std::cout << ":" + server.getServerName() +" 001 " + client.getNickName() + " :Welcome to the " + server.getServerName() + " Network, " +client.getNickName() + "\r\n";
	}	
}


void handlePart(Server &server, Client &client, std::vector<std::string>& params) {
	if (params.empty()) {
        client.write(":" + server.getServerName() + " 461 " + client.getNickName() + " PART :Not enough parameters\r\n");
        return;
    }

    std::vector<std::string> channelNames = split(params[0], ',');
    std::string reason = params.size() > 1 ? "" : "Leaving";

    if(reason.empty())
		for(std::vector<std::string> ::iterator it = params.begin(); it != params.end(); ++it)		
			reason.append(*it + " ");
    for (size_t i = 0; i < channelNames.size(); i++) {
        std::string channelName = channelNames[i];
        Channel *channel = server.getChannel(channelName);

        if (!channel) {
            client.write(":" + server.getServerName() + " 403 " + client.getNickName() + " " + channelName + " :No such channel\r\n");
            continue;
        }

        if (!channel->isClientInChannel(&client)) {
            client.write(":" + server.getServerName() + " 442 " + client.getNickName() + " " + channelName + " :You're not on that channel\r\n");
            continue;
        }

        bool wasOperator = channel->isOperator(&client);
        if (wasOperator) {
            channel->removeOperator(&client);
        }
        channel->broadcast(":" + client.getPrefix() + " PART " + channelName + " :" + reason + "\r\n");
        channel->removeClient(&client);
        
        if (channel->getClients().empty()) {
            server.removeChannel(channelName);
            delete channel;
        }
    }
}

void handleInvite(Server &server, Client &client, std::vector<std::string>& params) {
	if (params.size() < 2) {
        client.write(":" + server.getServerName() + " 461 " + client.getNickName() + " INVITE :Not enough parameters\r\n");
        return;
    }

    std::string targetNick = params[0];
    std::string channelName = params[1];
    Client *targetClient = NULL;
    std::vector<Client*> clients = server.getClients();
    for (std::vector<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
        if ((*it)->getNickName() == targetNick) {
            targetClient = *it;
            break;
        }
    }

    if (!targetClient) {
        client.write(":" + server.getServerName() + " 401 " + client.getNickName() + " " + targetNick + " :No such nick\r\n");
        return;
    }

    Channel *channel = server.getChannel(channelName);
    if (!channel) {
        client.write(":" + server.getServerName() + " 403 " + client.getNickName() + " " + channelName + " :No such channel\r\n");
        return;
    }

    if (!channel->isClientInChannel(&client)) {
        client.write(":" + server.getServerName() + " 442 " + client.getNickName() + " " + channelName + " :You're not on that channel\r\n");
        return;
    }

    if (channel->isClientInChannel(targetClient)) {
        client.write(":" + server.getServerName() + " 443 " + client.getNickName() + " " + targetNick + " " + channelName + " :is already on channel\r\n");
        return;
    }

    if (!channel->isOperator(&client)) {
        client.write(":" + server.getServerName() + " 482 " + client.getNickName() + " " + channelName + " :You're not channel operator\r\n");
        return;
    }
    targetClient->write(":" + client.getPrefix() + " INVITE " + targetNick + " " + channelName + "\r\n");
    client.write(":" + server.getServerName() + " 341 " + client.getNickName() + " " + targetNick + " " + channelName + "\r\n");
    channel->setInvited(targetClient);
}

void handlePing(Server &server, Client &client, std::vector<std::string>& params) {
	std::string msg;
    if (params.empty()) {
        msg = ":" + server.getServerName() + " 409 " + client.getNickName() + " :No origin specified\r\n";
        client.write(msg);
        return;
    }
    
    std::string token = params[0];
    msg = ":" + server.getServerName() + " PONG " + server.getServerName() + " :" + token + "\r\n";
    client.write(msg);
}


void handlePong(Server &server, Client &client, std::vector<std::string>& params) {    
    if (params.empty()) {
        std::string msg= ":" + server.getServerName() + " 409 " + client.getNickName() + " :No origin specified\r\n";
        client.write(msg);
        return;
    }
    // client.updateLastActivity();
}

void handleQuit(Server &server, Client &client, std::vector<std::string>& params) {
	
	
	std::string reason = params.size() > 1 ? ""  : "Leaving...";
	
	if(reason.empty())
		for(std::vector<std::string> ::iterator it = params.begin(); it != params.end(); ++it)		
			reason.append(*it + " ");
	
    if(client.getState() == REGISTERED)
        server.removeClient(client.getSocketFd(), reason);
    else
    {
        if(client.getNickName().empty())
            client.write(":"+ server.getServerName() + " * QUIT :" + reason + "\r\n");
        else
            client.write(":"+ server.getServerName() + " " + client.getNickName() +" QUIT :" + reason + "\r\n");
        std::cout << ": "+ server.getServerName() + " " + client.getNickName() +" QUIT :" + reason + "\r\n";
    }
}

void handleWho(Server &server, Client &client, std::vector<std::string>& params) {
	if (params.empty()) {
        client.write(":" + server.getServerName() + " 461 " + client.getNickName() + " WHO :Not enough parameters\r\n");
        return;
    }

    std::string target = params[0];
    bool operFlag = (params.size() > 1 && params[1] == "o");

    if (target[0] == '#' || target[0] == '&') {
        Channel *channel = server.getChannel(target);
        if (channel) {
            std::vector<Client*> clients = channel->getClients();
            for (std::vector<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
                Client *member = *it;
                if (operFlag && !channel->isOperator(member))
                    continue;
                std::string flags = "H";
                if (channel->isOperator(member))
                    flags += "@";
                client.write(":" + server.getServerName() + " 352 " + client.getNickName() + " " + 
                             channel->getName() + " " + member->getUserName() + " " + 
                             member->getIpAddress() + " " + server.getServerName() + " " + 
                             member->getNickName() + " " + flags + " :0 " + 
                             member->getRealName() + "\r\n");
            }
        }
    } else {
        std::vector<Client*> clients = server.getClients();
        for (std::vector<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
            Client *cli = *it;
            if (cli->getNickName() == target || target == "*") {
                if (operFlag) {
                    bool isOp = false;
                    const std::map<std::string, Channel*>& channels = server.getChannels();
                    for (std::map<std::string, Channel*>::const_iterator ch = channels.begin(); ch != channels.end(); ++ch) {
                        if (ch->second->isOperator(cli)) {
                            isOp = true;
                            break;
                        }
                    }
                    if (!isOp) continue;
                }
                std::string channelName = "*";
                std::string flags = "H";
                const std::map<std::string, Channel*>& channels = server.getChannels();
                for (std::map<std::string, Channel*>::const_iterator ch = channels.begin(); ch != channels.end(); ++ch) {
                    if (ch->second->isClientInChannel(cli)) {
                        channelName = ch->second->getName();
                        if (ch->second->isOperator(cli))
                            flags += "@";
                        break;
                    }
                }
                client.write(":" + server.getServerName() + " 352 " + client.getNickName() + " " + 
                             channelName + " " + cli->getUserName() + " " + 
                             cli->getIpAddress() + " " + server.getServerName() + " " + 
                             cli->getNickName() + " " + flags + " :0 " + 
                             cli->getRealName() + "\r\n");
            }
        }
    }
    client.write(":" + server.getServerName() + " 315 " + client.getNickName() + " " + target + " :End of WHO list\r\n");
}

void handleKick(Server &server, Client &client, std::vector<std::string>& params) {
	if (params.size() < 2) {
        client.write(":" + server.getServerName() + " 461 " + client.getNickName() + " KICK :Not enough parameters\r\n");
        return;
    }

    std::string channelName = params[0];
    std::string targetNick = params[1];
    std::string reason = "Kicked";
    if (params.size() > 2) {
        reason = params[2];
        if (reason[0] == ':')
            reason = reason.substr(1);
        for (size_t i = 3; i < params.size(); i++) {
            reason += " " + params[i];
        }
    }
    Channel *channel = server.getChannel(channelName);
    if (!channel) {
        client.write(":" + server.getServerName() + " 403 " + client.getNickName() + " " + channelName + " :No such channel\r\n");
        return;
    }
    if (!channel->isClientInChannel(&client)) {
        client.write(":" + server.getServerName() + " 442 " + client.getNickName() + " " + channelName + " :You're not on that channel\r\n");
        return;
    }
    if (!channel->isOperator(&client)) {
        client.write(":" + server.getServerName() + " 482 " + client.getNickName() + " " + channelName + " :You're not channel operator\r\n");
        return;
    }
    Client *targetClient = NULL;
    std::vector<Client*> clients = server.getClients();
    for (std::vector<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
        if ((*it)->getNickName() == targetNick) {
            targetClient = *it;
            break;
        }
    }
    if (!targetClient) {
        client.write(":" + server.getServerName() + " 401 " + client.getNickName() + " " + targetNick + " :No such nick\r\n");
        return;
    }
    if (!channel->isClientInChannel(targetClient)) {
        client.write(":" + server.getServerName() + " 441 " + client.getNickName() + " " + targetNick + " " + channelName + " :They aren't on that channel\r\n");
        return;
    }
    std::string kickMsg = ":" + client.getPrefix() + " KICK " + channelName + " " + targetNick + " :" + reason + "\r\n";
    channel->broadcast(kickMsg);
    channel->removeClient(targetClient);
}

void handlePrivMsg(Server &server, Client &client, std::vector<std::string>& params) {
	if (params.size() < 2) {
        client.write(":" + server.getServerName() + " 461 " + client.getNickName() + " PRIVMSG :Not enough parameters\r\n");
        return;
    }

    std::string target = params[0];
    std::string message = params[1];
    if (message[0] == ':')
        message = message.substr(1);
    for (size_t i = 2; i < params.size(); i++)
        message += " " + params[i];
    if (target[0] == '#' || target[0] == '&') {
        Channel *channel = server.getChannel(target);
        if (!channel) {
            client.write(":" + server.getServerName() + " 403 " + client.getNickName() + " " + target + " :No such channel\r\n");
            return;
        }

        if (!channel->isClientInChannel(&client)) {
            client.write(":" + server.getServerName() + " 404 " + client.getNickName() + " " + target + " :Cannot send to channel\r\n");
            return;
        }
        channel->broadcast(":" + client.getPrefix() + " PRIVMSG " + target + " :" + message + "\r\n", &client);
    } else {
        Client *targetClient = NULL;
        std::vector<Client*> clients = server.getClients();
        for (std::vector<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
            if ((*it)->getNickName() == target) {
                targetClient = *it;
                break;
            }
        }
        if (!targetClient) {
            client.write(":" + server.getServerName() + " 401 " + client.getNickName() + " " + target + " :No such nick\r\n");
            return;
        }
        targetClient->write(":" + client.getPrefix() + " PRIVMSG " + target + " :" + message + "\r\n");
    }
}
