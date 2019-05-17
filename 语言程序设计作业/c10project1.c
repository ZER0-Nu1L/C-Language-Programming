#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h> 
#define STACK_SIZE 100

void stack_overflow(void);
void stack_underflow(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
char pop(void);
void push(char ch);

char contents[STACK_SIZE];
int top = 0;

int main(void)
{
	int ch;
	bool flag = true;
	printf("Enter parentheses and/or braces:\n");
	
	while( (ch = getchar()) != '\n')
	{
		if( ch == '(' || ch =='{' )
		{
			push(ch);
		}
		else if( ch == ')')
		{
			if( pop() != '(')
			{
				flag = false;
				break;
			}
		}
		else if(ch =='}')
		{
			if( pop() != '{')
			{
				flag = false;
				break;
			}
			
		}
	}
	
	if(flag)
	{
		printf("Parentheses/braces are nested properly\n");
	}
	else
	{
		printf("Parentheses/braces are not nested properly\n");
	}
	
	return 0;
}

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void stack_overflow(void)
{
  printf("Stack overflow\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
  printf("Stack underflow\n");
  exit(EXIT_FAILURE);
}

void push(char ch)
{
	if(is_full())
	{
		stack_overflow();
	}
	else
	{
		contents[top++] = ch;
	}
}

char pop(void)
{
	if(is_empty())
	{
		stack_underflow();
	}
	else
	{
		return contents[--top];
	}
	return 0;// control reaches end of non-void function
}

