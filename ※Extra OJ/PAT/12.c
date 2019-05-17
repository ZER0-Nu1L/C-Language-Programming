#include<stdio.h> 

int main(void)
{
	int y[4], m[2], d[2];
	
	scanf("%1d%1d-%1d%1d-%1d%1d%1d%1d", &m[0], &m[1], &d[0], &d[1], &y[0], &y[1], &y[2], &y[3]);
	printf("%1d%1d%1d%1d-%1d%1d-%1d%1d", y[0], y[1], y[2], y[3], m[0], m[1], d[0], d[1]);
	
	return 0;
}
