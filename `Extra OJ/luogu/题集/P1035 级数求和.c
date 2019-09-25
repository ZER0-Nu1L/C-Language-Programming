#include<stdio.h>
int main(void)
{
	int k;
	scanf("%d", &k);
	
	double sum = 0.;
	int i = 1;
	while(sum <= k)
	{
		sum += (double) 1/i++;
	}
	
	printf("%d", i-1);
	return 0;
}
