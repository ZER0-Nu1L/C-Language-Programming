#include<stdio.h> 
#define N 10

void max_min(int a[], int n, int *pmax, int *pmin);

int main()
{
	int max, min;
	int a[N];
	int i;
	
	printf("Enter 10 numbers: \n");
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	
	max_min(a, N, &max, &min);
	
	printf("Largest: %d\n", max);
	printf("Smallest: %d\n", min);
	
	return 0;
}

void max_min(int a[], int n, int *pmax, int *pmin)
{
	int i;
	*pmax = *pmin = a[0];
	for(i = 0; i < n; i++)
	{
		*pmax = a[i] > *pmax ? a[i] : *pmax;
		*pmin = a[i] < *pmin ? a[i] : *pmin;
	}
}
