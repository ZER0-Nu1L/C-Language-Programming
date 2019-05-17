#include <stdio.h>

int main(void)
{
	int a;

	printf("Please input air quality index:\n");
	scanf("%d",&a);
	
	if (a <= 50)
		printf("best");
	else if(a <= 100)
		printf("good");
	else if(a <= 150)
		printf("polluted I");
	else if(a <= 200)
		printf("polluted II");
	else if(a <= 300)
		printf("polluted III");
	else 
		printf("polluted IV");


	return 0;
} 
