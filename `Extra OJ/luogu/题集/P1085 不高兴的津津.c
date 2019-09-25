#include <stdio.h>

int main (void)
{
	unsigned a[6];
	unsigned b[6];
	unsigned c[6];
	int i = 0;
	int flag =0 ;
	
	for (;i<7;i++)
	{
		scanf("%u %u",&a[i],&b[i]);
		c[i]=a[i]+b[i];
	}
	
	for (i=1;i<7;i++)	
	{
		if(c[i]>8)
		{
			printf("%d",i+1);
			flag = 1;
			break;		
		}
		
	}
	
	if (flag == 0)
		printf("0");
	
	return 0;
}
