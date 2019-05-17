#include <stdio.h>

int main ()
{
	float meter=0.00;
	float inch=0.00;
	
	printf("Please input your height (meter):\n");
	scanf("%f",&meter);
	
	inch = meter * 100.0f / 2.54f ;//	inch = meter  / 2.54f * 100.0f  ²»ÐÐ£¡£¡ 
	printf("Your height in inch is: %.4f inches",inch);
	
	return 0;
}
