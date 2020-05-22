#include "unp.h"
#include <time.h>

int main(int argc, char **argv) {
    int listenfd, connfd;
    struct sockaddr_in serveraddr;
    char buff[MAXLINE + 1];
    time_t ticks;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0))<0) {
        err_sys("socket error");
    }
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    //UNP p82 INADDR_ANY服务器主机有多个网络接口服务器进程就可以在多个网络接口上接受客户连接
    // INADDR_ANY 代表通配地址 值为0 
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(13);

    // UNP p83 
    if(bind(listenfd, (SA *)&serveraddr, sizeof(serveraddr) < 0)) {
        err_sys("bind error");
    }
    
}