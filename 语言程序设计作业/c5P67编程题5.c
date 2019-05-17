#include <stdio.h>

int main(void)
{
	float income;

	printf("Enter income:\n");
	scanf("%f",&income);
	
	if (income <= 750)
		printf("The tax is: $7.00");
	else if(income <= 2250)
		printf("The tax is: $%.2f" ,7.5 + (income-750)*0.02);
	else if(income <= 3750)
		printf("The tax is: $%.2f" ,37.50+(income-2250)*0.03);
	else if(income <= 5250)
		printf("The tax is: $%.2f" ,82.50+(income-3750)*0.04);
	else if(income <= 7000)
		printf("The tax is: $%.2f" ,142.50+(income-5250)*0.05);
	else 
		printf("The tax is: $%.2f" ,230.00+(income-7000)*0.06);


	return 0;
} 
