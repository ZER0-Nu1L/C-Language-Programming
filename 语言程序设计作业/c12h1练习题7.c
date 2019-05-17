#include<stdio.h> 
#include<stdbool.h>
#define N 5

bool search(const int a[], int n, int key);

int main(void)
{
	int a[N], key;
	int *p = a;
	
	printf("Enter 5 integers:\n");
	for(p = a; p < a + N; p++)
	{
		scanf("%d", p);
	}
	printf("Enter a key:\n"); 
	scanf("%d", &key);
	
	printf("The result: %d", (int) search(a, N, key)); 
	
	return 0;
}

bool search(const int a[], int n, int key)
{
	const int *p = a;
	for(p = a; p < a + N; p++)
	{
		if(*p == key)
			return true;//initialization deiscards
	}
	return false;
}
