#include<stdio.h>

int main(void)
{
	char ch;
	printf("You can scan 1234 to have a try!");
		
	while(1)
	{
		scanf("%c", &ch);
		
		switch(ch)
		{
			case '1':
				printf("1 output success\n");
				break;
			case '2':
				printf("2 output success\n");
				fflush(stdin);               //Çå³ý»º³åÇø
				break;
			case '3':
				printf("3 output success\n");
				break;
			case '4':
			printf("4 output success\n");
				break;
			default :
				return 0;
			
		}
	 } 
	
	return 0;
}
