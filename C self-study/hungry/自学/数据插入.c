#include <stdio.h>

void print(int *p, int n);
void insert(int a[], int *n, int x, int i);  //���벻������ֵ���ݵģ���Ҫ�ı�����ֵ�ģ�������һ���ú�������ֵ�õ��ģ���������ָ����Ϊ���� 

int main(void)
{
	int a[80];
	int i, n;
	int x;
	
	printf("Enter a number as the number of array: \n");
	scanf("%d",&n);
	printf("Enter numbers as the members of array: \n");
	for (i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
	printf("Enter a number that you want to insert into the array: \n");
	scanf("%d",&x);	
	printf("Enter the sertal number that you want to insert before: \n");
	scanf("%d",&i);	
		
	insert(a,&n, x, i);
	
	print (a, n);
	
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

void insert(int a[], int *n, int x, int i)
{
	int j;
	if (i<*n)
	{
		for(j=*n-1;j>=i-1;j--)
		{
			a[j+1]=a[j];
		} 
	}
	else
	{
		j=*n;	//�Ƚ�λ�ðں� 
	}
	
	a[i-1]=x;  //Ȼ������ 
	(*n)++;
} 
