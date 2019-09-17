#include <stdio.h>

void print(int *p, int n);
void insert(int a[], int *n, int x, int i);  //你想不仅仅数值传递的，想要改变其数值的，（但不一定用函数返回值得到的）都合适用指正作为参数 

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
		j=*n;	//先将位置摆好 
	}
	
	a[i-1]=x;  //然后坐好 
	(*n)++;
} 
