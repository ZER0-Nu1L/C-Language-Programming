#include<stdio.h>

int main(void)
{
	int count[10] = {0};
	char number[80];
	int i = 0, j = 0;
	
	printf("Enter a number: ");
	
	while( scanf("%c", &number[i]) ==1 && number[i] != '\n')
	{
		while(number[i]-'0' != j++);
		count[j-1]++;
		
		j=0;//!!!!
		i++;
	}
	
	printf("Digit:		0  1  2  3  4  5  6  7  8  9\n");
	printf("Occurrences:\t");
	for(i = 0; i <= 9; i++)
	{
		printf("%-3d", count[i]);
	}
	
	printf("\n");
	
	return 0;
 } 
