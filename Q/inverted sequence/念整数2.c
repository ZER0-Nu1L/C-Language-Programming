#include<stdio.h>
#include<string.h>
#define N 10
//问题的分解，step by step；关键是让为题顺理成章、行云流水的完成 
//框架（数据的输入(需要的数据类型)，数据的处理，数据的输出）
//关键点：一、处理数据：1、switch 即可解决对应问题 2、怎么按顺序读数字？(数组or？？？？？) 
//        二、 数据的输出格式问题 
//
int main(void)
{
	char number[N];
	fgets(number, 10, stdin);

	if(number[0] == '-')
	{
		printf("fu");
	}

	for(int i = 0; i < strlen(number); i++)
	{	
		switch(number[i])
		{
			case '0': printf("ling");break;
			case '1': printf("yi");break;
			case '2': printf("er");break;
			case '3': printf("san");break;
			case '4': printf("si");break;
			case '5': printf("wu");break;
			case '6': printf("liu");break;
			case '7': printf("qi");break;
			case '8': printf("ba");break;
			case '9': printf("jiu");break;
		}
		if(i != strlen(number) - 1)
		{
			printf(" ");
		}
	}
	return 0;
}
