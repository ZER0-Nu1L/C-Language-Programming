#include<stdio.h> 
#define N 5

double inner_product(const double *a, const double *b);

int main(void)
{
	double a[N], b[N];
	double *pa = a, *pb = b;
	
	printf("Enter 5 numbers for the first array:\n");
	for(pa = a; pa < a + N; pa++)
	{
		scanf("%lf", pa);
	}
	printf("Enter 5 numbers for the second array:\n");
	for(pb = b; pb < b + N; pb++)
	{
		scanf("%lf", pb);
	}
	
	printf("The inner product: %f", inner_product(a, b));
	
	return 0;
}

double inner_product(const double *a, const double *b)
{
	const double *pa = a, *pb = b;
	double result = 0.;
	for(pa = a, pb = b; pa < a + N; pa++, pb++)
	{
		result += *pa * *pb;
	}
	return result;
}
