#include<stdio.h>
#include<float.h>
#include<math.h> 

int main (void)
{ 
	int n=0;
	float a;
	float max = FLT_MIN, min=FLT_MAX;          //important! 
	float sum=0, sum_squares=0;
	
	printf("Enter a series numbers:\n");
	
	while(1)
	{
		scanf("%g", &a);
		if(a == 0)
			break;
		max = a > max ? a : max ;
		min = a < min ? a : min ;
		sum += a;
		sum_squares += a*a;
		n++;
	}
	
	printf("smallest:%g\n", min);                       //%g!
	printf("largest:%g\n", max);
	printf("average:%g\n", sum / n);
	printf("standard_deviation:%g\n", sqrt(sum_squares/n - sum*sum/n/n));
	
	return 0;
}
