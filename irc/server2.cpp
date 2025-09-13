#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <cstring>

const int PORT = 8080;
const int MAX_CLIENTS = 5;  // Keep it small for testing

int main() {
    // STEP 1: Create server socket (same as before)
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    // Allow port reuse (prevents "Address already in use" errors)
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // STEP 2: Bind and listen (same as before)
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return 1;
    }

    if (listen(server_fd, 5) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return 1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    // STEP 3: Set up poll array
    // fds[0] = server socket (for new connections)
    // fds[1-4] = client sockets (for client messages)
    struct pollfd fds[MAX_CLIENTS];
    
    // Initialize all slots as empty
    for (int i = 0; i < MAX_CLIENTS; i++) {
        fds[i].fd = -1;        // -1 means "not used"
        fds[i].events = POLLIN; // We want to know about incoming data
    }
    
    // Slot 0 is always the server socket
    fds[0].fd = server_fd;

    std::cout << "Waiting for connections..." << std::endl;

    // STEP 4: Main event loop
    while (true) {
        // Wait for activity on any socket
        int activity = poll(fds, MAX_CLIENTS, -1);
        if (activity < 0) {
            std::cerr << "Poll error" << std::endl;
            break;
        }

        // Check if server socket has activity (new connection)
        if (fds[0].revents & POLLIN) {
            int client_fd = accept(server_fd, NULL, NULL);
            if (client_fd >= 0) {
                std::cout << "New client connected: fd " << client_fd << std::endl;
                
                // Find first empty slot for this client
                bool placed = false;
                for (int i = 1; i < MAX_CLIENTS; i++) {
                    if (fds[i].fd == -1) {  // Empty slot found
                        fds[i].fd = client_fd;
                        placed = true;
                        std::cout << "  -> Placed in slot " << i << std::endl;
                        break;
                    }
                }
                
                if (!placed) {
                    std::cout << "  -> Server full, rejecting client" << std::endl;
                    close(client_fd);
                }
            }
        }

        // Check all client slots for activity
        for (int i = 1; i < MAX_CLIENTS; i++) {
            if (fds[i].fd == -1) continue;  // Empty slot, skip
            
            if (fds[i].revents & POLLIN) {
                // This client sent data - we MUST read it to clear the buffer
                char buffer[1024];
                int bytes = recv(fds[i].fd, buffer, sizeof(buffer) - 1, 0);
                if (bytes > 0) {
                    buffer[bytes] = '\0';
                    std::cout << "Client " << fds[i].fd << " sent: " << buffer << std::endl;
                } else if (bytes == 0) {
                    // Client disconnected gracefully
                    std::cout << "Client " << fds[i].fd << " disconnected" << std::endl;
                    close(fds[i].fd);
                    fds[i].fd = -1;
                }
            }
            
            // Check for client disconnect
            if (fds[i].revents & (POLLHUP | POLLERR)) {
                std::cout << "Client " << fds[i].fd << " disconnected" << std::endl;
                close(fds[i].fd);
                fds[i].fd = -1;  // Mark slot as empty
            }
        }
    }

    // Cleanup
    close(server_fd);
    return 0;
}