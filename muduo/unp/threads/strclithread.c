#include "unpthread.h"

void *copyto(void *);
static int sockfd;
static FILE *fp;

// 从套接字中读取数据输出到标准输出中
void str_cli_thread(FILE *fp_arg, int sockfd_arg) {
    char recvline[MAXLINE];
    pthread_t tid;
    sockfd = sockfd_arg;
    fp = fp_arg;
    
    int n;
    // pthread_create创建一个线程 当成功返回0 不成功返回一个非0值 代表具体的错误
    if((n = pthread_create(&tid, NULL, copyto, NULL) != 0)) {
        errno = n;
        err_sys("pthread_create error");
    }

    while(Readline(sockfd, recvline, MAXLINE) > 0) {
        Fputs(recvline, stdout);
    }
}

// 从标准输入中获取数据输出到套接字中
void* copyto(void *arg) {
    char sendline[MAXLINE];
    while(Fgets(sendline, MAXLINE, fp)!=NULL) {
        Write(sockfd, sendline, strlen(sendline));
    }
    // 当遇到标准输入的EOF的时候 半关闭 发送FIN
    shutdown(sockfd, SHUT_WR);
    return(NULL);
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;

    if(argc != 2) {
        err_quit("uasge: cli.o <IPAddress>");
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        err_sys("socket error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        err_sys("connect error");
    }

    str_cli_thread(stdin, sockfd);

    exit(0);
}