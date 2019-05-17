#include<stdio.h>

int main(void)
{
	int a[3][4];
	int max=0, min=326000;
	int maxrow=0, maxcol=0;
	int minrow=0, mincol=0;
	int i, j;
	
	printf("please input 3*4 integers:\n\n");
	for(i = 0; i <= 2; i++)
	{
		for(j = 0; j <= 3; j++)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] > max)
			{
				max = a[i][j];
				maxrow = i; 
				maxcol = j;
			}
			if(a[i][j] < min)
			{
				min = a[i][j];
				minrow = i;
				mincol = j;
			}
		}
	}
	
	printf("max=%d,row=%d,col=%d\n", max, maxrow, maxcol);
	printf("min=%d,row=%d,col=%d", min, minrow, mincol);
	
	return 0;
}
