#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 5);

    printf("Server listening on port %d\n", PORT);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*)&address, &addrlen);

        if (fork() == 0) {   // child process
            close(server_fd);

            read(client_fd, buffer, 1024);
            printf("Client: %s\n", buffer);

            send(client_fd, buffer, strlen(buffer), 0);
            close(client_fd);
            exit(0);
        }
        close(client_fd); // parent closes socket
    }
}
