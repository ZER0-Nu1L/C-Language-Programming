#include<stdio.h>

int main ()
{
	int amount;
	int  twenty,ten,five,one;
	amount = twenty =ten =five=one=0;
	
	printf("Enter a dollar amount: \n");
	scanf("%d",&amount);
	
	twenty=amount/20;
	amount %=20;
	ten =amount/10;
	amount %=10;
	five =amount/5;
	amount %=5;	
	one =amount;
	
	printf("$20 bills: %d\n",twenty);
	printf("$10 bills: %d\n",ten);
	printf(" $5 bills: %d\n",five);
	printf(" $1 bills: %d\n",one);
	
	return 0;
 } 

