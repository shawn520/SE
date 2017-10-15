
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10



/*menu program*/

static tDataNode head[] =
{
	{"help", "this is help cmd!", Help, &head[1]},
	{"version", "menu program v2.0", NULL, &head[2]},
	{"quit", "Quit from menu", Quit, &head[3]},
	{"add", "Addtion", Add, &head[4]},
	{"sub", "Substraction", Sub, &head[5]},
	{"Mul", "Multition", Mul, &head[6]},
	{"Div", "Division", Div, NULL}
};

int Hello()
{
	printf("Hi~My name is Shawn.\nThank you for use my cmd prgram!\n");

}

int main()
{

	/* cmd line begins */
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd number>");
		scanf("%s", cmd);
		tDataNode *p = FindCmd(head, cmd);
		if(p == NULL)
		{
			printf("This is a wrong cmd!\n");
			continue;	
		}
		printf("%s - %s\n", p->cmd, p->desc);
		if(p->handler != NULL)
		{
			p->handler();
		}
	}
}

int Help()
{
	ShowAllCmd(head);
	return 0;
}


