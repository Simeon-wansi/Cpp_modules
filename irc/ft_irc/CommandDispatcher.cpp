#include "CommandDispatcher.hpp"
#include "Server.hpp"
#include "utils.hpp"

CommandDispatcher::CommandDispatcher() {
    // All commands with thier requiere authentications states 
    registerCommand("PASS", handlePass, CONNECTED);
    registerCommand("NICK", handleNick, CONNECTED);
    registerCommand("USER", handleUser, AUTHENTICATED);
    registerCommand("JOIN", handleJoin, REGISTERED);
    registerCommand("PART", handlePart, REGISTERED);
    registerCommand("PRIVMSG", handlePrivMsg, REGISTERED);
    registerCommand("KICK", handleKick, REGISTERED);
    registerCommand("INVITE", handleInvite, REGISTERED);
    registerCommand("TOPIC", handleTopic, REGISTERED);
    registerCommand("MODE", handleMode, REGISTERED);
    registerCommand("WHO", handleWho, REGISTERED);
    registerCommand("PING", handlePing, REGISTERED);
    registerCommand("PONG", handlePong, REGISTERED);
    registerCommand("QUIT", handleQuit, CONNECTED);

}

void CommandDispatcher::registerCommand(const std::string& name, CommandHandler handler, clientState requiredState)
{
    _commands.insert(std::make_pair(name, Command(name, handler, requiredState)));
}

bool CommandDispatcher::executeCommand(Server& server, Client& client, const std::string& commandLine)
{
    std::vector<std::string> tokens = parseCommandLine(commandLine);
    if (tokens.empty()) return false;

    std::string command = tokens[0];
    std::vector<std::string> params(tokens.begin() + 1, tokens.end());

    std::map<std::string, Command>::iterator it = _commands.find(command);
    if (it ==  _commands.end())
    {
        client.write(":" + server.getServerName() + " 421 " + client.getNickName() + " " + command + " :Unknown command\r\n");
        return false;
    }

    // Execute command
    it->second.handler(server, client, params);
    return true;
}

std::vector<std::string> CommandDispatcher::parseCommandLine(const std::string& line) {
    std::vector<std::string> tokens;
    std::string trimmed =  line;
    trim(trimmed);

    if (trimmed.empty()) return tokens;

    size_t pos = 0;
    while (pos < trimmed.length()) {
        // skip whithespace
        while( pos < trimmed.length() && std::isspace(trimmed[pos])) pos++;
        if (pos >= trimmed.length()) break;

        //handle trailing parameter (start with :)
        if (trimmed[pos] == ':'){
            tokens.push_back(trimmed.substr(pos + 1));
            break;
        }

        // extract regular token
        size_t start = pos;
        while (pos < trimmed.length() && !std::isspace(trimmed[pos])) pos++;
        tokens.push_back(trimmed.substr(start, pos - start));
    }

    return tokens;
}