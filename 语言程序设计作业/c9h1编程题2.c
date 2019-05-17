#include<stdio.h>

double t( double income)
{
	float tax;
	if (income <= 750)
		tax = 7.00;
	else if(income <= 2250)
		tax = 7.5 + (income-750)*0.02;
	else if(income <= 3750)
		tax = 37.50+(income-2250)*0.03;
	else if(income <= 5250)
		tax = 82.50+(income-3750)*0.04;
	else if(income <= 7000)
		tax = 142.50+(income-5250)*0.05;
	else 
		tax = 230.00+(income-7000)*0.06;
	
	return 	tax;
}

int main(void)
{
	float income;
	
	printf("Enter amount of taxable income: \n");
	scanf("%f", &income);
	printf("Tax due: $%.2f", t(income));
	
	return 0;
} 
