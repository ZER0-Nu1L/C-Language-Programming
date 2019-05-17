#include<stdio.h>
#include<math.h>

double f(double x, double a3, double a2, double a1, double a0);
int main(void)
{
	double a[4];
	scanf_s("%lf %lf %lf %lf", &a[3], &a[2], &a[1], &a[0], 4);
	double i, j;
	scanf_s("%lf %lf", &i, &j, 2);
	double s = -1;
	while (s >= 0.0001 || s <= -0.0001)
	{
		s = f( (i+j)/2, a[3], a[2], a[1], a[0]);
		if (s * f(i, a[3], a[2], a[1], a[0]) > 0)
		{
			i = (i+j) / 2;
		}
		if (s * f(j, a[3], a[2], a[1], a[0]) > 0)
		{
			j = (i+j) / 2;
		}
	}
	printf("%.2f", (i+j) / 2);
	return 0;
}

double f(double x, double a3, double a2, double a1, double a0)
{
	return a3 * pow(x,3) + a2 * pow(x,2) + a1 * x + a0;
}
