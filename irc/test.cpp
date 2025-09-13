// chat_server_phase1.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <fcntl.h>

constexpr int PORT = 8080;         // Server will listen on port 8080
constexpr int MAX_CLIENTS = 10;    // Max slots in poll array (1 server + 9 clients)

int main() {
    // Create a TCP/IPv4 socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); return 1; }

    // Allow port reuse (avoids "Address already in use" after restart)
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt"); close(server_fd); return 1;
    }

    // Define server address (IPv4, any network interface, port 8080)
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;        // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // listen on all IPs (localhost + others)
    address.sin_port = htons(PORT);       // convert port to network byte order

    // Bind socket to the chosen IP/port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind"); close(server_fd); return 1;
    }

    // Start listening for incoming connections
    if (listen(server_fd, SOMAXCONN) < 0) {
        perror("listen"); close(server_fd); return 1;
    }

    std::cout << "Server listening on port " << PORT << '\n';

    // Poll structure: server socket + client sockets
    struct pollfd fds[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        fds[i].fd = -1;         // mark as unused
        fds[i].events = POLLIN; // we only care about "readable" events
        fds[i].revents = 0;     // cleared each loop
    }
    fds[0].fd = server_fd;      // slot 0 reserved for server socket
    fds[0].events = POLLIN;

    std::vector<int> clients;   // keep track of client file descriptors

    while (true) {
        // Wait until some socket has activity (blocking)
        int nready = poll(fds, MAX_CLIENTS, -1);
        if (nready < 0) {
            if (errno == EINTR) continue; // interrupted by signal → retry
            perror("poll");
            break;
        }

        // --- Check if new client is trying to connect ---
        if (fds[0].revents & POLLIN) {
            int client_fd = accept(server_fd, nullptr, nullptr);
            if (client_fd < 0) {
                perror("accept");
            } else {
                std::cout << "New client connected: " << client_fd << '\n';
                bool placed = false;
                // Put the client socket in the first free poll slot
                for (int i = 1; i < MAX_CLIENTS; ++i) {
                    if (fds[i].fd == -1) {
                        fds[i].fd = client_fd;
                        fds[i].events = POLLIN;
                        placed = true;
                        break;
                    }
                }
                if (!placed) {
                    // No free slot → reject client
                    std::cerr << "Max clients reached, closing connection\n";
                    close(client_fd);
                } else {
                    clients.push_back(client_fd);
                }
            }
            if (--nready <= 0) continue; // no more events left
        }

        // --- Check activity from connected clients ---
        for (int i = 1; i < MAX_CLIENTS && nready > 0; ++i) {
            if (fds[i].fd == -1) continue; // empty slot
            if (fds[i].revents & POLLIN) {
                // A client has sent data (we don't read it yet in Phase 1)
                std::cout << "Client " << fds[i].fd << " sent data\n";
                --nready;
            }
            if (fds[i].revents & (POLLHUP | POLLERR)) {
                // Client disconnected or error
                int closed = fds[i].fd;
                close(closed);
                fds[i].fd = -1; // mark slot as free
                auto it = std::find(clients.begin(), clients.end(), closed);
                if (it != clients.end()) clients.erase(it);
                std::cout << "Client " << closed << " disconnected\n";
            }
        }
    }

    // Cleanup when server exits
    close(server_fd);
    for (int fd : clients) close(fd);
    return 0;
}
