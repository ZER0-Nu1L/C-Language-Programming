#include<stdio.h>

int main(void)
{
	int a[5][5];
	int total[5]={0}, subject[5]={0};     //一定要初始化！！
	int i, j;
	int max[5] = {0}, min[5] = {100, 100, 100, 100, 100};   //一定要初始化！！

	for(i = 0; i <= 4; i++)
	{
		printf("Enter grades for student %d:", i+1);
		for(j = 0 ;j <= 4; j ++)
		{
			scanf(" %d", &a[i][j]);
			
			if(a[i][j] > max[j])
			{
				max[j] = a[i][j];
			}
			if(a[i][j] < min[j])
			{
				min[j] =a[i][j];
			}
		}
		printf("\n");
	}
	
	for(i = 0; i <= 4; i++)
	{
		for(j = 0;j <= 4; j++)
		{
			total[i] += a[i][j];
			subject[i] += a[j][i];
		}
	}
	
	printf("Student Total Average\n");
	for (i = 0; i<=4; i++)
	{
		printf("%6d%6d%6d\n", i+1, total[i], total[i]/5);
	}	
		 
	printf("\n");	 
		 
	printf("Quiz Average High Low\n");
	for (i = 0; i<=4; i++)
	{
		printf("%6d%6d%6d%6d\n", i+1, subject[i]/5, max[i], min[i]);
	}

	return 0;
}
