#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11;

	printf("Enter the first (single) digit:");
	scanf("%d",&x1);
	printf("\nEnter first group of five digits:");
	scanf("%d%d%d%d%d",&x2,&x3,&x4,&x5,&x6);
	printf("\nEnter second group of five digits:");
	scanf("%d%d%d%d%d",&x7,&x8,&x9,&x10,&x11);
	
	printf("\nCheck digit: %d",9- (3*(x1+x3+x5+x7+x9+x11)+(x2+x4+x6+x8+x10-1)) %10);
	
	system( "pause");

	return 0;



}

