#include "unp.h"

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    // // UNP p56 
    // struct in_addr {
    //     // 32位ip地址 网络字节序(大端序列)
    //     // 低地址存储高字节 0x0102为例 01高字节存储在低地址
    //     in_addr_t s_addr;
    // };
    // // 套接字地址结构
    // struct sockaddr_in {
    //     uint8_t sin_len;
    //     sa_family_t sin_family; 
    //     // port 和 addr需要手动进行host和network字节序的转换
    //     in_port_t sin_port;
    //     struct in_addr sin_addr;
    //     char sin_zero[8];
    // };
    
    struct sockaddr_in servaddr;

    if(argc!=2) {
        err_quit("usage: a.out <IPaddress>");
    }
    
    // int socket(int family, int type, int protocol);

    // UNP p78 socket param1 指定协议族 一般都使用地址族的宏定义 AF_INET ...
    // param2 指定套接字类型 tcp->SOCK_STREAM udp->SOCT_DGRAM
    // param3 0
    // return success 非负的sock描述符
    if((sockfd=socket(AF_INET, SOCK_STREAM, 0))<0){
        err_sys("socket error");
    }

    // UNP p66 字节操纵函数 针对sockaddr_in结构体 因为结构体内包含0 所以只能用bxxx的函数
    // strxxx的函数是把数据当成以0结尾的字符串处理
    // bzero有2个参数比memset更好记 param1 void* dest param2 size_t nbytes
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;

    // htons 将主机字节序转换为网络字节序 h->host n->network s->short(16 bit)
    servaddr.sin_port = htons(13);
    
    // int inet_pton(int family, const char *strptr, void *addrptr);

    // UNP p68 inet_pton 将主机序转换为网络序 适用于ipv4/6 主要使用这个函数 p->presentation n->numeric 
    // param1 地址族 param2 待转换的字符串指针 param3 存储二进制结果
    // return 成功为0 失败返回-1
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        err_quit("inet_pton error for %s");
    }

    // int connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen);
    // UNP p58 SA表示通用套接字地址结构 #define	SA	struct sockaddr
    // 套接字函数为了兼容不同的sock协议族 使用 sockaddr* 作为参数
    // UNP p80 connect param1 是sock函数返回的套接字描述符 param2 指向套接字地址结构的指针 param3 该结构的大小
    // return 成功为0 失败为-1
    if(connect(sockfd, (SA*) &servaddr, sizeof(servaddr)) < 0) {
        // !connect 失败则套接字不可再用 必须关闭 我们不能对这样的套接字再调用connect 必须调用close关闭
        err_sys("connect error");
    }

    // APUE p57 read param1 文件描述符 param2 指向读取内容的字符串指针 param3 能读取的最多的字节数
    // return 成功返回读到的字节数 如果到文件尾 返回0 出错返回 -1
    while((n = read(sockfd, recvline, MAXLINE)) > 0 ) {
        recvline[n] = 0;
        if(fputs(recvline, stdout) == EOF) {
            err_sys("fputs error");
        }
    }
    if (n < 0) {
        err_sys("read error");
    }
    exit(0);
}