#include "unp.h"

void sig_chld(int signo) {
    pid_t pid;
    int stat;

    // #include <sys/types.h>
    // #include <sys/wait.h>

    // pid_t wait(int *status);
    // param: pid = -1的时候表示等待第一个终止的子进程， options参数中指定WNOHANG可以使父进程不阻塞而立即返回0
    // pid_t waitpid(pid_t pid, int *status, int options);

    // 两个函数成功均返回进程pid 出错则返回0或-1

    // 1. 若调用成功则返回清理掉的子进程id，若调用出错则返回-1。父进程调用wait或waitpid时可能会：
    //      1. 阻塞（如果它的所有子进程都还在运行）。
    //      2. 带子进程的终止信息立即返回（如果一个子进程已终止，正等待父进程读取其终止信息）。
    //      3. 出错立即返回（如果它没有任何子进程）。
    // 2. 这两个函数的区别是：
    //      如果父进程的所有子进程都还在运行，调用wait将使父进程阻塞，而调用waitpid时如果在options参数中指定WNOHANG可以使父进程不阻塞而立即返回0。
    //      wait等待第一个终止的子进程，而waitpid可以通过pid参数指定等待哪一个子进程。
    //      可见，调用wait和waitpid不仅可以获得子进程的终止信息，还可以使父进程阻塞等待子进程终止，起到进程间同步的作用。如果参数status不是空指针，则子进程的终止信息通过这个参数传出，如果只是为了同步而不关心子进程的终止信息，可以将status参数指定为NULL。
    
    // 为什么不用wait而用waitpid?
    // 1. 建立一个信号处理函数并在信号处理函数中调用wait并不能防止出现僵尸进程
    // 2. 如果多个链接在同一时间退出所有的多个信号在处理函数之前产生而信号函数只执行一次(理想应该执行多次)
    // 3. 因为unix对信号一般是不排队的，因此使用waitpid循环等待获取所有终止进程的信息，如果没有子进程已经终止时就不阻塞退出，如果有多个线程终止就循环捕获。
    // 4. wait函数只会阻塞等待子进程 如果有还在运行的进程也会阻塞等待。
    while((pid = waitpid(-1, &stat, WNOHANG)) > 0) {
        printf("child %d terminated", pid);
    }
    return;
}


int main(int argc, char **argv) {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in servaddr, cliaddr;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family  = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        err_sys("socket error");
    }

    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        err_sys("bind error");
    }

    if(listen(listenfd, LISTENQ) < 0) {
        err_sys("listen error");
    }

    Singal(SIGCHLD, sig_chld);

    for(;;) {
        clilen = sizeof(cliaddr);
        if((connfd = accept(listenfd, (SA*)&cliaddr, &clilen)) < 0) {
            if(errno == EINTR) {
                continue;
            } else {
                err_sys("accept error");
            }   
        }
        if((childpid = Fork()) == 0) {
            Close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        Close(connfd);
    }
}