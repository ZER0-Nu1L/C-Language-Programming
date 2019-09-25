#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int main(void) 
{
	int n;
	scanf("%d", &n);
	int a[n][n];
	bool m[n][n];
	bool o[n][n];
	memset(m, false, sizeof(m));
	memset(o, false, sizeof(o));
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	int iindex = 0, jindex = 0;
	int *p1;
	for(int i = 0; i < n; i++)
	{
		for(p1 = a[i]; p1 < a[i] + n; p1++)
		{
			if(*p1 > a[i][jindex])
			{
				jindex = p1 - a[i];
			}
		}
		m[i][jindex] = true;
	}	
	int (*p2)[n];
	for(int j = 0; j < n; j++)
	{
		for(p2 = a; p2 < a + n; p2++)
		{
			if( (*p2)[j] < a[iindex][j])
			{
				iindex = p2 - a;
			}
		}
		o[iindex][j] = true;
	}
	
	bool flag = false;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(m[i][j] && o[i][j])
			{
				printf("%d %d\n", i, j);
				flag = true;
			}
		}
	}
	
	if(!flag)
	{
		printf("NO\n");
	}
	return 0;
}
