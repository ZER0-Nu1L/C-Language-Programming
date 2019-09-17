#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	char value;
	struct node *next;
}node;

node *top = NULL;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
int pop(void);

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
	while(top != NULL)
	{
		pop();
	}
}

bool is_empty(void)
{
	return top == NULL;
}

bool is_full(void)
{
	return false;//???Á´±í²»»áÂú¡­¡­ 
}

void push(char ch)
{
	if(is_full())
	{
		printf("The content is full!\n");
		exit(EXIT_FAILURE);
	}
	node* new_node;
	if((new_node = malloc(sizeof(node))) == NULL)
	{
		printf("Error in malloc!\n");
	}
	
	new_node->value = ch;
	new_node->next = top;
	top = new_node;
}

int pop(void)
{
	if(is_empty())
	{
		printf("The content is empty!\n");
		exit(EXIT_FAILURE);
	}
	int i;
//	node *old_top;

//	old_top = top;
	i = top->value;
	top = top->next;
	
//	free(old_top);
	return i;
}
