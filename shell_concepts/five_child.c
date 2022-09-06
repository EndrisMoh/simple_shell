#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int child, child1, child2, child3;
	int status;

	printf("I am the parent(1st process) and my PID is: %d\n\n", getpid());
	child = fork();
	if (child == 0)
	{
		printf("I am the first child(2nd process) and my PID is: %d\n", getpid());
		printf("My PPID is: %d\n\n", getppid());
	}
	else
	{
		wait(&status);
		child1 = fork();
		if (child1 == 0)
		{
		printf("I am the second child(3rd process) and my PID is: %d\n", getpid());
		printf("My PPID is: %d\n\n", getppid());
		}
		else
		{
			wait(&status);
			child2 = fork();
			if (child2 == 0)
			{
				printf("I am the third child(4th process) and my PID is: %d\n", getpid());
				printf("My PPID is: %d\n\n", getppid());
			}
			else
			{
				wait(&status);
				child3 = fork();
				if (child3 == 0)
				{
					printf("I am the 4th child(5th process and my PID is: %d\n", getpid());
					printf("My PPID is: %d\n\n", getppid());
				}
				else
				wait(NULL);
			}
		}
	}

	return (0);
}