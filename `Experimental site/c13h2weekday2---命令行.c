#include<stdio.h>
#include<string.h>
#define WEEK 7
#define LEN 9

int main(int argc, char *argv[])
{
	char *week[WEEK+1] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	int i, index = -1;
	for(i = 1; i < WEEK + 1; i++)
	{
		if( strcmp(week[i], argv[1]) == 0)//2!!  系统1！！ 
		{
			index = i;
		}
	}
	if(index == -1)
	{
		printf("Not found!\n");
	}
	else
	{
		printf("%s is %d.", week[index], index);
	}
	return 0;
}
//※查找的时候index要设初值
//∵你需要知道它在寻找的时候是在循环整体结束，还是满足条件后结束的；
