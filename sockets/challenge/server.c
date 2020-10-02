#include <stdlib.h>
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

    // initialize client 1
    struct sockaddr_in client_one = {0};
    char client_one_message[10] = {0};

    // initialize client 2
    struct sockaddr_in client_two = {0};

    printf("Waiting for incoming connections...\n");
    listen(sock_desc, 3);

    int client_len = sizeof(struct sockaddr_in);
    int sock_one = accept(sock_desc, (struct sockaddr*) &client_one, (socklen_t*) &client_len);
    if (sock_one < 0) {
        printf("Accept failed.\n");
        return 1;
    }
    printf("Connected to first client.\n");
    int sock_two = accept(sock_desc, (struct sockaddr*) &client_two, (socklen_t*) &client_len);
    if (sock_two < 0) {
        printf("Accept failed.\n");
        return 1;
    }
    printf("Connected to second client.\n");

    if (recv(sock_one, client_one_message, 10, 0) < 0) {
        printf("recv failed\n");
        return 1;
    }

    printf("Client one message: %s\n", client_one_message);
    int client_one_int = atoi(client_one_message);

    --client_one_int;
    char client_two_string[10];
    sprintf(client_two_string, "%d", client_one_int);


    if (send(sock_two, client_two_string, strlen(client_two_string), 0) < 0) {
        printf("recv failed\n");
        return 1;
    }
    close(sock_one);
    close(sock_two);

    return 0;
}
