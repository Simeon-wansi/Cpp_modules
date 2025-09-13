#include <iostream>    // For std::cout, std::cerr
#include <vector>      // For std::vector<int> clients
#include <algorithm>   // For std::find (used to remove clients)
#include <cstring>     // For memset
#include <cerrno>      // For errno values like EINTR
#include <unistd.h>    // For close(), read(), write()
#include <sys/types.h> // For socket types (sockaddr_in, etc.)
#include <sys/socket.h>// For socket(), bind(), listen(), accept()
#include <netinet/in.h>// For sockaddr_in, htons(), INADDR_ANY
#include <arpa/inet.h> // For inet_ntoa(), inet_pton() (not yet used, but useful)
#include <poll.h>      // For poll(), struct pollfd
#include <fcntl.h>     // For fcntl() if you later make sockets non-blocking



constexpr int PORT = 8080;
constexpr int MAX_CLIENTS = 10;

int main()
{
    // Create a TCP/IPv4 socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // Allow port reuse (avoids "Address already in use" after restart)
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        std::cerr << "Error setting socket options" << std::endl;
        return 1;
    }

    //  Define server address (IPv4, any network interface, port 8080)
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET; // ipv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all IPs(Localost + others)
    server_addr.sin_port = htons(PORT); // convert por to network bytes order


    //Bind socket to the chosen Ip/Port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {   
        std::cerr << "Bind error\n";
        return 1;
    }

    // Start Listening for incoming connections 
    if (listen(server_fd, SOMAXCONN) < 0)
    {
        std::cerr << "Listening error \n";
        return 1;
    }

    std::cout << "Server Listening on port" << PORT << '\n';

    //Poll structure: server socket + client sockets 
    struct pollfd fds[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        fds[i].fd = -1; // mark as unused
        fds[i].events = POLLIN; // We opnly care about readable events 
        fds[i].revents = 0; //cleared each look
    }
    fds[0].fd = server_fd; // slot 0 reserved for server socket
    fds[0].events = POLLIN;

    std::vector<int> clients; // Keep track of client file destriptors

    while(true)
    {
        // wait until some socket has activity (blocking)
        int nready = poll(fds, MAX_CLIENTS, -1);
        if (nready < 0)
        {
            if (errno == EINTR) continue; // Interupted by signal -> retry 
            std::cerr << "Error in poll\n";
            break;
        }
    //Check if a new client is trying to connect
        if (fds[0].revents & POLLIN)
        {
            int client_fd =  accept(server_fd, nullptr, nullptr);
            if (client_fd < 0)
                std::cerr << "Error accepting connection\n";
            else
            {
                std::cout << "New client connected : " << client_fd << '\n';
                bool placed =  false;
                // Put the client socket in the first free poll slot
                for (int i = 1; i < MAX_CLIENTS; i++)
                {
                    if (fds[i].fd == -1)
                    {
                        fds[i].fd = client_fd;
                        fds[i].events = POLLIN;
                        placed = true;
                        break;
                    }
                }
                if (!placed)
                {
                    //No free slot -> reject client
                    std::cerr  << "Max clients reached, closing connection\n";
                    close(client_fd);
                }
                else
                    clients.push_back(client_fd);
            }
            if (--nready == 0) continue; //No mroe events left
        }


        //Check activity form connected clients
        for (int i = 1; i < MAX_CLIENTS && nready > 0; ++i)
        {
            if (fds[i].fd == -1) continue; // Empty slot 
            if (fds[i].revents & POLLIN)
            {
            // A client has send sata (We dont reade yet in  Phase 1)
            std::cout << "Client " << fds[i].fd << " sent data\n";
            --nready;
            }
            if (fds[i].revents & (POLLHUP | POLLERR))
            {
                // Client  or error 
                int closed =  fds[i].fd;
                close(closed);
                fds[i].fd = -1; // Mark slot ad free
                auto it = std::find(clients.begin(), clients.end(), closed);
                if (it != clients.end())
                    clients.erase(it);
                std::cout << "Client " << closed << " disconnected\n";
            }
        }
    }

    //cleanubng when server exits
    close(server_fd);
    for (int fd: clients) close(fd);
    return 0;

}