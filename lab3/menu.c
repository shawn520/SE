                                                                            
/**************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2017-2018                          */
/*                                                                        */
/*  FILE NAME                   :   menu.c                                */
/*  PRINCIPAL AUTHOR            :   ShawnLiu                              */
/*  SUBSYSTEM NAME				:   menu                                  */
/*  MODULE NAME                 :   menu                                  */
/*  LANGUAGE					:   C                                     */
/*  TARGET ENVIRONMENT          :   ANY                                   */
/*  DATE OF FIRST RELEASE       :   2017/10/07                            */
/*  DESCRIPTION                 :   This is a menu program                */
/**************************************************************************/
   
/*
 * Revision log:
 *
 * Created by ShawnLiu, 2017/10/07
 *
 */
  


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Help();
int Quit();
int Add();
int Sub();
int Mul();
int Div();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

/* data struct and its operations */
typedef struct DataNode
{
	char*	cmd;
	char*	desc;
	int		(*handler)();
	struct	DataNode *next;
}tDataNode;

tDataNode *FindCmd(tDataNode *head, char *cmd)
{
	if(head == NULL || cmd == NULL)
	{
		return NULL;
	}
	tDataNode *p = head;
	while(p != NULL)
	{
		if(strcmp(p->cmd, cmd) == 0)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int ShowAllCmd(tDataNode *head)
{
	printf("Menu List:\n");
	tDataNode *p = head;
	while(p != NULL)
	{
		printf("%s - %s\n", p->cmd, p->desc);
		p = p->next;
	}
	return 0;
}

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

int Add()
{
	double num1, num2;
	double sum;
	printf("Addtion. Please input two numbers:\n");
	scanf("%lf %lf", &num1, &num2 );
	sum = num1 + num2;
	printf("%lf + %lf = %lf\n", num1, num2, sum);
	return 0;
}

int Sub()
{
	double num1, num2;
	double result;
	printf("Subtraction. Please input two numbers:\n");
	scanf("%lf %lf", &num1, &num2 );
	result = num1 - num2;
	printf("%lf - %lf = %lf\n", num1, num2, result);
}

int Mul()
{
	double num1, num2;
	double result;
	printf("Multiplication. Please input two numbers:\n");
	scanf("%lf %lf", &num1, &num2 );
	result = num1 * num2;
	printf("%lf * %lf = %lf\n", num1, num2, result);
}

int Div()
{
	int num1, num2;
	double result;
	printf("Division. Please input two numbers:\n");
	scanf("%d %d", &num1, &num2 );
	if(num2==0)
	{
		printf("Error: divisor can not be zero!\n");
	}
	else
	{
		result = num1 / num2;
		printf("%d / %d = %lf\n", num1, num2, result);
	}
}

int Hello()
{
	printf("Hi~My name is Shawn.\nThank you for use my cmd prgram!\n");

}

int Help()
{
	ShowAllCmd(head);
	return 0;


	/*printf("This is help cmd!\n");
	printf("---------------------------------------------\n");
	printf("|name	+ discription						 \n");
	printf("---------------------------------------------\n");
	printf("|help	+ cmd tips							 \n");
	printf("|hello	+ welcome						   	 \n");
	printf("|add	+ addition of two numbers.			 \n");
	printf("|sub	+ subtraction of two numbers.		 \n");
	printf("|mul	+ Multiplication of two numbers.	 \n");
	printf("|div	+ Division of two numbers.			 \n");
	printf("|quit	+ exit cmd.							 \n");
	printf("---------------------------------------------\n");*/
}

/*
void quit()
{
	char cmd[2];
	printf("Are you sure to quit the programe?(Y/N)");
	scanf("%s", cmd);
	if(strcmp(cmd, "Y")==0 || strcmp(cmd, "y")==0)
	{
		exit(0);
	}
	else if(strcmp(cmd, "N")==0 || strcmp(cmd, "n")==0 )
	{
		;
	}
	else
	{
		printf("Error:illegal input.\n");
	}
}*/

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


		while(p != NULL)
		{
			if(strcmp(p->cmd, cmd) == 0)//如果输入的命令和内置的命令判断=0为true，那么打印命令和它的描述
			{
				printf("%s - %s\n", p->cmd, p->desc);
				if(p->handler != NULL)//如果命令还有对应的函数
				{
					p->handler();//用函数指针调用一个函数
				}
				break;
			}
			p = p->next;
		}

		/*
		if(strcmp(cmd, "hello") == 0)
		{
			hello();
		}
		else if(strcmp(cmd, "h") == 0)
		{
			help();
		}
		else if(strcmp(cmd, "quit") == 0)
		{
			quit();
		}
		else if(strcmp(cmd, "add") == 0)
		{
			add();
		}
		else if(strcmp(cmd, "sub")==0)
		{
			sub();
		}
		else if(strcmp(cmd, "mul")==0)
		{
			mul();
		}
		else if(strcmp(cmd, "div")==0)
		{
			Div();
		}
		else
		{
			printf("Error:Wrong input!\nPlease input 'h' for help.\n");
		}*/
	}
}

int Quit()
{
	exit(0);
}

