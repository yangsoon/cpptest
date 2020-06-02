#include "apue.h"
#include <errno.h>
#include <limits.h>

static void	pr_sysconf(char *, int);
static void	pr_pathconf(char *, char *, int);

int
main(int argc, char *argv[])
{
	if (argc != 2)
		err_quit("usage: a.out <dirname>");

#ifdef ARG_MAX
	printf("ARG_MAX defined to be %ld\n", (long)ARG_MAX+0);
#else
	printf("no symbol for ARG_MAX\n");
#endif
#ifdef _SC_ARG_MAX
	pr_sysconf("ARG_MAX =", _SC_ARG_MAX);
#else
	printf("no symbol for _SC_ARG_MAX\n");
#endif
#ifdef ATEXIT_MAX
	printf("ATEXIT_MAX defined to be %ld\n", (long)ATEXIT_MAX+0);
#else
	printf("no symbol for ATEXIT_MAX\n");
#endif
#ifdef _SC_ATEXIT_MAX
	pr_sysconf("ATEXIT_MAX =", _SC_ATEXIT_MAX);
#else
	printf("no symbol for _SC_ATEXIT_MAX\n");
#endif
#ifdef CHARCLASS_NAME_MAX
	printf("CHARCLASS_NAME_MAX defined to be %ld\n", (long)CHARCLASS_NAME_MAX+0);
#else
	printf("no symbol for CHARCLASS_NAME_MAX\n");
#endif
#ifdef _SC_CHARCLASS_NAME_MAX
	pr_sysconf("CHARCLASS_NAME_MAX =", _SC_CHARCLASS_NAME_MAX);
#else
	printf("no symbol for _SC_CHARCLASS_NAME_MAX\n");
#endif
#ifdef CHILD_MAX
	printf("CHILD_MAX defined to be %ld\n", (long)CHILD_MAX+0);
#else
	printf("no symbol for CHILD_MAX\n");
#endif
#ifdef _SC_CHILD_MAX
	pr_sysconf("CHILD_MAX =", _SC_CHILD_MAX);
#else
	printf("no symbol for _SC_CHILD_MAX\n");
#endif
#ifdef CLOCKTICKSPERSECOND /*clock ticks/second*/
	printf("CLOCKTICKSPERSECOND /*clock ticks/second*/ defined to be %ld\n", (long)CLOCKTICKSPERSECOND /*clock ticks/second*/+0);
#else
	printf("no symbol for CLOCKTICKSPERSECOND /*clock ticks/second*/\n");
#endif
#ifdef _SC_CLK_TCK
	pr_sysconf("CLOCKTICKSPERSECOND /*clock ticks/second*/ =", _SC_CLK_TCK);
#else
	printf("no symbol for _SC_CLK_TCK\n");
#endif
#ifdef COLL_WEIGHTS_MAX
	printf("COLL_WEIGHTS_MAX defined to be %ld\n", (long)COLL_WEIGHTS_MAX+0);
#else
	printf("no symbol for COLL_WEIGHTS_MAX\n");
#endif
#ifdef _SC_COLL_WEIGHTS_MAX
	pr_sysconf("COLL_WEIGHTS_MAX =", _SC_COLL_WEIGHTS_MAX);
#else
	printf("no symbol for _SC_COLL_WEIGHTS_MAX\n");
#endif
#ifdef DELAYTIMER_MAX
	printf("DELAYTIMER_MAX defined to be %ld\n", (long)DELAYTIMER_MAX+0);
#else
	printf("no symbol for DELAYTIMER_MAX\n");
#endif
#ifdef _SC_DELAYTIMER_MAX
	pr_sysconf("DELAYTIMER_MAX =", _SC_DELAYTIMER_MAX);
#else
	printf("no symbol for _SC_DELAYTIMER_MAX\n");
#endif
#ifdef HOST_NAME_MAX
	printf("HOST_NAME_MAX defined to be %ld\n", (long)HOST_NAME_MAX+0);
#else
	printf("no symbol for HOST_NAME_MAX\n");
#endif
#ifdef _SC_HOST_NAME_MAX
	pr_sysconf("HOST_NAME_MAX =", _SC_HOST_NAME_MAX);
#else
	printf("no symbol for _SC_HOST_NAME_MAX\n");
#endif
#ifdef IOV_MAX
	printf("IOV_MAX defined to be %ld\n", (long)IOV_MAX+0);
#else
	printf("no symbol for IOV_MAX\n");
#endif
#ifdef _SC_IOV_MAX
	pr_sysconf("IOV_MAX =", _SC_IOV_MAX);
#else
	printf("no symbol for _SC_IOV_MAX\n");
#endif
#ifdef LINE_MAX
	printf("LINE_MAX defined to be %ld\n", (long)LINE_MAX+0);
#else
	printf("no symbol for LINE_MAX\n");
#endif
#ifdef _SC_LINE_MAX
	pr_sysconf("LINE_MAX =", _SC_LINE_MAX);
#else
	printf("no symbol for _SC_LINE_MAX\n");
#endif
#ifdef LOGIN_NAME_MAX
	printf("LOGIN_NAME_MAX defined to be %ld\n", (long)LOGIN_NAME_MAX+0);
#else
	printf("no symbol for LOGIN_NAME_MAX\n");
#endif
#ifdef _SC_LOGIN_NAME_MAX
	pr_sysconf("LOGIN_NAME_MAX =", _SC_LOGIN_NAME_MAX);
#else
	printf("no symbol for _SC_LOGIN_NAME_MAX\n");
#endif
#ifdef NGROUPS_MAX
	printf("NGROUPS_MAX defined to be %ld\n", (long)NGROUPS_MAX+0);
#else
	printf("no symbol for NGROUPS_MAX\n");
#endif
#ifdef _SC_NGROUPS_MAX
	pr_sysconf("NGROUPS_MAX =", _SC_NGROUPS_MAX);
#else
	printf("no symbol for _SC_NGROUPS_MAX\n");
#endif
#ifdef OPEN_MAX
	printf("OPEN_MAX defined to be %ld\n", (long)OPEN_MAX+0);
#else
	printf("no symbol for OPEN_MAX\n");
#endif
#ifdef _SC_OPEN_MAX
	pr_sysconf("OPEN_MAX =", _SC_OPEN_MAX);
#else
	printf("no symbol for _SC_OPEN_MAX\n");
#endif
#ifdef PAGESIZE
	printf("PAGESIZE defined to be %ld\n", (long)PAGESIZE+0);
#else
	printf("no symbol for PAGESIZE\n");
#endif
#ifdef _SC_PAGESIZE
	pr_sysconf("PAGESIZE =", _SC_PAGESIZE);
#else
	printf("no symbol for _SC_PAGESIZE\n");
#endif
#ifdef PAGE_SIZE
	printf("PAGE_SIZE defined to be %ld\n", (long)PAGE_SIZE+0);
#else
	printf("no symbol for PAGE_SIZE\n");
#endif
#ifdef _SC_PAGE_SIZE
	pr_sysconf("PAGE_SIZE =", _SC_PAGE_SIZE);
#else
	printf("no symbol for _SC_PAGE_SIZE\n");
#endif
#ifdef RE_DUP_MAX
	printf("RE_DUP_MAX defined to be %ld\n", (long)RE_DUP_MAX+0);
#else
	printf("no symbol for RE_DUP_MAX\n");
#endif
#ifdef _SC_RE_DUP_MAX
	pr_sysconf("RE_DUP_MAX =", _SC_RE_DUP_MAX);
#else
	printf("no symbol for _SC_RE_DUP_MAX\n");
#endif
#ifdef RTSIG_MAX
	printf("RTSIG_MAX defined to be %ld\n", (long)RTSIG_MAX+0);
#else
	printf("no symbol for RTSIG_MAX\n");
#endif
#ifdef _SC_RTSIG_MAX
	pr_sysconf("RTSIG_MAX =", _SC_RTSIG_MAX);
#else
	printf("no symbol for _SC_RTSIG_MAX\n");
#endif
#ifdef SEM_NSEMS_MAX
	printf("SEM_NSEMS_MAX defined to be %ld\n", (long)SEM_NSEMS_MAX+0);
#else
	printf("no symbol for SEM_NSEMS_MAX\n");
#endif
#ifdef _SC_SEM_NSEMS_MAX
	pr_sysconf("SEM_NSEMS_MAX =", _SC_SEM_NSEMS_MAX);
#else
	printf("no symbol for _SC_SEM_NSEMS_MAX\n");
#endif
#ifdef SEM_VALUE_MAX
	printf("SEM_VALUE_MAX defined to be %ld\n", (long)SEM_VALUE_MAX+0);
#else
	printf("no symbol for SEM_VALUE_MAX\n");
#endif
#ifdef _SC_SEM_VALUE_MAX
	pr_sysconf("SEM_VALUE_MAX =", _SC_SEM_VALUE_MAX);
#else
	printf("no symbol for _SC_SEM_VALUE_MAX\n");
#endif
#ifdef SIGQUEUE_MAX
	printf("SIGQUEUE_MAX defined to be %ld\n", (long)SIGQUEUE_MAX+0);
#else
	printf("no symbol for SIGQUEUE_MAX\n");
#endif
#ifdef _SC_SIGQUEUE_MAX
	pr_sysconf("SIGQUEUE_MAX =", _SC_SIGQUEUE_MAX);
#else
	printf("no symbol for _SC_SIGQUEUE_MAX\n");
#endif
#ifdef STREAM_MAX
	printf("STREAM_MAX defined to be %ld\n", (long)STREAM_MAX+0);
#else
	printf("no symbol for STREAM_MAX\n");
#endif
#ifdef _SC_STREAM_MAX
	pr_sysconf("STREAM_MAX =", _SC_STREAM_MAX);
#else
	printf("no symbol for _SC_STREAM_MAX\n");
#endif
#ifdef SYMLOOP_MAX
	printf("SYMLOOP_MAX defined to be %ld\n", (long)SYMLOOP_MAX+0);
#else
	printf("no symbol for SYMLOOP_MAX\n");
#endif
#ifdef _SC_SYMLOOP_MAX
	pr_sysconf("SYMLOOP_MAX =", _SC_SYMLOOP_MAX);
#else
	printf("no symbol for _SC_SYMLOOP_MAX\n");
#endif
#ifdef TIMER_MAX
	printf("TIMER_MAX defined to be %ld\n", (long)TIMER_MAX+0);
#else
	printf("no symbol for TIMER_MAX\n");
#endif
#ifdef _SC_TIMER_MAX
	pr_sysconf("TIMER_MAX =", _SC_TIMER_MAX);
#else
	printf("no symbol for _SC_TIMER_MAX\n");
#endif
#ifdef TTY_NAME_MAX
	printf("TTY_NAME_MAX defined to be %ld\n", (long)TTY_NAME_MAX+0);
#else
	printf("no symbol for TTY_NAME_MAX\n");
#endif
#ifdef _SC_TTY_NAME_MAX
	pr_sysconf("TTY_NAME_MAX =", _SC_TTY_NAME_MAX);
#else
	printf("no symbol for _SC_TTY_NAME_MAX\n");
#endif
#ifdef TZNAME_MAX
	printf("TZNAME_MAX defined to be %ld\n", (long)TZNAME_MAX+0);
#else
	printf("no symbol for TZNAME_MAX\n");
#endif
#ifdef _SC_TZNAME_MAX
	pr_sysconf("TZNAME_MAX =", _SC_TZNAME_MAX);
#else
	printf("no symbol for _SC_TZNAME_MAX\n");
#endif
#ifdef FILESIZEBITS
	printf("FILESIZEBITS defined to be %ld\n", (long)FILESIZEBITS+0);
#else
	printf("no symbol for FILESIZEBITS\n");
#endif
#ifdef _PC_FILESIZEBITS
	pr_pathconf("FILESIZEBITS =", argv[1], _PC_FILESIZEBITS);
#else
	printf("no symbol for _PC_FILESIZEBITS\n");
#endif
#ifdef LINK_MAX
	printf("LINK_MAX defined to be %ld\n", (long)LINK_MAX+0);
#else
	printf("no symbol for LINK_MAX\n");
#endif
#ifdef _PC_LINK_MAX
	pr_pathconf("LINK_MAX =", argv[1], _PC_LINK_MAX);
#else
	printf("no symbol for _PC_LINK_MAX\n");
#endif
#ifdef MAX_CANON
	printf("MAX_CANON defined to be %ld\n", (long)MAX_CANON+0);
#else
	printf("no symbol for MAX_CANON\n");
#endif
#ifdef _PC_MAX_CANON
	pr_pathconf("MAX_CANON =", argv[1], _PC_MAX_CANON);
#else
	printf("no symbol for _PC_MAX_CANON\n");
#endif
#ifdef MAX_INPUT
	printf("MAX_INPUT defined to be %ld\n", (long)MAX_INPUT+0);
#else
	printf("no symbol for MAX_INPUT\n");
#endif
#ifdef _PC_MAX_INPUT
	pr_pathconf("MAX_INPUT =", argv[1], _PC_MAX_INPUT);
#else
	printf("no symbol for _PC_MAX_INPUT\n");
#endif
#ifdef NAME_MAX
	printf("NAME_MAX defined to be %ld\n", (long)NAME_MAX+0);
#else
	printf("no symbol for NAME_MAX\n");
#endif
#ifdef _PC_NAME_MAX
	pr_pathconf("NAME_MAX =", argv[1], _PC_NAME_MAX);
#else
	printf("no symbol for _PC_NAME_MAX\n");
#endif
#ifdef PATH_MAX
	printf("PATH_MAX defined to be %ld\n", (long)PATH_MAX+0);
#else
	printf("no symbol for PATH_MAX\n");
#endif
#ifdef _PC_PATH_MAX
	pr_pathconf("PATH_MAX =", argv[1], _PC_PATH_MAX);
#else
	printf("no symbol for _PC_PATH_MAX\n");
#endif
#ifdef PIPE_BUF
	printf("PIPE_BUF defined to be %ld\n", (long)PIPE_BUF+0);
#else
	printf("no symbol for PIPE_BUF\n");
#endif
#ifdef _PC_PIPE_BUF
	pr_pathconf("PIPE_BUF =", argv[1], _PC_PIPE_BUF);
#else
	printf("no symbol for _PC_PIPE_BUF\n");
#endif
#ifdef SYMLINK_MAX
	printf("SYMLINK_MAX defined to be %ld\n", (long)SYMLINK_MAX+0);
#else
	printf("no symbol for SYMLINK_MAX\n");
#endif
#ifdef _PC_SYMLINK_MAX
	pr_pathconf("SYMLINK_MAX =", argv[1], _PC_SYMLINK_MAX);
#else
	printf("no symbol for _PC_SYMLINK_MAX\n");
#endif
#ifdef _POSIX_TIMESTAMP_RESOLUTION
	printf("_POSIX_TIMESTAMP_RESOLUTION defined to be %ld\n", (long)_POSIX_TIMESTAMP_RESOLUTION+0);
#else
	printf("no symbol for _POSIX_TIMESTAMP_RESOLUTION\n");
#endif
#ifdef _PC_TIMESTAMP_RESOLUTION
	pr_pathconf("_POSIX_TIMESTAMP_RESOLUTION =", argv[1], _PC_TIMESTAMP_RESOLUTION);
#else
	printf("no symbol for _PC_TIMESTAMP_RESOLUTION\n");
#endif
	exit(0);
}

static void
pr_sysconf(char *mesg, int name)
{
	long	val;

	fputs(mesg, stdout);
	errno = 0;
	if ((val = sysconf(name)) < 0) {
		if (errno != 0) {
			if (errno == EINVAL)
				fputs(" (not supported)\n", stdout);
			else
				err_sys("sysconf error");
		} else {
			fputs(" (no limit)\n", stdout);
		}
	} else {
		printf(" %ld\n", val);
	}
}

static void
pr_pathconf(char *mesg, char *path, int name)
{
	long	val;

	fputs(mesg, stdout);
	errno = 0;
	if ((val = pathconf(path, name)) < 0) {
		if (errno != 0) {
			if (errno == EINVAL)
				fputs(" (not supported)\n", stdout);
			else
				err_sys("pathconf error, path = %s", path);
		} else {
			fputs(" (no limit)\n", stdout);
		}
	} else {
		printf(" %ld\n", val);
	}
}
