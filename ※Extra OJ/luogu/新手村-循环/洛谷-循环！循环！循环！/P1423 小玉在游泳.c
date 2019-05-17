#include<stdio.h>
#define N 2
#define RATE 0.98
int main(void)
{
	double x;
	scanf("%lf", &x);
	
	double sum = N, swim = N;
	int i = 1;
	while(sum < x)
	{
		swim = swim * RATE;
		sum += swim;
		i++;
	}
	printf("%d", i);
	return 0;
}
//F假设没有进入循环、直接跳出是否正确
//S出口设置的等号，根据情景与题意 
