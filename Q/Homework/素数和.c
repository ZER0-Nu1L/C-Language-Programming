/*
题目内容：
我们认为2是第一个素数，3是第二个素数，5是第三个素数，依次类推。
现在，给定两个整数n和m，0<n<=m<=200，你的程序要计算第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。

输入格式:
两个整数，第一个表示n，第二个表示m。
输出格式：
一个整数，表示第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。
*/ 
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define N 200

bool is_Prime(int number);
//问题的分解，step by step；关键是让为题顺理成章、行云流水的完成 
//框架（数据的输入(需要的数据类型)，数据的处理，数据的输出）
//关键点：一、处理数据：素数(需要is_Prime()) ,素数的标号对应，求和  
int main(void)
{
	int min, max;
	scanf("%d %d", &min, &max);
	
	int prime[N] = {[1] = 2};//2 3 5 7 11 13 17 19 77
	int count = 2;
	for(int i = 3; i < N; i++)
	{
		if(is_Prime(i))
		{
			prime[count++] = i;
		}
	}
	
	int sum = 0;
	for(int i = min; i <= max; i++)
	{
		sum += prime[i];
	}
	
	printf("%d", sum);
	return 0;
}

bool is_Prime(int number)
{
	for(int i = 2; i <= (int)sqrt(number); i++)
	{
		if( number % i == 0)
		{
			return false;
		}
	}
	return true;
}
