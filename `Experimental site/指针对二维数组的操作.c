//想编写一个对二维数组行列进行处理的函数
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define MIN 1

void print(int row, int column, int array[row][column]);
void assignment(int row, int column, int array[row][column]);

int main(void)
{
	srand( (unsigned int) time(NULL));
	int row, column;
	
	printf("Enter the row of the array:");
	scanf("%d", &row);
	printf("Enter the column of the array:");
	scanf("%d", &column);
	
	int array[row][column];
	assignment(row, column, array);
	print(row, column, array);
	
	while(1)
	{
		int d_row;
		printf("Enter the row you want to clear:(put -1 exit)");
		scanf("%d", &d_row);
		if(d_row == -1)break;
		int *p;
		for(p = array[d_row]; p < array[d_row] + column; p++)
		{
			*p = 0;
		}
		print(row, column, array);
	}
	while(1)
	{
		int d_column;
		printf("Enter the column you want to clear:(put -1 exit)");
		scanf("%d", &d_column);
		if(d_column == -1)break;
		int (*p)[column];
		for(p = array; p <array + row; p++)
		{
			(*p)[d_column] = 0;
		}
		print(row, column, array);
	}
	
	return 0;
} 
 
void print(int row, int column, int array[row][column])
{	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			printf("%5d", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void assignment(int row, int column, int array[row][column])
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			array[i][j] = rand() % MAX + MIN;
		}
	}	
}
