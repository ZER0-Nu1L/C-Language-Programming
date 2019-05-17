#include <stdio.h>

int main ()
{
	int a;
	
	printf("Enter a number between 0 and 32767:");
	scanf("%d",&a);
	printf("\nIn octal, your number is: %05o", a);
	
	
	return 0;
 } 
