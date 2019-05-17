#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12;

	printf("Enter the first 12 digits of an EAN:");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&x1,&x2,&x3,&x4,&x5,&x6,&x7,&x8,&x9,&x10,&x11,&x12);

	printf("\nCheck digit: %d",9- (3*(x2+x4+x6+x8+x10+x12)+(x1+x3+x5+x7+x9+x11-1)) %10);
	
	system( "pause");

	return 0;



}


