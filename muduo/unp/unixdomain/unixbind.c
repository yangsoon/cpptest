#include "unp.h"

int main(int argc, char **argv) {
    int sockfd;
    socklen_t len;

    struct sockaddr_un addr1, addr2;

    if(argc!=2) {
        err_quit("usage: unixbind <pathname>");
    }

    if((sockfd = socket(AF_LOCAL, SOCK_STREAM, 0)) < 0) {
        err_sys("socket error");
    }

    // 如果文件系统已经有了该路径名 bind将会失败 首先需要用unlink删除这个路径名
    unlink(argv[1]);

    bzero(&addr1, sizeof(addr1));
    addr1.sun_family = AF_LOCAL;
    strncpy(addr1.sun_path, argv[1], sizeof(addr1.sun_path) - 1);

    if(bind(sockfd, (struct sockaddr*)&addr1, SUN_LEN(&addr1)) < 0) {
        err_sys("bind error");
    }

    len = sizeof(addr2);
    if (getsockname(sockfd, (struct sockaddr*)&addr2, &len) < 0)
		err_sys("getsockname error");
    
    printf("bound name = %s, return len = %d\n", addr2.sun_path, len);
    exit(0);
}