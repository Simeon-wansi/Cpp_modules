#ifndef COMMANDDISPATCHER_HPP
#define COMMANDDISPATCHER_HPP

#include "irc.hpp"
#include <map>

class CommandDispatcher {

private:
    std::map<std::string, Command> _commands;

public:
    CommandDispatcher();
    void registerCommand(const std::string& name, CommandHandler handler, clientState requiredState);
    bool executeCommand(Server& server, Client& client, const std::string& commandLine);

private:
    std::vector<std::string> parseCommandLine(const std::string& Line);
};

#endif