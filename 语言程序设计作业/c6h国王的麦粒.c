#include<stdio.h> 
#include<math.h> 

int main(void)
{
	double sum = 0;
	double i = 0;
	
	for (;i<=63;i++ )
	{
		sum += pow (2.0, i);
	}
	
//	sum /= 2.718281828459045235360;
	
	printf("volume: %le",sum/1.42e8);
	
	
	return 0;
}
