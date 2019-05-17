#include<stdio.h> 

int main(void)
{
	int n, count = 1, max = 0;
	scanf("%d", &n);
	int tem[n];
	for(int i = 0; i < n; i++)
	{
		scanf(" %d", &tem[i]);
	}
	
	for(int i = 0; i < n-1; i++)
	{
		if(tem[i] <= tem[i + 1])
		{
			count++;
			max = (max > count ? max : count);
		}
		else
		{
			count = 1;
		}
	}
	printf("%d", max);
	
	return 0;
}
