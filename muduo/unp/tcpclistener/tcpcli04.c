#include "unp.h"

int main(int argc, char **argv) {
    if(argc!=2) {
        err_quit("usage tcpcli <IPAddress");
    }

    int i, sockfd[5];
    struct sockaddr_in servaddr;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    for(i = 0; i < 5; i++) {
        sockfd[i] = Socket(AF_INET, SOCK_STREAM, 0);
        Connect(sockfd[i], (SA *)&servaddr, sizeof(servaddr));
    }
    str_cli(stdin, sockfd[0]);
    exit(0);
}