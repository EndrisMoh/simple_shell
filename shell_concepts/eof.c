#include <stdio.h>
int main()
{
	char ch;
	FILE *fp;

	fp = fopen("std1.txt", "w"); //open the file in write mode
	printf("enter the text then press cntrl Z:\n");

	//reading char by char until it equals to EOF
	while ((ch = getchar()) != EOF)
	{
	//i.e. when u press ctrlZ the while loop terminates
	putc(ch, fp);
	}
	fclose(fp);
	fp = fopen("std1.txt", "r");
	printf("text on the file:\n");

	//reading the character from file until fp equals to EOF
	while ((ch = getc(fp)) != EOF)
	{
	putchar(ch);
	}
	fclose(fp);
	return (0);
}