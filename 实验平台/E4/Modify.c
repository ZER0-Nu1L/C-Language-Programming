#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define STACK_SIZE 100

char contents[STACK_SIZE]; 
int top = 0;

void empty(void);
void stack_overflow(void);
void stack_underflow(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);

int main(void)
{
	char ch;
	bool flag = true;
	printf("Enter parentheses and/or braces: ");
	
	empty();
	while( (ch = getchar()) != '\n' && ch != EOF)
	{
		if(ch == '(' || ch == '{' )
		{
			push(ch);
		}
		else if (ch == ')')
		{
			flag = ( pop() == '(' );
		}
		else if( ch == '}')
		{
			flag = (pop() == '{');
		}
		
		if(flag)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	
	if(top != 0)
	{
		flag = false;
	}
	
	printf(flag ? "Parentheses/braces are nested properly\n" : "Parentheses/braces are NOT nested properly\n");
	
	return 0;
}

void empty(void)
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
  printf("Parentheses/braces are NOT nested properly\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
  printf("Parentheses/braces are NOT nested properly\n");
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
		contents[top++] =ch;
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
}
