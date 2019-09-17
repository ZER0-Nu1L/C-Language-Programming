#include<stdio.h> 
#include<stdlib.h>

typedef struct node{
	int value;
	struct node *next;
} node;

int count_occurrences(node * list, int n);
node *add_to_list(node* list, int n);//expected 'node' but argument is of type 'struct node *'
node * delete_form_list(node* list, int n);

void print_list(node * list);

int main(void)                          //copy时要小心…… 
{
	int n, object;
	node *first = NULL;
	
	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
			break;
		first = (node*)add_to_list(first, n);//incompatible type for argument 1 of
	}
	
	scanf("%d", &object);
	printf("The occurrences of %d is: %d\n",object, count_occurrences(first, object));
	scanf("%d", &object);
	delete_form_list(first, object);
	printf("After delete:");
	print_list(first);
	
	free(first);
	
	return 0;
}

int count_occurrences(node * list, int n)
{
	int number = 0;
	for(; list != NULL; list = list->next)
	{
		if(list->value == n)
			number++;
	}
	return number;
}

node *add_to_list(node* list, int n)
{
	node *new_node;
	if(  (new_node = (node *)malloc(sizeof(node) ) )== NULL)
	{
		printf("ERROR\n");
	}
	new_node->value = n;//incompatible types when assigning 'struct nod *' from type 'node'
	new_node->next = list;
	
	return new_node;
}

node * delete_form_list(node* list, int n)
{
	node *prev, *cur;//
	for(prev = NULL, cur = list;
		cur != NULL && cur->value !=n;
		prev = cur, cur = cur->next)
		;
	if(cur == NULL)
	{
		printf("Not found!\n");
		return list;
	}
	if(prev == NULL)
	{
		list = list->next;
	}
	else
	{
		prev->next = cur->next;
	}
	free(cur);
	return list;
}

void print_list(node *list)
{
	for(; list != NULL; list = list->next)
	{
		printf("%3d", list->value);
	}
	printf("\n");
}
