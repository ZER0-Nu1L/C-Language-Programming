#include <stdio.h>

int main(void)
{
	float x, y;
	
	printf("Please input coordinates of a point (x,y):\n");
	scanf("(%f,%f)",&x, &y);
	
	if (x==0 && y==0)
		printf("This point is the origin.");
	else if(x > 0 && y > 0)
		printf("This point is in QI.");
	else if(x < 0 && y > 0)
		printf("This point is in QII.");
	else if(x < 0 && y < 0)
		printf("This point is in QIII.");
	else if(x > 0 && y< 0)
		printf("This point is in QIV.");
	else if(x==0)
		printf("This point is on the y-axis.");
	else if(y==0)
		printf("This point is on the x-axis.");

	return 0;
} 
