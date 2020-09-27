#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int sock_send(int sock_desc, char* request);
int sock_recv(int sock_desc, char* response, int size);
int main (void) {
    short sock_desc = socket(AF_INET, SOCK_STREAM, 0);

    int port = 1337;
    struct sockaddr_in remote = {0};
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_port = htons(port);

    int con_ret_val = connect(sock_desc, (struct sockaddr*) &remote, sizeof(remote));
    if (con_ret_val < 0) {
        printf("Could not connect.\n");
        return -1;
    }

    char message[100];
    printf("What would you like to send to the server?\n");
    fgets(message, 100, stdin);

    int send_res = sock_send(sock_desc, message);
    if (send_res < 0) {
        printf("Could not send message.\n");
        return 1;
    }

    char response[100] = {0};
    int rec_res = sock_recv(sock_desc, response, 100);

    if (rec_res < 0) {
        printf("Could not receive message.\n");
        return 1;
    }

    printf("Server response: %s\n", response);

    close(sock_desc);

    return 0;
}

int sock_send(int sock_desc, char* request) {
    struct timeval tv; //timeout
    tv.tv_sec = 20;
    tv.tv_usec = 0;
    if (setsockopt(sock_desc, SOL_SOCKET, SO_SNDTIMEO, (char*) &tv, sizeof(tv)) < 0) {
        printf("Timeout...\n");
        return -1;
    }

    return send(sock_desc, request, strlen(request), 0);
}

int sock_recv(int sock_desc, char* response, int size) {
    struct timeval tv; //timeout
    tv.tv_sec = 20;
    tv.tv_usec = 0;
    if (setsockopt(sock_desc, SOL_SOCKET, SO_RCVTIMEO, (char*) &tv, sizeof(tv)) < 0) {
        printf("Timeout...\n");
        return -1;
    }
    return recv(sock_desc, response, size, 0);
}
