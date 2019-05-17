#include <stdio.h> 

int main(void)
{
	int a;
	
	printf("Please input an integer:\n\n");
	scanf("%d",&a);
	
	switch (a)
	{
		case 1:case 2:case -1:case -2:case 0:
			printf("Your number is: %d",a);
			break;
		default:
			printf("Your number is out of the given range.\n");
		
		
	}
	
	return 0;
}
