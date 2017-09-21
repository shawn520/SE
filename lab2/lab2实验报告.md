【shawn520 + 《软件工程（C编码实践篇）》[MOOC课程作业](http://mooc.study.163.com/course/USTC-1000002006)】

【代码仓库】(https://github.com/shawn520/SE.git)
[GitHub代码链接](https://github.com/shawn520/SE/tree/master/lab2)

**一、实验要求**
**代码风格规范**

 - 原则：简明、易读、无二义性；
 - 缩进、命名、注释等代码编排的风格规范；
 - 《构建之法》4.1代码规范
 - 高质量C++/C编程指南（林锐）
 - 一定要及时提交代码以防丢失 
 
 
**具体要求**（参照视频中的具体实验过程）：

    实现一个命令行的菜单小程序，执行某个命令时调用一个特定的函数作为执行动作，
    实现的命令个数不少于8个；
    类似ftp的help目录或者bash的help目录；
    程序循环、接收用户的命令，如help、others等命令；
    可以广泛通用的命令行菜单子系统组件，可方便地定制而嵌入到其他系统；

**二、实验过程**
1. 配置vim
	

	```
	set tabstop=4
	set cindent
	set hlsearch
	```

2. 打开实验目录，创建lab2文件夹

	```
	$ cd workspace/SE
	$ mkdir lab2
	$ cd lab2
	```

3. 新建menu.c文件并进入vim编辑器

	```
	vim menu.c
	```

4. 进行c语言编程，完成命令行的菜单小程序，完整代码如下

	```
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
		printf("%lf - %lf = %lf\n", num1, num2, result);
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
			printf("%d - %d = %lf\n", num1, num2, result);
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
		printf("|Div	+ Division of two numbers.			 \n");
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
	```

5. 程序代码部分截图
	![](http://img.blog.csdn.net/20170921094920989?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbGl1c2hhd241MjA=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
	![](http://img.blog.csdn.net/20170921095116038?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbGl1c2hhd241MjA=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
	![](http://img.blog.csdn.net/20170921095005163?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbGl1c2hhd241MjA=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
	![](http://img.blog.csdn.net/20170921095023019?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbGl1c2hhd241MjA=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
6. 程序演示过程
	![](http://img.blog.csdn.net/20170921095814740?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbGl1c2hhd241MjA=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
7. 提交代码至版本库中
	

	```
	$ git add menu.c
	$ git commit -m "a menu cmd program."
	$ git push origin master
	```

8. 实验中遇到的问题与心得
**问题描述：**
![](http://img.blog.csdn.net/20170921101029626?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbGl1c2hhd241MjA=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
**解决办法：**发现是40131端口被占用，解除被占用端口，success!



欢迎大家访问我的——

 - GitHub主页:  https://github.com/shawn520/SE
 - CSDN博客:      http://blog.csdn.net/liushawn520
 - 新浪微博 [@奔跑中的Shawn](http://weibo.com/u/3072837203?refer_flag=1005055010_&is_all=1)



