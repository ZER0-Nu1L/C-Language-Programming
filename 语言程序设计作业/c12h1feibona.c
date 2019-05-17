#include<stdio.h>
#define N 15

int main(void)
{
    int a[N] = {0,1};
	int *p = a;
	
	for(p = a + 2; p < a + N; p++)
	{
		*p = *(p-1) + *(p-2);
	}

	for(p = a; p < a + N; p++)
	{
		printf("%6d", *p);
	}

	return 0;
}
