#include "Server.hpp"
#include <iostream>
#include <cstdlib>

int main(int ac, char**av)
{
    if (ac != 3)
    {
        std::cerr << "Usage: " << av[0] << "<port> <password>" << std::endl;
        return 1;
    }

    try{
        int port = std::atoi( av[1]);
        if (port <= 0 || port > 65535)
        {
            std::cerr << "Error: Invalid port number" << std::endl;
            return 1;
        }

        Server server(port, av[2]);
        std::cout << "Starting IRC server on port " << port << std::endl;
        server.start(); // always running 
    }
    catch(const std::exception& e)
    {
        std::cerr << " Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}