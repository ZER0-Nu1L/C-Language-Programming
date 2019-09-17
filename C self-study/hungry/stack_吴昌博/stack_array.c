#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define STACK_SIZE 100

int top = -1;
char content[STACK_SIZE];

void make_empty(void);
bool is_empty(void);
bool is_full(void);
int pop(void);
void push(char ch);

int main(void) 
{
	make_empty();

	push('a');push('b');push('c');push('d');
	
	printf("%-2c",pop());
	printf("%-2c",pop());
	printf("%-2c",pop());
	printf("%-2c",pop());

	make_empty();
	
	return 0;
}

void make_empty(void)
{
	top = -1;
}
bool is_empty(void)
{
	return top == -1;
}
bool is_full(void)
{
	return top == STACK_SIZE;
}

int pop(void)
{
	if(is_empty())
	{
		printf("Stack is empty!\n");
		exit(EXIT_FAILURE);
	}
	return content[top--];
}
void push(char ch)
{
	if(is_full())
	{
		printf("The content is full!\n");
		exit(EXIT_FAILURE);
	}
	content[++top] = ch;
}

