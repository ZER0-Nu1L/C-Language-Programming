#include<stdio.h>
#include<limits.h>
#define N 10
void find_two_largest(int a[], int n, int *lp, int *slp);

int main(void)
{
	int a[N];
	int first = INT_MIN, second = INT_MIN;
	
	printf("Enter 10 integers:\n");
	int i;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	
	find_two_largest(a, N, &first, &second);
	
	printf("Largest: %d\n", first);
	printf("Second Largest: %d\n", second);
	
	return 0;
}

void find_two_largest(int a[], int n, int *lp, int *slp)
{
	int i, index = 0;
	for(i = 0; i < n; i++)
	{
		if(a[i] >= *lp)
		{
			index = i;
			*lp = a[i];
		}
	}
	
	for(i = 0; i < index; i++)
	{
		if(a[i] >= *slp)
		{
			*slp = a[i];
		}
	}
	for(i = index + 1; i < n; i++)
	{
		if(a[i] >= *slp)
		{
			*slp = a[i];
		}
	}
}
