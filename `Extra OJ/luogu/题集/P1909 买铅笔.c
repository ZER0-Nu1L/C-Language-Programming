#include<stdio.h>                    //»º³åÇø£¡£¡ 

int main()
{
	int number;
	int n1, price1;
	int n2, price2;
	int n3, price3;
	int sum1, sum2, sum3;
	
	scanf("%d", &number);
	scanf(" %d %d ", &n1, &price1);
	scanf(" %d %d ", &n2, &price2);
	scanf(" %d %d ", &n3, &price3);
	
	if(number % n1 == 0)
	{
		sum1 = number/n1 * price1;
	}
	else
	{
		sum1 = (number/n1 + 1) * price1;
	}
	
	if(number % n2 == 0)
	{
		sum2 = number/n2 * price2;
	}
	else
	{
		sum2 = (number/n2 + 1) * price2;
	}
	
	if(number % n3 == 0)
	{
		sum3 = number/n3 * price3;
	}
	else
	{
		sum3 = (number/n3 + 1) * price3;
	}
	
	sum1 = sum1<sum2 ? sum1 : sum2;
	sum3 = sum1<sum3 ? sum1 : sum3;
	
	printf ("%d",sum3);
	
	
	return 0;
}
