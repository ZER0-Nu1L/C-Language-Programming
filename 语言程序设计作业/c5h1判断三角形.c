#include <stdio.h>
#include <math.h>

int main(void)
{
	float a, b, c;

//	printf("Enter 3 sides of the triangle: ");
	scanf("%f %f %f",&a, &b, &c);
	
	if (a+b> c && a+c>b && b+c>a)
	{
		if(a==b && b==c )
		printf("\nequilateral triangle");	
		else if(a==b || b==c || a==c)
		printf("isoceles triangle");	
		else if(a*a+b*b == c*c || a*a + c*c == b*b || b*b+ c*c ==a*a)
		printf("\nright-angled triangle");	
		else
		printf("\narbitrary triangle");	
	}
	else 
	{
		printf(" It isn't triangle.");
		//printf("&ldquo; These sides do not correspond to a valid triangle &rdquo;");
	}

	return 0;
} 
