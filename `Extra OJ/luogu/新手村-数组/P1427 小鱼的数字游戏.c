#include<stdio.h>

int main(void)
{
	int a[100];
	int i = 0;
	while(1)
	{
		scanf(" %d", &a[i]);
		if ( a[i] == 0) break;
		i++;
	}
	
	for(i--; i >= 0; i--)
	{
		printf("%d ", a[i]);	
	}
	
	return 0;
}
