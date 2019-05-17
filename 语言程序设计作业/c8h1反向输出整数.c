#include<stdio.h>

int main(void)
{
	int a[10];
	int i;
	
	printf("Enter 10 numbers: \n");
	
	for(i=0; i<10; i++)
	{
		scanf("%d ", &a[i]);
	}
	
	printf("\nIn reverse order: ");
	for(i=9; i>=0; i--)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}
