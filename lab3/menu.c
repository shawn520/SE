nclude <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "linklist.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

int Help();
int Add();
int Sub();
int Multi();
int Divide();
int Time();
int Power();
int Quit();

/* menu program */
static tDataNode head[] =
        {
			                {"version", "menu program v2.0", NULL, &head[1]},
							                {"help", "this is help cmd!", Help, &head[2]},
											                {"add", "this is add cmd!", Add, &head[3]},
															                {"sub", "this is sub cmd!", Sub, &head[4]},
																			                {"mul", "this is multi cmd!", Multi, &head[5]},
																							                {"div", "this is divide cmd!", Divide, &head[6]},
																											                {"pow", "this is power cmd!", Power, &head[7]},
																															                {"time", "this is time cmd!", Time, &head[8]},
																																			                {"quit", "this is quit cmd", Quit, NULL}
							        };

int main()
{
	    char cmd[CMD_MAX_LEN];
		    printf("Welcome!Use 'help' to get how to use this system.\n");
			    /* cmd line begins */
			    while(1)
					    {
							        printf("input a cmd >");
									        scanf("%s", cmd);
											        tDataNode *p = FindCmd(head, cmd);
													        if(p == NULL)
																        {
																			            printf("Wrong cmd!Use 'help' to get how to use this system.\n");
																						            continue;
																									        }
															        printf("%s ---- %s\n", p->cmd, p->desc);
																	        if(p->handler != NULL)
																				        {
																							            p->handler();
																										        }
																			    }
}


int Help()
{
	    ShowAllCmd(head);
}

int Add()
{
	    int a,b;
		    printf("Please input two integer numbers:\n");
			    scanf("%d %d", &a, &b);
				    int c = a + b;
					    printf("The result of add cmd is:\n");
						    printf("%d+%d=%d\n", a,b,c);
							    return 0;
}
int Sub()
{
	    int a,b;
		    printf("Please input two integer numbers:\n");
			    scanf("%d %d", &a, &b);
				    int c = a - b;
					    printf("The result of sub cmd is:\n");
						    printf("%d-%d=%d\n", a,b,c);
							    return 0;
}

int Multi()
{
	    int a,b;
		    printf("Please input two integer numbers:\n");
			    scanf("%d %d", &a, &b);
				    int c = a * b;
					    printf("The result of mul cmd is:\n");
						    printf("%d*%d=%d\n", a,b,c);
							    return 0;
}

int Divide()
{
	    int a,b;
		    printf("Please input two integer numbers:\n");
			    scanf("%d %d", &a, &b);
				    int c = a / b;
					    printf("The result of div cmd is:\n");
						    printf("%d/%d=%d\n", a,b,c);
							    return 0;
}

int Power()
{
	    double a,b;
		    printf("Please input two double numbers:\n");
			    scanf("%lf %lf", &a, &b);
				    double c = pow(a, b);
					    printf("The result of pow cmd is: \n");
						    printf("%.6f^%.6f=%.6f\n", a,b,c);
							    return 0;
}

int Time()
{
	    time_t t = time(0);
		    char temp[64];
			    strftime(temp, sizeof(temp), "%Y/%m/%d %X %A", localtime(&t));
				    puts(temp);
					    return 0;
}

int Quit()
{
	    exit(0);
}
