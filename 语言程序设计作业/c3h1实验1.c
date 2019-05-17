#include <stdio.h>

int main ()
{
	int y, d;
	
	printf("Please input your age:\n");
	scanf("%d",&y);
	
	d=365 * y;
	printf("The equivalent number of days: %8d",d);
	
	return 0;
}
