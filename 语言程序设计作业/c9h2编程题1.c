#include<stdio.h>
#define N 10

void selection_sort(int a[], int n);

int main(void)
{
	//freopen("C:\\Users\\wcb53\\Desktop\\testdata.txt", "r", stdin);
	int a[N], i;
	printf("Enter 10 numbers to be sorted: \n");

	for(i = 0; i < N; i++)
	{
		scanf(" %d", &a[i]);
	}
	
	selection_sort(a, N);
	
	printf("In sorted order: ");
	for(i = 0;i < N; i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}

void selection_sort(int a[], int n)
{
	if(n == 1)return;
	
	int max, max_index = 0;
	int i, t;
	max = a[0];

	for(i = 0; i < n; i++)
	{
		if(max < a[i])
		{
			max_index = i;
			max = a[i];
		}
	}
	t = a[n - 1];a[n - 1] = a[max_index]; a[max_index] = t;
	
	selection_sort(a, n-1);
}
