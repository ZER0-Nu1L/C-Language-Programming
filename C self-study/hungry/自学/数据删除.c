#include <stdio.h>

void print(int *p, int n);
void delete1(int a[], int *n, int x);

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
	printf("Enter a number that you want to erease from the array: \n");
	scanf("%d",&x);	
		
	delete1(a, &n, x);
	
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

	void delete1(int a[], int *n, int x)
{
	int i, j;
	int pose = -1;
	
	for (i=0;i<=*n-1;i++)
	{
		if(a[i]==x)
		{
			pose = i;
			break;
		}
	}

	if (pose == -1)
	{
		printf("Not Found!");
		return; 	
	}
		
	for(j=i;j<=*n-1;j++)
	{
		a[j]=a[j+1];
	} 

	(*n)--;
} 
