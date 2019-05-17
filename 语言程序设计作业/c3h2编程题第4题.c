#include <stdio.h>

int main ()
{
	int y, m, d;
	y=m=d=0;
	
	printf("Enter phone number [(xxx) xxx-xxxx]:");
	scanf("(%d) %d-%d",&m, &d, &y);
	printf("\nYou entered %d.%d.%d", m, d, y);
	
	return 0;
}
