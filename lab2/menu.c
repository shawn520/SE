#include<stdio.h>
#include<stdlib.h>
int main()
{
	char cmd[128];
	while(1)
	{
		scanf("%s", cmd);
		if(strcmp(cmd, "help") == 0)
		{
			printf("This is help cmd!\n");
		}
		else if(strcmp(cmd, "quit") == 0)
		{
			exit(0);
		}
		else
		{
			printf("Wrong cmd!\n");
		}
	}
}
