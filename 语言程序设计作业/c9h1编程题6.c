#include<stdio.h>
#include<math.h>

double f( double x)
{
	float y;

	y = 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * x - 6;
	
	return y;
}

int main(void)
{
	float x;
	
	printf("Enter value for x: \n");
	scanf("%f", &x);
	printf("Polynomial value: %g", f(x));//  %g !
	
	return 0;
} 
