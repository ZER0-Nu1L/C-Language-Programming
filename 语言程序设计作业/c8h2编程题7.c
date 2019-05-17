#include<stdio.h>

int main(void)
{
	int a[5][5];
	int sumrow[5]={0}, sumcol[5]={0};   //一定要初始化！！ 
	int i, j;

	for(i = 0; i <= 4; i++)
	{
		printf("Enter row %d:", i+1);
		for(j = 0 ;j <= 4; j ++)
		{
			scanf(" %d", &a[i][j]);
		}
		printf("\n");
	}
	
	for(i = 0; i <= 4; i++)
	{
		for(j = 0;j <= 4; j++)
		{
			sumrow[i] += a[i][j];
			sumcol[i] += a[j][i];
		}
	}
	
	printf("Row totals:");
	for (i = 0; i<=4; i++)
	{
		printf("%6d", sumrow[i]);
	}
	
	printf("\n");
	
	printf("Column totals:");
	for (i = 0; i<=4; i++)
	{
		printf("%6d", sumcol[i]);
	}

	return 0;
}
