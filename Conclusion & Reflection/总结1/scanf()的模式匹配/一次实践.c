#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>

int main (void)
{
	float x1, x2, y1, y2;
	float d;
	x1=x2=y1=y2=d=0.00;
	printf("Please input the coordinators of two points: \n");
	printf("point1(x1, y1): ");
	scanf("(%f, %f)",&x1, &y1);
	printf("\npoint(x2,y2):");
	scanf(" (%f, %f)", &x2, &y2);
	d= sqrtf((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	printf("\nThe disance between points(%g, %g) and (%g,%g)is %.4f", x1, y1, x2, y2, d);

	system("pause");
	
	return 0;
}
 
