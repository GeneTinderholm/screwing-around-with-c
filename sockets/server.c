#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main (void) {
    short sock_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_desc == -1) {
        printf("Could not create socket.\n");
        return 1;
    }
    int port = 1337;
    struct sockaddr_in remote = {0};
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(port);

    int bind_ret_val = bind(sock_desc, (struct sockaddr*) &remote, sizeof(remote));

    if (bind_ret_val < 0) {
        printf("Could not bind socket.\n");
        return 1;
    }

    struct sockaddr_in client = {0};
    char client_message[200] = {0};
    char message[100] = {0};
    const char* p_message = "Hello, from the server.";

    printf("Waiting for incoming connections...\n");
    listen(sock_desc, 3);

    while (1) {
        int client_len = sizeof(struct sockaddr_in);
        int sock = accept(sock_desc, (struct sockaddr*) &client, (socklen_t*) &client_len);

        if (sock < 0) {
            printf("Accept failed.\n");
            return 1;
        }

        memset(client_message, '\0', sizeof(client_message));
        memset(message, '\0', sizeof(message));

        if (recv(sock, client_message, 200, 0) < 0) {
            printf("recv failed\n");
            return 1;
        }
        printf("Client message: %s\n", client_message);

        strcpy(message, p_message);

        if (send(sock, message, strlen(message), 0) < 0) {
            printf("recv failed\n");
            return 1;
        }
        close(sock);
        sleep(1);
    }

    return 0;
}
