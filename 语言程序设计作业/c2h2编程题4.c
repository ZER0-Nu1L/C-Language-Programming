#include<stdio.h>

int main (void){

double amount=0.00;

printf("Enter an amount: ");
scanf("%lf",&amount);
printf("With tax added: $%.2lf\n",amount*1.05f);

return 0;

}

