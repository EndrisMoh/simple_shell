#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * main - entry point
 *
 * Get PID, PPID and GID
 */

int main(void)
{
	pid_t pid, ppid;
	gid_t gid;

	/* get the process id */

	if ((pid = getpid()) < 0)
	{
		perror("unable to get pid\n");
	}
	else
	{
		printf("The process id is %d \n", pid);
	}

	/* get the parent process id */
	if ((ppid = getppid()) < 0)
	{
		perror("unable to get the ppid \n");
	}
	else
	{
		printf("The parent process id is %d \n", ppid);
	}

	/* get the group process id */
	if ((gid = getgid()) < 0)
	{
		perror("unable to get the group id \n");
	}
	else
	{
		printf("The group id is %d \n", gid);
	}

	return(0);
}
