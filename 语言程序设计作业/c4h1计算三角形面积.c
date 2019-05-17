#include<stdio.h>
#include<math.h>

int main(void)

{

	float a, b, c, s, area;

	printf("Please input data:");


	scanf("%f%f%f",&a,&b,&c);

	s= (a + b + c) / 2;
	area = sqrtf(s*(s - a)*(s - b)*(s - c));

	printf("\n\narea=%.3f",area);

	

	return 0;



}

