#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int read_word(void);

int first = 0;
int main(void)
{	
	while(1)
	{
		read_word();
	}
	return 0;
}

int read_word(void)
{
	char ch;
	while( (ch = getchar()) == ' ')
		;
	
	int number = 0;
	while(ch != '.' && ch != ' ')
	{
		number++;
		ch = getchar();
	}
	
	if(ch == '.' && number == 0)
	{
		exit(EXIT_SUCCESS); 
	}
	else if(ch == '.' && first == 0)
	{
		printf("%d", number);
		exit(EXIT_SUCCESS); 
	}
	else if(ch == '.' && first != 0)
	{
		printf(" %d", number);
		exit(EXIT_SUCCESS); 
	}
	else if (first == 0)
	{
		printf("%d", number);
		first = 1;
	}
	else
	{
		printf(" %d", number);
	}
	return number;
}
