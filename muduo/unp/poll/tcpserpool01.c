#include "unp.h"

int main(int argc, char **argv) {
    int i, maxi, listenfd, connfd, sockfd;
    int nready;
    ssize_t n;
    char buf[MAXLINE];
    socklen_t clilen;
    struct pollfd client[OPEN_MAX];
    struct sockaddr_in cliaddr, servaddr;

    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        err_sys("socket error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        err_sys("bind error");
    }

    if(listen(listenfd, LISTENQ) < 0) {
        err_sys("listen error");
    }

    client[0].fd = listenfd;
    client[0].events = POLLRDNORM;
    for(i = 1; i < OPEN_MAX; i++) {
        client[i].fd = -1;
    }
    maxi = 0;

    for(;;) {
        if((nready = poll(client, maxi+1, INFTIM)) < 0) {
            err_sys("poll errro");
        }
        if(client[0].revents & POLLRDNORM) {
            clilen = sizeof(cliaddr);
            if((connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen)) < 0) {
                err_sys("connfd error");
            }
            for(i = 1; i < OPEN_MAX; i++) {
                if(client[i].fd < 0) {
                    client[i].fd = connfd;
                    break;
                }
            }
            if(i == OPEN_MAX) {
                err_quit("too many client");
            }
            client[i].events = POLLRDNORM;
            if(i > maxi) {
                maxi = i;
            }
            if(--nready <= 0) {
                continue;
            }
        }

        for(i = 1; i <= maxi; i++) {
            if((sockfd = client[i].fd) < 0) {
                continue;
            }
            if(client[i].revents&(POLLRDNORM|POLLERR)) {
                if((n = read(sockfd, buf, MAXLINE)) < 0) {
                    if(errno == ECONNRESET) { // 接收到客户端的rst
                        Close(sockfd);
                        client[i].fd = -1;
                    }
                } else if(n == 0) { // 客户端关闭
                    Close(sockfd);
                    client[i].fd = -1;
                } else {
                    Write(sockfd, buf, n);
                }
            } 
            if(--nready<=0) {
                break;
            }
        }
    }
}