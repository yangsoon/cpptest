#include "unp.h"

void select_str_cli(FILE *fp, int sockfd) {
    int maxfdp1, stdineof;
    fd_set rset;
    char buf[MAXLINE];
    int n;
    
    stdineof = 0;
    FD_ZERO(&rset);
    for(;;) {
        if(stdineof==0) {
            FD_SET(sockfd, &rset);
        }
        FD_SET(fileno(fp), &rset);
        maxfdp1 = max(fileno(fp), sockfd) + 1;

        if((select(maxfdp1, &rset, NULL, NULL, NULL))<0) {
            err_sys("select error");
        }

        if(FD_ISSET(sockfd, &rset)) {
            if((n=Readline(sockfd, buf, MAXLINE)) == 0) {
                if(stdineof==1) {
                    return;
                } else {
                    err_quit("str_cli: server terminated");
                }
            }
            Write(fileno(fp), buf, n);
        }

        if(FD_ISSET(fileno(fp), &rset)) {
            if((n=Readline(fileno(fp), buf, MAXLINE)) == 0) {
                stdineof = 1;
                // 一般使用close来关闭一个套接字
                // 但是使用close有2个局限性， 首先close先把描述符的引用计数减去1 只有在引用计数为0的时候才会关闭套接字
                // 其次是close终止的时候是读写全都关闭 但是套接字是全双工的 有时候我们需要告诉对端我们完成了数据发送，还可以接受对端的数据
                // 即关闭写的这一半 也叫半关闭

                // 使用shutdown就可以解决上面的问题 使用shutdown的时候不管引用计数是否为0都照样关闭
                // 还可以通过设置第二个参数 来选择如何关闭
                if(shutdown(sockfd, SHUT_WR) < 0) {
                    err_sys("shutdown error");
                }
                FD_CLR(fileno(fp), &rset);
                continue;
            }
            Write(sockfd, buf, n);
        }
    }
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    int n;

    if(argc != 2) {
        err_quit("usage: <IPAddress>");
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0){
        err_sys("socket error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        err_sys("connect error");
    }

    select_str_cli(stdin, sockfd);
    exit(0);
}