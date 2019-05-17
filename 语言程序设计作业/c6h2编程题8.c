#include<stdio.h>

int main (void){

	int firstday, day_number;
	int i, j;
	
    printf("Enter number of days in month:\n\n");
    scanf("%d",&day_number);
	printf("Enter starting day of the week (1=Sun, 7=Sat):\n\n");
    scanf("%d",&firstday);
	
	for(j=1;j<firstday;j++)
	{
		printf("   ");
	}
	
	for (i=1;i<=day_number;i++)
	{
		printf("%2d ", i);
		if((i+firstday - 1)%7 == 0)
		{
			printf("\n");	
		}
	}
	
	return 0;	 
}

