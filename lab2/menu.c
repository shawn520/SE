#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void add()
{
	double num1, num2;
	double sum;
	printf("Addtion. Please input two numbers:\n");
	scanf("%lf %lf", &num1, &num2 );
	sum = num1 + num2;
	printf("%lf + %lf = %lf\n", num1, num2, sum);
}

void sub()
{
	double num1, num2;
	double result;
	printf("Subtraction. Please input two numbers:\n");
	scanf("%lf %lf", &num1, &num2 );
	result = num1 - num2;
	printf("%lf - %lf = %lf\n", num1, num2, result);
}

void mul()
{
	double num1, num2;
	double result;
	printf("Multiplication. Please input two numbers:\n");
	scanf("%lf %lf", &num1, &num2 );
	result = num1 * num2;
	printf("%lf * %lf = %lf\n", num1, num2, result);
}

void Div()
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

void hello()
{
	printf("Hi~My name is Shawn.\nThank you for use my cmd prgram!\n");

}

void help()
{
	printf("This is help cmd!\n");
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
	printf("---------------------------------------------\n");
}

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
}

int main()
{
	char cmd[128];
	while(1)
	{
		scanf("%s", cmd);
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
		}
	}
}
