#include "unp.h"

int main(int argc, char **argv) {
    int i, maxi, maxfd, listenfd, connfd, sockfd;
    int nready, client[FD_SETSIZE];
    ssize_t n;
    fd_set rset, allset;
    
    char buf[MAXLINE];
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        err_sys("socket error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr))<0) {
        err_sys("bind error");
    }

    if(listen(listenfd, LISTENQ) < 0) {
        err_sys("listen error");
    }

    maxfd = listenfd;
    maxi = -1;
    for(i = 0; i < FD_SETSIZE; i++) {
        client[i] = -1;
    }
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);

    for(;;) {
        rset = allset;
        if((nready = select(maxfd, &rset, NULL, NULL, NULL)) < 0) {
            err_sys("select error");
        }

        if(FD_ISSET(listenfd, &rset)) {
            clilen = sizeof(cliaddr);
            if((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen)) < 0) {
                err_sys("accept error");
            }
            for(i = 0; i < FD_SETSIZE; i++) {
                if(client[i]<0) {
                    client[i] = connfd;
                    break;
                }
            }
            if(i == FD_SETSIZE) {
                err_quit("too many clients");
            }

            FD_SET(connfd, &allset);

            if(connfd > maxfd) {
                maxfd = connfd;
            }

            if(i > maxi) {
                maxi = i; // max index in client[]
            }

            if(--nready <= 0) {
                continue;
            }
        }

        for(i = 0; i <= maxi; i++) {
            if((sockfd = client[i]) < 0) {
                continue;
            }
            if(FD_ISSET(sockfd, &rset)) {
                if((n = Read(sockfd, buf, MAXLINE)) == 0) {
                    Close(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                } else {
                    Write(sockfd, buf, n);
                }
                if(--nready <= 0) {
                    break;
                }
            }
        }
    }

}