#include <stdio.h>

int main(void)
{
	int a;

	printf("Enter a number:\n");
	scanf("%d",&a);
	
	if (a / 10 > 99)
		printf("The number %d has 4 digits",a);
	else if(a / 10 > 9)
		printf("The number %d has 3 digits",a);
	else if(a / 10 > 0)
		printf("The number %d has 2 digits",a);
	else if(a / 10 == 0)
		printf("The number %d has 1 digits",a);

	return 0;
} 
