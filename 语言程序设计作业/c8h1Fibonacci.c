#include<stdio.h>

int main(void)
{
	int a[50] = {0, 1};
	int i;
	int n;
	
	printf("Enter number of fibonacci numbers:\n");
	scanf("%d", &n);
	for(i=2; i<50; i++)
	{
		a[i] = a[i-1] + a[i-2];
	}
		printf("Fibonacci numbers: %d ", a[0]);
	
	for(i=1; i<n; i++)
	{
		printf(",%d ", a[i]);
	}
	
	return 0;
}
