#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *next;
};

int count_occurrences(struct node * list, int n);
struct node* add_to_list(struct node*list, int n);

int main(void)
{
	struct node *first = NULL;//!!!!!
	int n;
	int object;
	
	while(1){
		scanf("%d", &n);
		if(n == 0)
			break;	
		first = add_to_list(first, n);
	}	
	
	scanf("%d", &object);
	printf("The occurrences of %d is: %d\n",object, count_occurrences(first, object));
	
	free(first);                                        
	return 0;
}

int count_occurrences(struct node * list, int n)
{
	int number = 0;
	
	for(; list != NULL; list = list->next){
		if(list->value == n){
			number++;
		}
	}
	return number;
}

struct node* add_to_list(struct node*list, int n)
{
	struct node* new_node;
	
	new_node = malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}
	new_node->value = n;//
	new_node->next = list;//为能实现多个链表的创建，所以需要传递表头，用全局变量会大大限制函数的可移植性//
//	list = new_node;     //只是副本，所以没有用 
	return new_node;
}
