#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void generate_random_walk(char a[10][10]);
void print_array(char walk[10][10]);

int main(void)
{
	char a[10][10];
	srand( (unsigned int) time(NULL));
	
	generate_random_walk(a);
	print_array(a);//这样的参数足够吗 
	 
	return 0;
 }
 
 void generate_random_walk(char a[10][10])
 {
 	int i = 0, j = 0;
	
	for(i = 0; i < 10; i++)//对数组初始化 
	{
		for(j = 0; j <10; j++)
		{
			a[i][j] ='.';
		}
	}
	i = 0, j = 0;	
	a[0][0] = 'A';

	int k = 0;
	while(1)
	{
		int rnd = rand() % 4 + 1;
		switch (rnd)
		{
			case 1:                    //←
				if(i - 1 < 0) break;      //越界 
				if(a[i-1][j] != '.' )break;//已经走过
				i--; k++;
				a[i][j] = k + 'A';
				break;
			case 2:                    //→ 
				if(i + 1 > 9) break;
				if(a[i+1][j] != '.')break;
				i++; k++;
				a[i][j] = k + 'A';
				break;	
			case 3:                    //↑ 
				if(j - 1 < 0) break;
				if(a[i][j-1] != '.')break;
				j--; k++;
				a[i][j] = k + 'A';
				break;
			case 4:                    //↓ 
				if(j + 1 > 9) break;
				if(a[i][j+1] != '.')break;
				j++; k++;
				a[i][j] = k + 'A';
				break;	
		}
		if(k == 25)break;
		
		if(i >= 1 && i <= 8  && j >= 1 && j <= 8  )
		{
			if(a[i-1][j] != '.' && a[i+1][j] != '.' && a[i][j-1] != '.' && a[i][j+1] != '.')
			break;
		}
		if(i == 0 && j <= 8 && j >= 2)
		{
			if(a[i+1][j] != '.' && a[i][j-1] != '.' && a[i][j+1] != '.')
			break;
		}
		if(j == 0 && i <= 8  && i >= 2)
		{
			if(a[i-1][j] != '.' && a[i+1][j] != '.' && a[i][j+1] != '.')
			break;
		}
		if(j == 9 && i <= 8  && i >= 2)
		{
			if(a[i-1][j] != '.' && a[i+1][j] != '.' && a[i][j-1] != '.')
			break;
		}
		if(i == 0 && j == 9 )
		{
			if(a[i+1][j] != '.' && a[i][j-1] != '.' )
			break;
		}
		if(i == 9 && j == 0 )
		{
			if(a[i-1][j] != '.' && a[i][j+1] != '.' )
			break;
		}
		if(i == 9 && j == 9 )
		{
			if(a[i-1][j] != '.' && a[i][j-1] != '.' )
			break;
		}
	}
 }
 
 void print_array(char walk[10][10])
 {
 	int i, j;
	for(i = 0; i < 10; i++)
	{
		printf("   ");
		for(j = 0; j <10; j++)
		{
			printf(" %c", walk[i][j]);
		}
		printf("\n");
	}
 }
