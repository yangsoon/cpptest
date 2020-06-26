#include "unp.h"

void str_echo_local(int sockfd) {
    ssize_t n;
    char buf[MAXLINE];
again:
    // 如果客户端关闭连接 那么接收到客户端的FIN将导致read的返回值n=0，进而导致函数返回
    while((n=read(sockfd, buf, MAXLINE))>0) {
        Write(sockfd, buf, n);
    }

    if(n < 0 && errno == EINTR) {
        goto again;
    } else if (n < 0) {
        err_sys("read error");
    }
}

void sig_chld(int signo)
{
	pid_t	pid;
	int		stat;

	while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0) {
		printf("child %d terminated\n", pid);
	}
	return;
}

Sigfunc * demo_signal(int signo, Sigfunc *func)
{
   /* 
    将sa_handler赋值为常数SIG_IGN传给sigaction表示忽略信号，赋值为常数SIG_DFL表示执行系统默认动作，赋值为一个函数指针表示用自定义函数捕捉信号，
    或者说向内核注册了一个信号处理函数，该函数返回值为void，可以带一个int参数，通过参数可以得知当前信号的编号，这样就可以用同一个函数处理多种信号。
    显然，这也是一个回调函数，不是被main函数调用，而是被系统所调用。当某个信号的处理函数被调用时，内核自动将当前信号加入进程的信号屏蔽字，
    当信号处理函数返回时自动恢复原来的信号屏蔽字，这样就保证了在处理某个信号时，如果这种信号再次产生，那么它会被阻塞到当前处理结束为止。
    如果在调用信号处理函数时，除了当前信号被自动屏蔽之外，还希望自动屏蔽另外一些信号，则用sa_mask字段说明这些需要额外屏蔽的信号，当信号处理函数返回时自动恢复原来的信号屏蔽字。
 */
    // struct sigaction {
    //    void      (*sa_handler)(int);   /* addr of signal handler, */
    //                                        /* or SIG_IGN, or SIG_DFL */
    //    sigset_t sa_mask;               /* additional signals to block */
    //    int      sa_flags;              /* signal options, Figure 10.16 */

    //    /* alternate handler */
    //    void     (*sa_sigaction)(int, siginfo_t *, void *);
    // };
	struct sigaction	act, oact;
	
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if (signo == SIGALRM) {
#ifdef	SA_INTERRUPT
		act.sa_flags |= SA_INTERRUPT;	/* SunOS 4.x */
#endif
	} else {
#ifdef	SA_RESTART
		act.sa_flags |= SA_RESTART;		/* SVR4, 44BSD */
#endif
	}

    /*
    #include <signal.h>
    int sigaction(int signo, const struct sigaction *act, struct sigaction *oact);
    */

    // sigaction函数可以读取和修改与指定信号相关联的处理动作。调用成功则返回0，出错则返回-1。
    // signo是指定信号的编号。若act指针非空，则根据act修改该信号的处理动作。若oact指针非空，则通过oact传出该信号原来的处理动作。
	if (sigaction(signo, &act, &oact) < 0)
		return(SIG_ERR);
	return(oact.sa_handler);
}

int main(int argc, char **argv) {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in servaddr, cliaddr;

    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        err_sys("socket error");
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    if(bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
        err_sys("bind error");
    }

    if(listen(listenfd, LISTENQ)<0) {
        err_sys("listen error");
    }

    // 因为在for循环中没有wait子进程，当子进程处理完连接之后 进入僵死状态
    // 因为僵尸进程会占用内核空间 所以我们需要对僵尸进程的PCB进行回收
    // 当子进程结束之后内核会对相应的父进程发送SIGCHID信号，但是unix默认忽略信号
    // 所以这里我们需要注册对该信号的处理程序
    Signal(SIGCHLD, sig_chld);

    for(;;) {
        clilen = sizeof(cliaddr);

        /* 
        1. 当主进程阻塞在accept函数等待其他连接的时候 如果子进程退出内核向子进程的父进程发送一个SIGCHLD信号
        因为主进程建立了对该信号的处理函数 所以会执行相应的函数处理
        2. 因为该信号是父进程阻塞于系统调用的时候被父进程捕获的，部分系统如Solaris的内核就会使accept返回EINTR错误(被中断的系统调用)
        导致进程终止，但在BSD系统中 内核将重启被中断的应用。
        */
        // accept被称为慢系统调用 描述可能永久阻塞的函数
        if ((connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen)) < 0) {
            // 为了处理系统调用被中断的情况，这里手动处理系统调用中断问题，当errno==EINTR时 继续执行
            // ! 只有connect不能重启 如果该函数返回EINTR 就不能再次调用了，当connect函数调用被信号中断而不再重启之后
            // 我们必须调用select函数来等待连接完成
            if(errno==EINTR)
                continue;
            else
                err_sys("accpet error");
        }

        if((childpid = fork()) == 0) {
            if(close(listenfd)<0) {
                err_sys("listen error");
            }
            str_echo_local(connfd);
            exit(0);
        }

        if(close(connfd)<0) {
            err_sys("close error");
        }
    }
}