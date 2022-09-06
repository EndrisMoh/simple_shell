#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#define		MAX_SIZE_CMD	256
#define		MAX_SIZE_ARG	16

/*char cmd[MAX_SIZE_CMD];  // string holder for the command
char *argv[MAX_SIZE_ARG]; // an array for command and arguments
pid_t pid;                  // global variable for the child process ID
char i;                      // global for loop counter*/

/**
 * get_cmd - get command string from the user
 *
 */
void get_cmd(void)
{
	char cmd[MAX_SIZE_CMD];

	printf("#cisfun$\t");
	fgets(cmd, MAX_SIZE_CMD, stdin);

	/* remove training newline */
	if ((strlen(cmd) > 0) && (cmd[strlen(cmd) - 1] == '\n'))
		cmd[strlen(cmd) - 1] = '\0';
		/*printf("%s\n", cmd); */
}

/**
 * convert_cmd - split string into argv
 */
void convert_cmd(void)
{
	char *ptr;
	int i = 0;
	char cmd[MAX_SIZE_CMD];
	char *argv[MAX_SIZE_ARG];

	ptr = strtok(cmd, " ");

	while (ptr != NULL)
	{
		argv[i] = ptr;
		i++;
		ptr = strtok(NULL, " ");
	}

	/* check for "&" */
	if (!strcmp("&", argv[i - 1]))
	{
		argv[i - 1] = NULL;
		argv[i] = "&";
	}
	else
	{
		argv[i] = NULL;
	}
}

/**
 * c-shell - start the shell
 */
void c_shell(void)
{
	pid_t pid;
	int i = 0;
	char cmd[MAX_SIZE_CMD];
	char *argv[MAX_SIZE_ARG];
	char **envp;

	while (1)
	{
		get_cmd();
		/*bypass empty commands */
		if (!strcmp("", cmd))
			continue;
		/*check for the "exit" command */
		if (!strcmp("exit", cmd))
			break;
		/*fit the command into *argv[] */
		convert_cmd();
		/* fork and execute the command */
		pid = fork();
		if (pid == -1)
		{
			printf("Failed to create a child\n");
		}
		else if (pid == 0)
		{
			/* execute the  command */
			execve(argv[0], argv, envp);
		}
		else
		{
			/* wait for a command to finish if "&" is not present */
			if (argv[i] == NULL)
				waitpid(pid, NULL, 0);
		}
	}
}

/**
 * log_handle - signal handle to add log statements
 */
void log_handle(int sig)
{
	FILE *pFile;

	pFile = fopen("log.txt", "a");

	if (pFile == NULL)
		perror("Error opening file.");
	else
		fprintf(pFile, "[LOG] child process terminated.\n");
	fclose(pFile);
}

/**
 * main -super smple shell
 * Return: Always 0.
 */
int main(void)
{
	/* tie the handler to the SGNCHLD signal */
	signal(SIGCHLD, log_handle);

	/* start the shell */
	c_shell();

	return (0);
}
