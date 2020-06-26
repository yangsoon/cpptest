#include "unp.h"

void str_echo_local(int sockfd) {
    ssize_t n;
    char buf[MAXLINE];
again:
    // 如果客户端关闭连接 那么接收到客户端的FIN将导致read的返回值n=0，进而导致函数返回
    while((n=read(sockfd, buf, MAXLINE))>0) {
        Write(sockfd, buf, n);
    }

    if(n < 0 && errno == EINTR) {
        goto again;
    } else if (n < 0) {
        err_sys("read error");
    }
}

int main(int argc, char **argv) {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in servaddr, cliaddr;

    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        err_sys("socket error");
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    // int bind(int sockfd, const struct sockaddr *myaddr, socklen_t addrlen);
    if(bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
        err_sys("bind error");
    }

    // int listen(int sockfd, int backlog);
    if(listen(listenfd, LISTENQ)<0) {
        err_sys("listen error");
    }

    for(;;) {
        clilen = sizeof(cliaddr);

        // int accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);

        if((childpid = fork()) == 0) {
            if(close(listenfd)<0) {
                err_sys("listen error");
            }
            str_echo_local(connfd);
            exit(0);
        }

        if(close(connfd)<0) {
            err_sys("close error");
        }
    }
}