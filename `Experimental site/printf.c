#include<stdio.h>

int main()
{
	//%d 

	printf("%5d\n", 123);		//最小字段宽带
	printf("%3.4d\n", 123);		//最少的显示 
	printf("%3.3d\n", 123);		
	printf("%05d\n", 123);		//补0 
	
	printf("\n");
	
	printf("%5.1f\n", 123.4);
	printf("%5.1e\n", 123.4);
	printf("%5.2e\n", 123.4);
	
	printf("\n");
	
	printf("%g\n", 123.343600);
	printf("%.3g\n", 123.343600);
	printf("%.3g\n", 124553.343600);
	printf("%g\n", 123.3);
	printf("%.3g\n", 123.3);
	
	int i, j;
	scanf("%d%d", &i, &j);
	printf("%d", j);
	
	return 0;
 } 
