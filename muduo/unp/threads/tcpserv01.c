#include "unpthread.h"

static void* doit(void *);

int main(int argc, char **argv) {
    int listenfd, connfd;
    int *iptr;
    pthread_t tid;
    socklen_t addrlen, len;
    struct sockaddr *cliaddr;
    
    if(argc == 2) {
        listenfd = Tcp_listen(NULL, argv[1], &addrlen);
    } else if(argc == 3) {
        listenfd = Tcp_listen(argv[1], argv[2], &addrlen);
    } else {
        err_quit("usage...");
    }

    cliaddr = Malloc(addrlen);
    for(;;) {
        len = addrlen;
        iptr = Malloc(sizeof(int));
        *iptr = Accept(listenfd, cliaddr, &len);
        if(pthread_create(&tid, NULL, &doit, (void *) connfd) != 0) {
            err_sys("pthread_create error");
        }
    }
}

static void* doit(void * arg) {
    int connfd;
    connfd = *((int *) arg);
    free(arg);

    // 线程首先脱离 主线程没有理由等待它创建的每一个线程
    pthread_detach(pthread_self());
    str_echo((int) arg);
    Close((int) arg);
    return(NULL);
}