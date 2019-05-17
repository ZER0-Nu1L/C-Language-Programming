#include<stdio.h>
#define N 10

int get_data(double a[]);
double harmonic_array(double a[], int n);

int main(void)
{
	double a[N] = {0.}, result = 0.;
	int n;
	
	printf("Please input less than 10 double numbers:");
	n = get_data(a);
	
	result = harmonic_array(a, n);
	
	printf("\nThe harmonic mean of this array is: %.5f", result);
	
	return 0;
}

int get_data(double a[])
{
	int i = 0;
	while(scanf(" %lf", &a[i]) == 1)//scanf(" %5lf", &a[i]) == 1)严重的后果 
	{
//		printf("%.3lf\t", a[i]); //输出中间变量法 
		i++;
		if(i == 10)
			break;
	}
	return i;
}

double harmonic_array(double a[], int n)
{
	double result = 0;//初始化很重要！！ 
	int i;
	for(i = 0; i < n; i++)
	{
		result += 1 / a[i];
	}
	result = n / result;
	
	return result;
}
