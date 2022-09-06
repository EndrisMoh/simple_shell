#include <unistd.h>
#include <stdio.h>

/**
 * main - prints the environment using the global variable environ
 *
 * Return: Always 0
 */
int main(void)
{
	extern char **environ;
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i++]);
	}
	return (0);
}