#include <stdio.h>

int main ()
{
	float loan,rate,payment;
	
	printf("Enter amount of loan:");
	scanf("%f",&loan);
	printf("\nEnter interest rate:");
	scanf("%f",&rate);	
	printf("\nEnter monthly payment:");
	scanf("%f",&payment);

	loan -=payment;
	rate = rate/100.00/12.00;
	loan += (loan+payment)*rate;
	printf("\nBalance remaining after first payment: $%.2f\n",loan);
	
	loan -=payment;
	loan += (loan+payment)*rate;
	printf("Balance remaining after second payment: $%.2f\n",loan);		
	
	loan -=payment;
	loan += (loan+payment)*rate;
	printf("Balance remaining after third payment: $%.2f\n",loan);	
	
	return 0;
 } 
