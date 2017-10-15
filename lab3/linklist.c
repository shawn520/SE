#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

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



int Quit()
{
	exit(0);
}

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


