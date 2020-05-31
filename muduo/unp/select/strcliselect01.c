// 使用select重写str_cli函数，这样服务器进程一终止，客户就能马上得到通知。
// 之前的版本当套接字发生某些时间时，客户可能阻塞于fgets调用。新版本改为阻塞在select调用上
#include "unp.h"


void select_str_cli(FILE *fp, int sockfd) {
    int maxfdp1;
    fd_set rset;
    int n;
    char sendline[MAXLINE], recvline[MAXLINE];

    // 用于初始化
    FD_ZERO(&rset);
    // 使用select来驱动，区分描述符
    for(;;) {
        //设置监控的文件描述符
        //每次调用select之后 rset都会被清空 所以需要重新设置
        FD_SET(fileno(fp), &rset);
        FD_SET(sockfd, &rset);
        // 注意这里的maxfd1一定设为最大值加1 因为这个传给select可以认为是描述符的个数
        maxfdp1 = max(fileno(fp), sockfd) + 1;

        // select 调用
        // int select(int maxfdp,fd_set *readfds,fd_set *writefds,fd_set *errorfds,struct timeval*timeout);
        // 第一个参数表示监听描述符的最大值，后面的参数依次表示 可读 可写 异常集合 以及超时时间
        // 可读集合：sock有数据可读 对端关闭写 有新的连接
        // 可写集合：sock有缓存空间可以写 主动关闭写端
        // !!当套接字上发生错误时候 可写也可读
        // 异常 只有出现带外数据的时候才出现异常
        if((n = select(maxfdp1, &rset, NULL, NULL, NULL)) < 0) {
            err_sys("select error");
        }
        if(FD_ISSET(sockfd, &rset)) {
            if(Readline(sockfd, recvline, MAXLINE) == 0) {
                err_quit("str_cli: server terminated prematurely");
            }
            Fputs(recvline, stdout);
        }

        if(FD_ISSET(fileno(fp), &rset)) {
            if(Fgets(sendline, MAXLINE, fp) == NULL) {
                return;
            }
            Write(sockfd, sendline, strlen(sendline));
        }
    }
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;

    if(argc!=2) {
        err_quit("usage: tcpcli <IPaddress>");
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        err_sys("sockfd error");
    }

    // 基本流程
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        err_sys("connect error");
    }
    // Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    select_str_cli(stdin, sockfd);
    exit(0);
}