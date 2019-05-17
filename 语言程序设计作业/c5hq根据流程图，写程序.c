#include <stdio.h>

int main(void)
{
	int age, status;

	printf("Please input age:\n\n");
	scanf("%d",&age);
	
	if (age <= 59)
	{
		if(age >20)
		{
			printf("Adult");
		}
		else if(age >12)
		{
			printf("Teen");
		}		
		else
		{
			printf("Child");
		}
	}
	else 
	{
		printf("Please input status:\n\n");
		scanf("%d",&status);
		if(!status)
		{
			printf("Retired senior");
		}
		else
		{
			printf("Working senior");	
		}
		
	}

	return 0;
} 
