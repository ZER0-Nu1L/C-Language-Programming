#include<stdio.h>//实现移位
#include<ctype.h>
#include<string.h>

#define MAX_LEN 80

int readline(char str[], int n);
void move(char str[], int n);
int main(void)
{
	char str[MAX_LEN+1];	int n; 
	printf("Enter a range of alpha:");
	readline(str, MAX_LEN);
	printf("Enter a number as the step you want to move");
	scanf("%d", &n);
	move(str, n);
	printf("%s", str);
	return 0;
}

void move(char str[], int n)
{
	char t[n];
	for(int i = 0; i < n; i++)
	{
		t[i] = str[strlen(str)-2-i];//+++++++++++++++++没有套出数学原理 
	}
	for(int i = n; i < strlen(str)-n; i++)
	{
		str[i] = str[i-n];
	}
	for(int i = 0; i < n; i++)
	{
		str[i] = t[i];
	}
}

int  readline(char str[], int n)
{
	char ch;
	while( isspace(ch = getchar()) )
		;
		
	int i = 0;
	while(ch != '\n' && ch != EOF)
	{
		if(i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}
