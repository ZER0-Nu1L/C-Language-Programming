#include <stdio.h>
#include <stdlib.h> 

void print(int *p, int n);
void insert(int *p, int *n, int x, int i);  //���벻������ֵ���ݵģ���Ҫ�ı�����ֵ�ģ�������һ���ú�������ֵ�õ��ģ���������ָ����Ϊ���� 

int main(void)
{
	int *p;
	int i, n;
	int x;
	
	printf("Enter a number as the number of array: \n");
	scanf("%d",&n);
	
	if((p = (int*)calloc(n, sizeof(int)))== NULL)
	{
		printf("Not able to allocate memory.\n"); 
		exit(1);
	}
	
	printf("Enter numbers as the members of array: \n");
	for (i=0;i<=n-1;i++)
	scanf("%d",p+i);
			
	p=realloc(p,sizeof(int)+n);	
			
	printf("Enter a number that you want to insert into the array: \n");
	scanf("%d",&x);	
	printf("Enter the sertal number that you want to insert before: \n");
	scanf("%d",&i);	
		
	insert(p, &n, x, i);
	
	print (p, n);
	
	free(p);
	
	return 0 ;
 } 
 
 void print(int *p, int n)
{
	int i;
	
	for (i=0;i<=n-1;i++)
	{
		printf("%6d", *(p+i));	
	}
	printf("\n");
	
	return ;
}

void insert(int *p, int *n, int x, int i)
{
	int j;
	if (i<*n)
	{
		for(j=*n-1;j>=i-1;j--)
		{
			p[j+1]=p[j];
		} 
	}
	else
	{
		j=*n;	//�Ƚ�λ�ðں� 
	}
	
	p[i-1]=x;  //Ȼ������ 
	(*n)++;
} 
