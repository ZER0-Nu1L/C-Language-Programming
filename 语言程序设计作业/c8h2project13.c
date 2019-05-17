#include<stdio.h>

int main(void)
{
	char chfirst[20];
	char chlast[20];
	
	printf("Enter a first and last name: \n\n");
	scanf(" %s", chfirst);
	scanf(" %s", chlast);
	
	printf("You entered the name: %s, %c.", chlast, chfirst[0]);

	return 0;

}

