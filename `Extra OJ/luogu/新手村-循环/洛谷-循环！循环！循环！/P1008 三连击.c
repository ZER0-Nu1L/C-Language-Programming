#include<stdio.h>
#include<stdbool.h>
#include<string.h> 

int main(void)
{
	int a[11] = {0};
	bool flag = true;
	int n;
	
	for(int i = 192; i < 333; i++)
	{
		n = i;
		a[n % 10] ++; a[n / 10 % 10] ++; a[n / 100] ++;
		n = 2 * i;
		a[n % 10] ++; a[n / 10 % 10] ++; a[n / 100]++;
		n = 3 * i;
		a[n % 10] ++; a[n / 10 % 10] ++; a[n / 100]++;
		
		for(int j = 1; j <= 9; j++)
		{
			if(a[j] != 1)// a[j] == 0;
			{
				flag = false;
				break;	
			}
		}
		
		if(flag)
		{
			printf("%d %d %d\n", i, 2*i, 3*i);
		}
		else
		{
			flag = true;
			memset(a, 0, sizeof(a));
		}		
	}	
	return 0;  
}
