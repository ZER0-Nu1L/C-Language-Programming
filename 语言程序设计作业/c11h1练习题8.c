#include<stdio.h>
#include<limits.h>
#define N 10
int *find_largest(int a[], int n);

int main(void)
{
	int a[N];
	int *fp;
	
	printf("Enter 10 integers:\n");
	int i;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	
	fp = find_largest(a, N);
	
	printf("The largest: %d\n", *fp);
	
	return 0;
}

int *find_largest(int a[], int n)
{
	int i, index = 0;
	int max = a[0];
	for(i = 0; i < n; i++)
	{
		if(a[i] >= max)
		{
			index = i;
			max = a[i];
		}
	}
	return &a[index];
}
