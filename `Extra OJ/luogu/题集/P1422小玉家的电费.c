#include <stdio.h>

int main(void)
{
	float charge;

	scanf("%f",&charge);
	
	if (charge <= 150)
		printf("%.1f" ,0.4463*charge);
	else if(charge <= 400)
		printf("%.1f" ,0.4463*150 + (charge-150)*0.4663);
	else 
		printf("%.1f" ,0.4463*150 + (400-150)*0.4663+(charge - 400)*0.5663);

	return 0;
} 
