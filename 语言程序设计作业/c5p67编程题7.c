#include <stdio.h>

int main(void)
{
	int a, b, c, d;
	int max1, max2, max;
	int min1, min2, min;
	
	printf("Enter four integers:\n");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);

	if (a>b)
	{
		max1 = a; min1 = b;
	}
	else
	{
		max1 = b; min1 = a;	
	}

	if (c>d)
	{
		max2 = c; min2 = d;
	}
	else
	{
		max2 = d; min2 = c;	
	}

	max = (max1 > max2) ? max1 : max2;
	min = (min1 < min2) ? min1 : min2;

	printf("\nLargest: %d\n", max);
	printf("Smallest: %d\n", min);
	
	return 0;
} 
