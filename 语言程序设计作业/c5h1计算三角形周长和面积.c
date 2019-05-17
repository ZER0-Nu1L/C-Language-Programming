#include <stdio.h>
#include <math.h>

int main(void)
{
	float a, b, c;
	float s;

	printf("Enter 3 sides of the triangle: ");
	scanf("%f %f %f",&a, &b, &c);
	
	if (a+b> c && a+c>b && b+c>a)
	{
	
		  s = (a+b+c)/2;
		printf("area=%.2f;perimeter=%.2f",sqrt(s*(s-a)*(s-b)*(s-c)), a+b+c);
	}
	else 
	{
		printf("&ldquo; These sides do not correspond to a valid triangle &rdquo;");
	}

	return 0;
} 
