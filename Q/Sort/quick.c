#include<stdio.h>
#define N 10

void print(int a[], int n);
void quick(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void)
{
	int a[N];
	printf("Enter %d numbers:", N);
	for(int i = 0; i < N; i++)
	{
		scanf(" %d", &a[i]);
	}
	
	quick(a, 0, N - 1);
	
	printf("After sort:\n");
	print(a, N);
	
	return 0;
}

void print(int a[], int n)
{	
	for (int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
}

void quick(int a[], int low, int high)
{
	int mid = split(a, low, high);
	
	if(low >= high)return;
	quick(a, low, mid - 1);
	quick(a, mid + 1, high);
}

int split(int a[], int low, int high)
{
	int part_element = a[low];
	
	while(1)
	{
		while(low < high && part_element <= a[high])  //a[high] >= part_element
		{
			high--;
		}
		if(low >= high)break;
		a[low++] = a[high];
		
		while(low < high && a[low] <= part_element)
		{
			low++;
		}
		if(low >= high)break;
		a[high--] = a[low];
	}
	a[high] = part_element;
	return high;
}
