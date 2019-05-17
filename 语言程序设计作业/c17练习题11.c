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
	new_node->next = list;//Ϊ��ʵ�ֶ������Ĵ�����������Ҫ���ݱ�ͷ����ȫ�ֱ����������ƺ����Ŀ���ֲ��//
//	list = new_node;     //ֻ�Ǹ���������û���� 
	return new_node;
}
