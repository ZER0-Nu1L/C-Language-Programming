#include<stdio.h>
#include<float.h>          //!!
#include<math.h> 

int main (void)
{ 
	double f;
	double sum = 0;
	
	printf("This program sums a series of double values.\n");
	printf("Enter values (0 to terminate): \n");
	
	
	while((scanf("%lf", &f)) != 0 && f != 0.0)  //!!
	{
		sum += f;
	}
	
//	if(sum - 1133.675 <= 1 && sum - 1133.675 >= 0)
//		printf("The sum is: %.2lf\n", sum);
//	else
		printf("The sum is: %g\n", sum);   //!!
	
	
	return 0;
}
