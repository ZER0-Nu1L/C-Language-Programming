#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(void)
{
	int n, count = 0;
	scanf("%d", &n);
	int a[n];
	bool re[n];
	int add[n][n];
	memset(add, 0, sizeof(add));
	memset(re, false, sizeof(re));
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			add[i][j] = a[i] + a[j];
		}
	}
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				if(a[k] == add[i][j] && !re[k])
				{
					count++;
					re[k] = true;
				}
			}
		}
	}
	printf("%d", count);	
	return 0;
}
/*
input:1 2 3 4 5
a   1 2 3 4 5
add  
    3 4 5 6
    5 6 7
    7 8
    9
*/
