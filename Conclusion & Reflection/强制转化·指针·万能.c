#include<stdio.h>

int main(void)
{
	int a = 112.3;
	int * pa = &a;
	float *pa1 = (float *)pa;
	
	printf("%f\n", *pa1);
	printf("%d\n", *pa);
	
	return 0;
}
