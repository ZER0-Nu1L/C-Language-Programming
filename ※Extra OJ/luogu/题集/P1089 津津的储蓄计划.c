#include <stdio.h>

int main(void)
{
	int a[11];
	int store = 0, hand = 0;
	int sum;
	int i;
	
	for (i=0; i<12; i++)
	{
		scanf("%d", &a[i]);
		
	}

	for (i=0; i<12; i++)
	{
		hand = hand + 300 - a[i] ;
		
		while(hand >= 100)//if ¸Ä³Éwhile 
		{
			hand -= 100;
			store += 100;
		}
		
		if(hand<0)
		{
			printf("%d",-(i+1));
			return 0;
		 } 
	}
	
	sum = hand + store*1.2;
	
	printf("%d",sum);
	
	return 0;
} 
