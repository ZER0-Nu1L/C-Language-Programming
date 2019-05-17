#include <stdio.h>

int main(void)
{
	int a;

	printf("Enter wind speed:\n");
	scanf("%d",&a);
	
	if (a < 1)
		printf("The description is: Calm");
	else if(a>=1 && a<=3)
		printf("The description is: Light air");
	else if(a>=4 && a<=27)
		printf("The description is: Breeze");
	else if(a>=28 && a<=47)
		printf("The description is: Gale");
	else if(a>48 && a<63)
		printf("The description is: Storm");
	else if(a>=64)
		printf("The description is: Hurricane");


	return 0;
} 
