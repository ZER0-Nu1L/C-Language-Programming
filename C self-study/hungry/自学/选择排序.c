#include <stdio.h>

void print(int *p, int n);
void choose (int *p, int n);

int main (void)
{
	int n;
	int i, j, imin, t; 
	int a[10];
	
	printf("Enter a number as the number of array: \n");
	scanf("%d",&n);
	printf("Enter numbers as the members of array: \n");
	for (i=0;i<=n-1;i++)
		scanf("%d",&a[i]);

    choose (a, n);
	 
	print(a,n);
	
	return 0;
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

void choose (int a[], int n)
{
	int i, j, imin, t; 
	
	for(i=0;i<n-1;i++)
	 {
	 	imin = i;
	 	for(j=i+1;j<=n-1;j++)
	 	{
	 		if(a[imin]>a[j])
			{
			 	t = imin ; imin = j; j = t;
			} 
		}
		 t=a[imin];a[imin]=a[i];a[i]=t;
		 
	 	printf("这是第%d次排序后的结果：", i+1); 
		print(a,n);
	 }
	
	return;
}
