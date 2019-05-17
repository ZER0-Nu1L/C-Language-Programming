#include<stdio.h>

int main ()
{
	int number;
	int i = 0, sum = 0;
	
	printf("Enter an positive integer:\n\n");
	scanf("%d", &number);
	
	printf("The digits are:");
	
	while(number != 0 )
	{
		sum += number %10;
		printf("   %d", number%10);
		number /= 10;
		i++; 
	}
	
	printf("\n");
	if(sum % 9 ==0)
	{
		printf("Divisible by 9: YES.");
	}
	else
	{
		printf("Divisible by 9: NO.");
	
	}
	return 0;
}
