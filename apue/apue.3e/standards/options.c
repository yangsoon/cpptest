#include "apue.h"
#include <errno.h>

static void	pr_sysconf(char *, int);
static void	pr_pathconf(char *, char *, int);

int
main(int argc, char *argv[])
{
	if (argc != 2)
		err_quit("usage: a.out <dirname>");

#ifdef _POSIX_ADVISORY_INFO
	printf("_POSIX_ADVISORY_INFO is defined (val is %ld)\n", (long)_POSIX_ADVISORY_INFO+0);
#else
	printf("_POSIX_ADVISORY_INFO is undefined\n");
#endif
#ifdef _SC_ADVISORY_INFO
	pr_sysconf("sysconf says _POSIX_ADVISORY_INFO =", _SC_ADVISORY_INFO);
#else
	printf("no symbol for _POSIX_ADVISORY_INFO\n");
#endif
	printf("\n");
#ifdef _POSIX_ASYNCHRONOUS_IO
	printf("_POSIX_ASYNCHRONOUS_IO is defined (val is %ld)\n", (long)_POSIX_ASYNCHRONOUS_IO+0);
#else
	printf("_POSIX_ASYNCHRONOUS_IO is undefined\n");
#endif
#ifdef _SC_ASYNCHRONOUS_IO
	pr_sysconf("sysconf says _POSIX_ASYNCHRONOUS_IO =", _SC_ASYNCHRONOUS_IO);
#else
	printf("no symbol for _POSIX_ASYNCHRONOUS_IO\n");
#endif
	printf("\n");
#ifdef _POSIX_BARRIERS
	printf("_POSIX_BARRIERS is defined (val is %ld)\n", (long)_POSIX_BARRIERS+0);
#else
	printf("_POSIX_BARRIERS is undefined\n");
#endif
#ifdef _SC_BARRIERS
	pr_sysconf("sysconf says _POSIX_BARRIERS =", _SC_BARRIERS);
#else
	printf("no symbol for _POSIX_BARRIERS\n");
#endif
	printf("\n");
#ifdef _POSIX_CLOCK_SELECTION
	printf("_POSIX_CLOCK_SELECTION is defined (val is %ld)\n", (long)_POSIX_CLOCK_SELECTION+0);
#else
	printf("_POSIX_CLOCK_SELECTION is undefined\n");
#endif
#ifdef _SC_CLOCK_SELECTION
	pr_sysconf("sysconf says _POSIX_CLOCK_SELECTION =", _SC_CLOCK_SELECTION);
#else
	printf("no symbol for _POSIX_CLOCK_SELECTION\n");
#endif
	printf("\n");
#ifdef _POSIX_CPUTIME
	printf("_POSIX_CPUTIME is defined (val is %ld)\n", (long)_POSIX_CPUTIME+0);
#else
	printf("_POSIX_CPUTIME is undefined\n");
#endif
#ifdef _SC_CPUTIME
	pr_sysconf("sysconf says _POSIX_CPUTIME =", _SC_CPUTIME);
#else
	printf("no symbol for _POSIX_CPUTIME\n");
#endif
	printf("\n");
#ifdef _POSIX_FSYNC
	printf("_POSIX_FSYNC is defined (val is %ld)\n", (long)_POSIX_FSYNC+0);
#else
	printf("_POSIX_FSYNC is undefined\n");
#endif
#ifdef _SC_FSYNC
	pr_sysconf("sysconf says _POSIX_FSYNC =", _SC_FSYNC);
#else
	printf("no symbol for _POSIX_FSYNC\n");
#endif
	printf("\n");
#ifdef _POSIX_IPV6
	printf("_POSIX_IPV6 is defined (val is %ld)\n", (long)_POSIX_IPV6+0);
#else
	printf("_POSIX_IPV6 is undefined\n");
#endif
#ifdef _SC_IPV6
	pr_sysconf("sysconf says _POSIX_IPV6 =", _SC_IPV6);
#else
	printf("no symbol for _POSIX_IPV6\n");
#endif
	printf("\n");
#ifdef _POSIX_JOB_CONTROL
	printf("_POSIX_JOB_CONTROL is defined (val is %ld)\n", (long)_POSIX_JOB_CONTROL+0);
#else
	printf("_POSIX_JOB_CONTROL is undefined\n");
#endif
#ifdef _SC_JOB_CONTROL
	pr_sysconf("sysconf says _POSIX_JOB_CONTROL =", _SC_JOB_CONTROL);
#else
	printf("no symbol for _POSIX_JOB_CONTROL\n");
#endif
	printf("\n");
#ifdef _POSIX_MAPPED_FILES
	printf("_POSIX_MAPPED_FILES is defined (val is %ld)\n", (long)_POSIX_MAPPED_FILES+0);
#else
	printf("_POSIX_MAPPED_FILES is undefined\n");
#endif
#ifdef _SC_MAPPED_FILES
	pr_sysconf("sysconf says _POSIX_MAPPED_FILES =", _SC_MAPPED_FILES);
#else
	printf("no symbol for _POSIX_MAPPED_FILES\n");
#endif
	printf("\n");
#ifdef _POSIX_MEMLOCK
	printf("_POSIX_MEMLOCK is defined (val is %ld)\n", (long)_POSIX_MEMLOCK+0);
#else
	printf("_POSIX_MEMLOCK is undefined\n");
#endif
#ifdef _SC_MEMLOCK
	pr_sysconf("sysconf says _POSIX_MEMLOCK =", _SC_MEMLOCK);
#else
	printf("no symbol for _POSIX_MEMLOCK\n");
#endif
	printf("\n");
#ifdef _POSIX_MEMLOCK_RANGE
	printf("_POSIX_MEMLOCK_RANGE is defined (val is %ld)\n", (long)_POSIX_MEMLOCK_RANGE+0);
#else
	printf("_POSIX_MEMLOCK_RANGE is undefined\n");
#endif
#ifdef _SC_MEMLOCK_RANGE
	pr_sysconf("sysconf says _POSIX_MEMLOCK_RANGE =", _SC_MEMLOCK_RANGE);
#else
	printf("no symbol for _POSIX_MEMLOCK_RANGE\n");
#endif
	printf("\n");
#ifdef _POSIX_MEMORY_PROTECTION
	printf("_POSIX_MEMORY_PROTECTION is defined (val is %ld)\n", (long)_POSIX_MEMORY_PROTECTION+0);
#else
	printf("_POSIX_MEMORY_PROTECTION is undefined\n");
#endif
#ifdef _SC_MEMORY_PROTECTION
	pr_sysconf("sysconf says _POSIX_MEMORY_PROTECTION =", _SC_MEMORY_PROTECTION);
#else
	printf("no symbol for _POSIX_MEMORY_PROTECTION\n");
#endif
	printf("\n");
#ifdef _POSIX_MESSAGE_PASSING
	printf("_POSIX_MESSAGE_PASSING is defined (val is %ld)\n", (long)_POSIX_MESSAGE_PASSING+0);
#else
	printf("_POSIX_MESSAGE_PASSING is undefined\n");
#endif
#ifdef _SC_MESSAGE_PASSING
	pr_sysconf("sysconf says _POSIX_MESSAGE_PASSING =", _SC_MESSAGE_PASSING);
#else
	printf("no symbol for _POSIX_MESSAGE_PASSING\n");
#endif
	printf("\n");
#ifdef _POSIX_MONOTONIC_CLOCK
	printf("_POSIX_MONOTONIC_CLOCK is defined (val is %ld)\n", (long)_POSIX_MONOTONIC_CLOCK+0);
#else
	printf("_POSIX_MONOTONIC_CLOCK is undefined\n");
#endif
#ifdef _SC_MONOTONIC_CLOCK
	pr_sysconf("sysconf says _POSIX_MONOTONIC_CLOCK =", _SC_MONOTONIC_CLOCK);
#else
	printf("no symbol for _POSIX_MONOTONIC_CLOCK\n");
#endif
	printf("\n");
#ifdef _POSIX_PRIORITIZED_IO
	printf("_POSIX_PRIORITIZED_IO is defined (val is %ld)\n", (long)_POSIX_PRIORITIZED_IO+0);
#else
	printf("_POSIX_PRIORITIZED_IO is undefined\n");
#endif
#ifdef _SC_PRIORITIZED_IO
	pr_sysconf("sysconf says _POSIX_PRIORITIZED_IO =", _SC_PRIORITIZED_IO);
#else
	printf("no symbol for _POSIX_PRIORITIZED_IO\n");
#endif
	printf("\n");
#ifdef _POSIX_PRIORITY_SCHEDULING
	printf("_POSIX_PRIORITY_SCHEDULING is defined (val is %ld)\n", (long)_POSIX_PRIORITY_SCHEDULING+0);
#else
	printf("_POSIX_PRIORITY_SCHEDULING is undefined\n");
#endif
#ifdef _SC_PRIORITY_SCHEDULING
	pr_sysconf("sysconf says _POSIX_PRIORITY_SCHEDULING =", _SC_PRIORITY_SCHEDULING);
#else
	printf("no symbol for _POSIX_PRIORITY_SCHEDULING\n");
#endif
	printf("\n");
#ifdef _POSIX_RAW_SOCKETS
	printf("_POSIX_RAW_SOCKETS is defined (val is %ld)\n", (long)_POSIX_RAW_SOCKETS+0);
#else
	printf("_POSIX_RAW_SOCKETS is undefined\n");
#endif
#ifdef _SC_RAW_SOCKETS
	pr_sysconf("sysconf says _POSIX_RAW_SOCKETS =", _SC_RAW_SOCKETS);
#else
	printf("no symbol for _POSIX_RAW_SOCKETS\n");
#endif
	printf("\n");
#ifdef _POSIX_READER_WRITER_LOCKS
	printf("_POSIX_READER_WRITER_LOCKS is defined (val is %ld)\n", (long)_POSIX_READER_WRITER_LOCKS+0);
#else
	printf("_POSIX_READER_WRITER_LOCKS is undefined\n");
#endif
#ifdef _SC_READER_WRITER_LOCKS
	pr_sysconf("sysconf says _POSIX_READER_WRITER_LOCKS =", _SC_READER_WRITER_LOCKS);
#else
	printf("no symbol for _POSIX_READER_WRITER_LOCKS\n");
#endif
	printf("\n");
#ifdef _POSIX_REALTIME_SIGNALS
	printf("_POSIX_REALTIME_SIGNALS is defined (val is %ld)\n", (long)_POSIX_REALTIME_SIGNALS+0);
#else
	printf("_POSIX_REALTIME_SIGNALS is undefined\n");
#endif
#ifdef _SC_REALTIME_SIGNALS
	pr_sysconf("sysconf says _POSIX_REALTIME_SIGNALS =", _SC_REALTIME_SIGNALS);
#else
	printf("no symbol for _POSIX_REALTIME_SIGNALS\n");
#endif
	printf("\n");
#ifdef _POSIX_REGEXP
	printf("_POSIX_REGEXP is defined (val is %ld)\n", (long)_POSIX_REGEXP+0);
#else
	printf("_POSIX_REGEXP is undefined\n");
#endif
#ifdef _SC_REGEXP
	pr_sysconf("sysconf says _POSIX_REGEXP =", _SC_REGEXP);
#else
	printf("no symbol for _POSIX_REGEXP\n");
#endif
	printf("\n");
#ifdef _POSIX_SAVED_IDS
	printf("_POSIX_SAVED_IDS is defined (val is %ld)\n", (long)_POSIX_SAVED_IDS+0);
#else
	printf("_POSIX_SAVED_IDS is undefined\n");
#endif
#ifdef _SC_SAVED_IDS
	pr_sysconf("sysconf says _POSIX_SAVED_IDS =", _SC_SAVED_IDS);
#else
	printf("no symbol for _POSIX_SAVED_IDS\n");
#endif
	printf("\n");
#ifdef _POSIX_SEMAPHORES
	printf("_POSIX_SEMAPHORES is defined (val is %ld)\n", (long)_POSIX_SEMAPHORES+0);
#else
	printf("_POSIX_SEMAPHORES is undefined\n");
#endif
#ifdef _SC_SEMAPHORES
	pr_sysconf("sysconf says _POSIX_SEMAPHORES =", _SC_SEMAPHORES);
#else
	printf("no symbol for _POSIX_SEMAPHORES\n");
#endif
	printf("\n");
#ifdef _POSIX_SHARED_MEMORY_OBJECTS
	printf("_POSIX_SHARED_MEMORY_OBJECTS is defined (val is %ld)\n", (long)_POSIX_SHARED_MEMORY_OBJECTS+0);
#else
	printf("_POSIX_SHARED_MEMORY_OBJECTS is undefined\n");
#endif
#ifdef _SC_SHARED_MEMORY_OBJECTS
	pr_sysconf("sysconf says _POSIX_SHARED_MEMORY_OBJECTS =", _SC_SHARED_MEMORY_OBJECTS);
#else
	printf("no symbol for _POSIX_SHARED_MEMORY_OBJECTS\n");
#endif
	printf("\n");
#ifdef _POSIX_SHELL
	printf("_POSIX_SHELL is defined (val is %ld)\n", (long)_POSIX_SHELL+0);
#else
	printf("_POSIX_SHELL is undefined\n");
#endif
#ifdef _SC_SHELL
	pr_sysconf("sysconf says _POSIX_SHELL =", _SC_SHELL);
#else
	printf("no symbol for _POSIX_SHELL\n");
#endif
	printf("\n");
#ifdef _POSIX_SPAWN
	printf("_POSIX_SPAWN is defined (val is %ld)\n", (long)_POSIX_SPAWN+0);
#else
	printf("_POSIX_SPAWN is undefined\n");
#endif
#ifdef _SC_SPAWN
	pr_sysconf("sysconf says _POSIX_SPAWN =", _SC_SPAWN);
#else
	printf("no symbol for _POSIX_SPAWN\n");
#endif
	printf("\n");
#ifdef _POSIX_SPIN_LOCKS
	printf("_POSIX_SPIN_LOCKS is defined (val is %ld)\n", (long)_POSIX_SPIN_LOCKS+0);
#else
	printf("_POSIX_SPIN_LOCKS is undefined\n");
#endif
#ifdef _SC_SPIN_LOCKS
	pr_sysconf("sysconf says _POSIX_SPIN_LOCKS =", _SC_SPIN_LOCKS);
#else
	printf("no symbol for _POSIX_SPIN_LOCKS\n");
#endif
	printf("\n");
#ifdef _POSIX_SPORADIC_SERVER
	printf("_POSIX_SPORADIC_SERVER is defined (val is %ld)\n", (long)_POSIX_SPORADIC_SERVER+0);
#else
	printf("_POSIX_SPORADIC_SERVER is undefined\n");
#endif
#ifdef _SC_SPORADIC_SERVER
	pr_sysconf("sysconf says _POSIX_SPORADIC_SERVER =", _SC_SPORADIC_SERVER);
#else
	printf("no symbol for _POSIX_SPORADIC_SERVER\n");
#endif
	printf("\n");
#ifdef _POSIX_SYNCHRONIZED_IO
	printf("_POSIX_SYNCHRONIZED_IO is defined (val is %ld)\n", (long)_POSIX_SYNCHRONIZED_IO+0);
#else
	printf("_POSIX_SYNCHRONIZED_IO is undefined\n");
#endif
#ifdef _SC_SYNCHRONIZED_IO
	pr_sysconf("sysconf says _POSIX_SYNCHRONIZED_IO =", _SC_SYNCHRONIZED_IO);
#else
	printf("no symbol for _POSIX_SYNCHRONIZED_IO\n");
#endif
	printf("\n");
#ifdef _POSIX_THREAD_ATTR_STACKADDR
	printf("_POSIX_THREAD_ATTR_STACKADDR is defined (val is %ld)\n", (long)_POSIX_THREAD_ATTR_STACKADDR+0);
#else
	printf("_POSIX_THREAD_ATTR_STACKADDR is undefined\n");
#endif
#ifdef _SC_THREAD_ATTR_STACKADDR
	pr_sysconf("sysconf says _POSIX_THREAD_ATTR_STACKADDR =", _SC_THREAD_ATTR_STACKADDR);
#else
	printf("no symbol for _POSIX_THREAD_ATTR_STACKADDR\n");
#endif
	printf("\n");
#ifdef _POSIX_THREAD_ATTR_STACKSIZE
	printf("_POSIX_THREAD_ATTR_STACKSIZE is defined (val is %ld)\n", (long)_POSIX_THREAD_ATTR_STACKSIZE+0);
#else
	printf("_POSIX_THREAD_ATTR_STACKSIZE is undefined\n");
#endif
#ifdef _SC_THREAD_ATTR_STACKSIZE
	pr_sysconf("sysconf says _POSIX_THREAD_ATTR_STACKSIZE =", _SC_THREAD_ATTR_STACKSIZE);
#else
	printf("no symbol for _POSIX_THREAD_ATTR_STACKSIZE\n");
#endif
	printf("\n");
#ifdef _POSIX_THREAD_ATTR_CPUTIME
	printf("_POSIX_THREAD_ATTR_CPUTIME is defined (val is %ld)\n", (long)_POSIX_THREAD_ATTR_CPUTIME+0);
#else
	printf("_POSIX_THREAD_ATTR_CPUTIME is undefined\n");
#endif
#ifdef _SC_THREAD_CPUTIME
	pr_sysconf("sysconf says _POSIX_THREAD_ATTR_CPUTIME =", _SC_THREAD_CPUTIME);
#else
	printf("no symbol for _POSIX_THREAD_ATTR_CPUTIME\n");
#endif
	printf("\n");
#ifdef _POSIX_THREAD_PRIO_INHERIT
	printf("_POSIX_THREAD_PRIO_INHERIT is defined (val is %ld)\n", (long)_POSIX_THREAD_PRIO_INHERIT+0);
#else
	printf("_POSIX_THREAD_PRIO_INHERIT is undefined\n");
#endif
#ifdef _SC_THREAD_PRIO_INHERIT
	pr_sysconf("sysconf says _POSIX_THREAD_PRIO_INHERIT =", _SC_THREAD_PRIO_INHERIT);
#else
	printf("no symbol for _POSIX_THREAD_PRIO_INHERIT\n");
#endif
	printf("\n");
#ifdef _POSIX_THREAD_PRIORITY_SCHEDULING
	printf("_POSIX_THREAD_PRIORITY_SCHEDULING is defined (val is %ld)\n", (long)_POSIX_THREAD_PRIORITY_SCHEDULING+0);
#else
	printf("_POSIX_THREAD_PRIORITY_SCHEDULING is undefined\n");
#endif
#ifdef _SC_THREAD_PRIORITY_SCHEDULING
	pr_sysconf("sysconf says _POSIX_THREAD_PRIORITY_SCHEDULING =", _SC_THREAD_PRIORITY_SCHEDULING);
#else
	printf("no symbol for _POSIX_THREAD_PRIORITY_SCHEDULING\n");
#endif
	printf("\n");
#ifdef _POSIX_THREAD_PROCESS_SHARED
	printf("_POSIX_THREAD_PROCESS_SHARED is defined (val is %ld)\n", (long)_POSIX_THREAD_PROCESS_SHARED+0);
#else
	printf("_POSIX_THREAD_PROCESS_SHARED is undefined\n");
#endif
#ifdef _SC_THREAD_PROCESS_SHARED
	pr_sysconf("sysconf says _POSIX_THREAD_PROCESS_SHARED =", _SC_THREAD_PROCESS_SHARED);
#else
	printf("no symbol for _POSIX_THREAD_PROCESS_SHARED\n");
#endif
	printf("\n");
#ifdef _POSIX_THREAD_ROBUST_PRIO_INHERIT
	printf("_POSIX_THREAD_ROBUST_PRIO_INHERIT is defined (val is %ld)\n", (long)_POSIX_THREAD_ROBUST_PRIO_INHERIT+0);
#else
	printf("_POSIX_THREAD_ROBUST_PRIO_INHERIT is undefined\n");
#endif
#ifdef _SC_THREAD_ROBUST_PRIO_INHERIT
	pr_sysconf("sysconf says _POSIX_THREAD_ROBUST_PRIO_INHERIT =", _SC_THREAD_ROBUST_PRIO_INHERIT);
#else
	printf("no symbol for _POSIX_THREAD_ROBUST_PRIO_INHERIT\n");
#endif
	printf("\n");
#ifdef _POSIX_THREAD_ROBUST_PRIO_PROTECT
	printf("_POSIX_THREAD_ROBUST_PRIO_PROTECT is defined (val is %ld)\n", (long)_POSIX_THREAD_ROBUST_PRIO_PROTECT+0);
#else
	printf("_POSIX_THREAD_ROBUST_PRIO_PROTECT is undefined\n");
#endif
#ifdef _SC_THREAD_ROBUST_PRIO_PROTECT
	pr_sysconf("sysconf says _POSIX_THREAD_ROBUST_PRIO_PROTECT =", _SC_THREAD_ROBUST_PRIO_PROTECT);
#else
	printf("no symbol for _POSIX_THREAD_ROBUST_PRIO_PROTECT\n");
#endif
	printf("\n");
#ifdef _POSIX_THREAD_SAFE_FUNCTIONS
	printf("_POSIX_THREAD_SAFE_FUNCTIONS is defined (val is %ld)\n", (long)_POSIX_THREAD_SAFE_FUNCTIONS+0);
#else
	printf("_POSIX_THREAD_SAFE_FUNCTIONS is undefined\n");
#endif
#ifdef _SC_THREAD_SAFE_FUNCTIONS
	pr_sysconf("sysconf says _POSIX_THREAD_SAFE_FUNCTIONS =", _SC_THREAD_SAFE_FUNCTIONS);
#else
	printf("no symbol for _POSIX_THREAD_SAFE_FUNCTIONS\n");
#endif
	printf("\n");
#ifdef _POSIX_THREAD_SPORADIC_SERVER
	printf("_POSIX_THREAD_SPORADIC_SERVER is defined (val is %ld)\n", (long)_POSIX_THREAD_SPORADIC_SERVER+0);
#else
	printf("_POSIX_THREAD_SPORADIC_SERVER is undefined\n");
#endif
#ifdef _SC_THREAD_SPORADIC_SERVER
	pr_sysconf("sysconf says _POSIX_THREAD_SPORADIC_SERVER =", _SC_THREAD_SPORADIC_SERVER);
#else
	printf("no symbol for _POSIX_THREAD_SPORADIC_SERVER\n");
#endif
	printf("\n");
#ifdef _POSIX_THREADS
	printf("_POSIX_THREADS is defined (val is %ld)\n", (long)_POSIX_THREADS+0);
#else
	printf("_POSIX_THREADS is undefined\n");
#endif
#ifdef _SC_THREADS
	pr_sysconf("sysconf says _POSIX_THREADS =", _SC_THREADS);
#else
	printf("no symbol for _POSIX_THREADS\n");
#endif
	printf("\n");
#ifdef _POSIX_TIMEOUTS
	printf("_POSIX_TIMEOUTS is defined (val is %ld)\n", (long)_POSIX_TIMEOUTS+0);
#else
	printf("_POSIX_TIMEOUTS is undefined\n");
#endif
#ifdef _SC_TIMEOUTS
	pr_sysconf("sysconf says _POSIX_TIMEOUTS =", _SC_TIMEOUTS);
#else
	printf("no symbol for _POSIX_TIMEOUTS\n");
#endif
	printf("\n");
#ifdef _POSIX_TIMERS
	printf("_POSIX_TIMERS is defined (val is %ld)\n", (long)_POSIX_TIMERS+0);
#else
	printf("_POSIX_TIMERS is undefined\n");
#endif
#ifdef _SC_TIMERS
	pr_sysconf("sysconf says _POSIX_TIMERS =", _SC_TIMERS);
#else
	printf("no symbol for _POSIX_TIMERS\n");
#endif
	printf("\n");
#ifdef _POSIX_TYPED_MEMORY_OBJECTS
	printf("_POSIX_TYPED_MEMORY_OBJECTS is defined (val is %ld)\n", (long)_POSIX_TYPED_MEMORY_OBJECTS+0);
#else
	printf("_POSIX_TYPED_MEMORY_OBJECTS is undefined\n");
#endif
#ifdef _SC_TYPED_MEMORY_OBJECTS
	pr_sysconf("sysconf says _POSIX_TYPED_MEMORY_OBJECTS =", _SC_TYPED_MEMORY_OBJECTS);
#else
	printf("no symbol for _POSIX_TYPED_MEMORY_OBJECTS\n");
#endif
	printf("\n");
#ifdef _POSIX_VERSION
	printf("_POSIX_VERSION is defined (val is %ld)\n", (long)_POSIX_VERSION+0);
#else
	printf("_POSIX_VERSION is undefined\n");
#endif
#ifdef _SC_VERSION
	pr_sysconf("sysconf says _POSIX_VERSION =", _SC_VERSION);
#else
	printf("no symbol for _POSIX_VERSION\n");
#endif
	printf("\n");
#ifdef _XOPEN_CRYPT
	printf("_XOPEN_CRYPT is defined (val is %ld)\n", (long)_XOPEN_CRYPT+0);
#else
	printf("_XOPEN_CRYPT is undefined\n");
#endif
#ifdef _SC_XOPEN_CRYPT
	pr_sysconf("sysconf says _XOPEN_CRYPT =", _SC_XOPEN_CRYPT);
#else
	printf("no symbol for _XOPEN_CRYPT\n");
#endif
	printf("\n");
#ifdef _XOPEN_ENH_I18N
	printf("_XOPEN_ENH_I18N is defined (val is %ld)\n", (long)_XOPEN_ENH_I18N+0);
#else
	printf("_XOPEN_ENH_I18N is undefined\n");
#endif
#ifdef _SC_XOPEN_ENH_I18N
	pr_sysconf("sysconf says _XOPEN_ENH_I18N =", _SC_XOPEN_ENH_I18N);
#else
	printf("no symbol for _XOPEN_ENH_I18N\n");
#endif
	printf("\n");
#ifdef _XOPEN_REALTIME
	printf("_XOPEN_REALTIME is defined (val is %ld)\n", (long)_XOPEN_REALTIME+0);
#else
	printf("_XOPEN_REALTIME is undefined\n");
#endif
#ifdef _SC_XOPEN_REALTIME
	pr_sysconf("sysconf says _XOPEN_REALTIME =", _SC_XOPEN_REALTIME);
#else
	printf("no symbol for _XOPEN_REALTIME\n");
#endif
	printf("\n");
#ifdef _XOPEN_REALTIME_THREADS
	printf("_XOPEN_REALTIME_THREADS is defined (val is %ld)\n", (long)_XOPEN_REALTIME_THREADS+0);
#else
	printf("_XOPEN_REALTIME_THREADS is undefined\n");
#endif
#ifdef _SC_XOPEN_REALTIME_THREADS
	pr_sysconf("sysconf says _XOPEN_REALTIME_THREADS =", _SC_XOPEN_REALTIME_THREADS);
#else
	printf("no symbol for _XOPEN_REALTIME_THREADS\n");
#endif
	printf("\n");
#ifdef _XOPEN_SHM
	printf("_XOPEN_SHM is defined (val is %ld)\n", (long)_XOPEN_SHM+0);
#else
	printf("_XOPEN_SHM is undefined\n");
#endif
#ifdef _SC_XOPEN_SHM
	pr_sysconf("sysconf says _XOPEN_SHM =", _SC_XOPEN_SHM);
#else
	printf("no symbol for _XOPEN_SHM\n");
#endif
	printf("\n");
#ifdef _XOPEN_UNIX
	printf("_XOPEN_UNIX is defined (val is %ld)\n", (long)_XOPEN_UNIX+0);
#else
	printf("_XOPEN_UNIX is undefined\n");
#endif
#ifdef _SC_XOPEN_UNIX
	pr_sysconf("sysconf says _XOPEN_UNIX =", _SC_XOPEN_UNIX);
#else
	printf("no symbol for _XOPEN_UNIX\n");
#endif
	printf("\n");
#ifdef _XOPEN_UUCP
	printf("_XOPEN_UUCP is defined (val is %ld)\n", (long)_XOPEN_UUCP+0);
#else
	printf("_XOPEN_UUCP is undefined\n");
#endif
#ifdef _SC_XOPEN_UUCP
	pr_sysconf("sysconf says _XOPEN_UUCP =", _SC_XOPEN_UUCP);
#else
	printf("no symbol for _XOPEN_UUCP\n");
#endif
	printf("\n");
#ifdef _XOPEN_VERSION
	printf("_XOPEN_VERSION is defined (val is %ld)\n", (long)_XOPEN_VERSION+0);
#else
	printf("_XOPEN_VERSION is undefined\n");
#endif
#ifdef _SC_XOPEN_VERSION
	pr_sysconf("sysconf says _XOPEN_VERSION =", _SC_XOPEN_VERSION);
#else
	printf("no symbol for _XOPEN_VERSION\n");
#endif
	printf("\n");
#ifdef _POSIX_CHOWN_RESTRICTED
	printf("_POSIX_CHOWN_RESTRICTED is defined (val is %ld)\n", (long)_POSIX_CHOWN_RESTRICTED+0);
#else
	printf("_POSIX_CHOWN_RESTRICTED is undefined\n");
#endif
#ifdef _PC_CHOWN_RESTRICTED
	pr_pathconf("pathconf says _POSIX_CHOWN_RESTRICTED =", argv[1], _PC_CHOWN_RESTRICTED);
#else
	printf("no symbol for _POSIX_CHOWN_RESTRICTED\n");
#endif
	printf("\n");
#ifdef _POSIX_NO_TRUNC
	printf("_POSIX_NO_TRUNC is defined (val is %ld)\n", (long)_POSIX_NO_TRUNC+0);
#else
	printf("_POSIX_NO_TRUNC is undefined\n");
#endif
#ifdef _PC_NO_TRUNC
	pr_pathconf("pathconf says _POSIX_NO_TRUNC =", argv[1], _PC_NO_TRUNC);
#else
	printf("no symbol for _POSIX_NO_TRUNC\n");
#endif
	printf("\n");
#ifdef _POSIX_VDISABLE
	printf("_POSIX_VDISABLE is defined (val is %ld)\n", (long)_POSIX_VDISABLE+0);
#else
	printf("_POSIX_VDISABLE is undefined\n");
#endif
#ifdef _PC_VDISABLE
	pr_pathconf("pathconf says _POSIX_VDISABLE =", argv[1], _PC_VDISABLE);
#else
	printf("no symbol for _POSIX_VDISABLE\n");
#endif
	printf("\n");
#ifdef _POSIX_ASYNC_IO
	printf("_POSIX_ASYNC_IO is defined (val is %ld)\n", (long)_POSIX_ASYNC_IO+0);
#else
	printf("_POSIX_ASYNC_IO is undefined\n");
#endif
#ifdef _PC_ASYNC_IO
	pr_pathconf("pathconf says _POSIX_ASYNC_IO =", argv[1], _PC_ASYNC_IO);
#else
	printf("no symbol for _POSIX_ASYNC_IO\n");
#endif
	printf("\n");
#ifdef _POSIX_PRIO_IO
	printf("_POSIX_PRIO_IO is defined (val is %ld)\n", (long)_POSIX_PRIO_IO+0);
#else
	printf("_POSIX_PRIO_IO is undefined\n");
#endif
#ifdef _PC_PRIO_IO
	pr_pathconf("pathconf says _POSIX_PRIO_IO =", argv[1], _PC_PRIO_IO);
#else
	printf("no symbol for _POSIX_PRIO_IO\n");
#endif
	printf("\n");
#ifdef _POSIX_SYNC_IO
	printf("_POSIX_SYNC_IO is defined (val is %ld)\n", (long)_POSIX_SYNC_IO+0);
#else
	printf("_POSIX_SYNC_IO is undefined\n");
#endif
#ifdef _PC_SYNC_IO
	pr_pathconf("pathconf says _POSIX_SYNC_IO =", argv[1], _PC_SYNC_IO);
#else
	printf("no symbol for _POSIX_SYNC_IO\n");
#endif
	printf("\n");
#ifdef _POSIX2_SYMLINKS
	printf("_POSIX2_SYMLINKS is defined (val is %ld)\n", (long)_POSIX2_SYMLINKS+0);
#else
	printf("_POSIX2_SYMLINKS is undefined\n");
#endif
#ifdef _PC_2_SYMLINKS
	pr_pathconf("pathconf says _POSIX2_SYMLINKS =", argv[1], _PC_2_SYMLINKS);
#else
	printf("no symbol for _POSIX2_SYMLINKS\n");
#endif
	printf("\n");
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
