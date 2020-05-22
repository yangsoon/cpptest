#include "unp.h"
#include <time.h>

int main(int argc, char **argv) {
    int listenfd, connfd;
    struct sockaddr_in serveraddr, cliaddr;
    char buff[MAXLINE + 1];
    time_t ticks;
    socklen_t len;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0))<0) {
        err_sys("socket error");
    }
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    //UNP p82 INADDR_ANY服务器主机有多个网络接口服务器进程就可以在多个网络接口上接受客户连接
    // INADDR_ANY 代表通配地址 值为0 
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(13);

    // UNP p83  bind函数把一个本地协议地址赋予一个套接字
    if(bind(listenfd, (SA *)&serveraddr, sizeof(serveraddr)) < 0 ) {
        err_sys("bind error");
    }

    /*
    UNP p84 listen 函数
    仅仅由TCP服务器调用 当socket创建一个一个套接字时，它被假设为一个主动套接字，就是会主动发起connect函数调用的socket
    listen 函数把一个未连接的套接字转换为一个被动套接字，调用listen会导致套接字从CLOSED状态转换为LISTEN状态。
    第二个参数指定了套接字排队的最大连接个数

    内核为每个监听套接字维护2个队列
    1. 未完成队列 该部分存储的套接字完成了3次握手的前2次阶段 处于SYN_RCVD状态 等待客户端的syn报文
    2. 已完成连接队列 当未完成队列中的套接字完成3次握手之后 从未完成队列放到完成队列
    当进程调用accept函数之后 已完成队列的队头项目就返回给进程，队列为空时 休眠

    注意未完成队列的套接字在未完成队列存在的时间就是一个RTT
    当一个客户的SYN来到的时候，如果队列满了 那么服务器就忽略SYN 也不发送RST 因为队列满是暂时的 客户端可以重发SYN 直到队列有空间
    */
    if(listen(listenfd, LISTENQ) < 0) {
        err_sys("listen error");
    }

    for(;;) {
        len = sizeof(cliaddr);

        /*
        accept 用于从已完成队列中取出下一个已经完成的连接
        param1: 监听套接字 由sock创建 并随后被bind listen所用的第一个参数
        param2: 返回已连接的对端进程的协议地址 
        param3 返回套接字结构体内确切的字节数
        return: 如果accept成功返回一个内核产生的新的描述符(已连接套接字) 代表与所返回客户的tcp连接
        */

        // 如果对返回的客户协议地址都不感兴趣就直接都设置为空指针
        // if((connfd = accept(listenfd, (SA *)NULL, &NULL)) < 0) 
        if((connfd = accept(listenfd, (SA *)&cliaddr, &len)) < 0) {
            err_sys("connect error");
        }
        printf("connection from %s, port %d\n",
             inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
             ntohs(cliaddr.sin_port));
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));

        // APUE p58 write向描述符写数据 param3指定写入的字节数 返回成功写入的个数
        // 返回值是和参数3一致的如果不一样说明出错
        if (write(connfd, buff, sizeof(buff)) != sizeof(buff))
            err_sys("write error");
        if (close(connfd) == -1) 
            err_sys("close error");
    }
}