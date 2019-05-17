#include<stdio.h>
int main(void)
{
	float loan;
	float rate;
	float pay;
	float rate2;
	printf("Enter amount of loan: ");
	scanf("%f", &loan);
	printf("Enter interest rate: ");
	scanf("%f", &rate);
	printf("Enter monthly payment: ");
	scanf("%f", &pay);
	putchar('\n');

	rate2 = 0.01*rate / 12.0;

	loan = loan * (rate2 + 1) - pay;

	printf("Balance remaining after first payment: $%.2f\n", loan);

	loan = loan * (rate2 + 1) - pay;

	printf("Balance remaining after second payment: $%.2f\n", loan);

	loan = loan * (rate2 + 1) - pay;

	printf("Balance remaining after third payment: $%.2f\n", loan);

	return 0;
}

