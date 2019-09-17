#include<stdio.h>

int main(void)
{
	int number, new_number = 0;
	int a;
	scanf("%d", &number);
	if(number < 0)
	{
		printf("fu ");
		number = -number;
	}
	while(number != 0)
	{
		new_number = new_number*10 + number % 10;
		number /=  10;
	}
//	printf("%d", new_number);
	while(new_number != 0)//
	{
		a = new_number % 10;
		if(new_number >= 10)
		{
			switch(a)
			{
				case 0: printf("ling ");break;
				case 1: printf("yi ");break;
				case 2: printf("er ");break;
				case 3: printf("san ");break;
				case 4: printf("si ");break;
				case 5: printf("wu ");break;
				case 6: printf("liu ");break;
				case 7: printf("qi ");break;
				case 8: printf("ba ");break;
				case 9: printf("jiu ");break;
			}
		}
		else
		{
			switch(a)
			{
				case 0: printf("ling");break;
				case 1: printf("yi");break;
				case 2: printf("er");break;
				case 3: printf("san");break;
				case 4: printf("si");break;
				case 5: printf("wu");break;
				case 6: printf("liu");break;
				case 7: printf("qi");break;
				case 8: printf("ba");break;
				case 9: printf("jiu");break;
			}
		}
		new_number /= 10;		
	}
	return 0;
}
