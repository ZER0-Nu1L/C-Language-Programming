#include<stdio.h> 

int main(void)
{
	int a, b;
	int min;
	int i = 0;
	
	printf("Enter a fraction:");
	scanf("%d/%d", &a, &b);
	
	min = a<b ? a : b;
	
	for(i=min;i>=1;i--)
	{
		if ((a % i == 0 ) && (b % i ==0))
		{
			a /= i;
			b /= i;			
		}
	}
	
	printf("\nIn lowest terms: %d/%d", a, b);
	
	return 0;
}
