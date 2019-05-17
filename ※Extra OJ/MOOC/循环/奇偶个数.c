#include <stdio.h>

int main ()
{
	int i, in = 0, ou = 0, ji = 0 ;
	
	do
	{
		scanf("%d",&in);
		if(in % 2 ==0)
		{
			ou ++;
		}
		else if (in== -1)
		{
			continue;
		}
		else if (in % 2 == 1) 
		{
			ji ++; 	
		}	

	}
	while (in != -1);
	
	printf("%d %d",ji, ou);		
	
	return 0;
}
