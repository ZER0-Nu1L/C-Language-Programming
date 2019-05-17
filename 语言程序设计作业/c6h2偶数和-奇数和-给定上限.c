#include<stdio.h>
#include <stdlib.h>

int main (void)
{
	int upperbound;
	int sumodd = 0, sumeven = 0;
	 
	printf("Please input the upper bound: \n");
	scanf("%d", &upperbound);
	
	int i;
	for ( i =1 ; i<=upperbound; i++)
	{
		if (i%2 == 0)
		{
			sumeven += i;
		}
		else
		{
			sumodd += i;
		}
	}
	
	printf("Sum of odds: %d\n", sumodd);
	printf("Sum of evens: %d\n", sumeven);
	printf("Absolute Difference: %d \n", abs(sumodd - sumeven));
	
	return 0;
}
