#include<stdio.h>
#include<string.h>
#define WEEK 7
#define LEN 9

int main(void)
{
	char *week[WEEK+1] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	char ch[LEN + 1];
	int i, index = -1;
	printf("Please enter a string:\n");
	scanf("%s", ch);
	
	for(i = 1; i < WEEK + 1; i++)
	{
		if( strcmp(week[i], ch) == 0)
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
