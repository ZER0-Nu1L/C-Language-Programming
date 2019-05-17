#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)

{

	float x1, x2, y1, y2;
	float d;
	x1 = x2 = y1 = y2 =0.00;

	printf("Please input the coordinates of two points:\n");
	printf("point 1(x,y): ");
	scanf("(%f,%f)",&x1, &y1);
	printf("\npoint 2(x,y): ");
	scanf("  (%f,%f)",&x2, &y2);
	
	d= sqrtf((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	printf("\nThis distance is: %.4f", d);
	
	system( "pause");



	return 0;



}

