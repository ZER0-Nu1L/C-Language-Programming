#include<stdio.h>
#include<string.h>
#define MAX 80
#define N 20
int main(void)
{
	char word[MAX][N+1];
	char t[1][N+1];
	int len, i = 0;
	while(1)
	{
		printf("Enter word: \n");
		scanf(" %s", word[i]);
		if(strlen(word[i]) == 4)
		{
			len = i + 1;
			break;
		}
		i++;
	}
	for(i = 0; i < len - 1; i++)
	{
		int imax = i;
		int j;
		for(j = i + 1; j < len; j++)
		{
			if(strcmp(word[j], word[imax]) > 0)
			{ 
				imax = j;
			}
		}
		strcpy(t[0], word[i]); strcpy(word[i], word[imax]);strcpy(word[imax], t[0]);
	}
	printf("\nSmallest word: %s", word[len-1]);
	printf("\nLargest word: %s\n", word[0]);
	
	return 0;
}
