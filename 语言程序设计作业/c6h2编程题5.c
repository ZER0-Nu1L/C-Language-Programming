#include<stdio.h>

int main (void){
	int number;
	int sum = 0;
	
	printf("Enter a number: \n\n");
	scanf("%d",&number);

	while (number != 0)
	{
		sum =sum*10 + number%10;
		number /= 10;	
	}

    printf("The reversal is: %d",sum);

	return 0;	 
}

