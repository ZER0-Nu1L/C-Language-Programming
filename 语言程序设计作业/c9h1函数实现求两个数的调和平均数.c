#include<stdio.h>
#include<math.h>

double harmonic_mean( double x, double y)
{
	double average;

	average = 1 / ( (1/x + 1/ y) / 2 );
	
	return average;
}

int main(void)
{
	double x, y;
	
	printf("Please input two double numbers: \n");
	scanf("%lf %lf", &x, &y);
	printf("The harmonic mean of %g and %g is: %g", x, y, harmonic_mean(x, y));
	
	return 0;
} 
