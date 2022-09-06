#include <dirent.h>
#include <stdio.h>

/**
 *main - program that looks for files in the current PATH
 *
 * Return: current PATH
 */

int main(void)
{
	DIR *d;
	struct dirent *dir;
	d = opendir(".");

	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			printf("%s\n", dir->d_name);
		}
	closedir(d);
	}
	return (0);
}