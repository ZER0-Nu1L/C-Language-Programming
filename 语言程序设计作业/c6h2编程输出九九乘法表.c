#include<stdio.h>

int main (void)
{
	 
	
	int i, j;
	for ( i =1 ; i<10; i++)
	{
		printf("%d   ", i);
	}
	
	printf("\n");

	for ( i =1 ; i<10; i++)
	{
		printf("-   ");
	}
	
	printf("\n");
	
	for ( i =1 ; i<10; i++)
	{
		for ( j =1 ; j<i+1; j++)
		{
			printf("%-4d", i*j);
		}
		printf("\n");
	}

	
	return 0;
}
