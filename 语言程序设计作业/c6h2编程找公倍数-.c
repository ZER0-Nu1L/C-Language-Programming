#include<stdio.h> 

int main(void)
{
	int i, j=0;               //错误j的初始化没有放进循环 
	int number;
	int a[5];
	int q, p;
	int h = 0;
	
	for (i=10000;i<=99999;i++)
	{
//	i=15015;  
		if(i%3==0 && i%5==0 && i%7==0 && i%13==0)
		{
				number = i;
				while(number != 0)
				{
					a[j] = number % 10;
					number /= 10;
					j++ ;
				}
				
				j=0;
				
				for (p=0;p<=3;p++)
				{
					for(q=p+1;q<=4;q++)
					{
						if(a[q]==a[p])
						{
							goto next ;
						}	
					}
				}
				h=i;
		}
		
		next: continue;
	}
		printf("%d\n", h);
	
	return 0;
}
