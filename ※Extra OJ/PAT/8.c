#include<stdio.h> 

int main(void)
{
	int height;
	scanf("%d", &height);
	printf("%.1lf", (double) (height - 100)*0.9*2);
	
	return 0;
}
