#include<stdio.h>
#include<math.h>

void divide(double a, char* sign, int* i, double* f);

int main(void)
{
	double a;
	char sign;
	int i;
	double f;
	
	printf("Enter a number: ");
	scanf("%lf", &a);
	
	divide(a, &sign, &i, &f);
	
	printf("\nsign: %c\n", sign);
	printf("integer part: %d\n", i);
	printf("fractional part: %g\n", f);
	
	return 0;
}

void divide(double a, char* cp, int* p, double* fp)
{
		if(a > 0)
	{
		*cp = '+';
	}
	else if(a < 0)
	{
		*cp = '-';
		a = -a;
	}
	else
	{
		*cp = ' ';
	}
	*p = (int) a;
	*fp = a - *p;
	
}
