#include <stdio.h>

int main(void)
{
	int a, b;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&a, &b);
	
	if (a > 12 && a != 24 && a != 0)
		printf("Equivalent 12-hour time: %d:%02d PM\n", a % 12, b);
	else if( a == 12)
		printf("Equivalent 12-hour time: %d:%02d PM\n", 12, b); //
	else if( a == 0 ||a == 24)
		printf("Equivalent 12-hour time: %d:%02d AM\n", 12, b);	
	else 
		printf("Equivalent 12-hour time: %d:%02d AM\n", a, b);

	return 0;
} 
