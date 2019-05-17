#include<stdio.h>

int main(void)
{
	char s[80];
	char ch;
	int i, j, index;
	
	printf("Enter a sentence: \n");
	
	for( i=0; ((ch=getchar()) != '.' ) && (ch != '!') && (ch != '?'); i++)
	{
		s[i] = ch;
	}
		
	printf("Reversal of sentence: ");

	int indexmax = i;
	char sign = ch;
	
	index = indexmax-1;	


	for(i = indexmax - 1;i >= 0; i--)
	{
		if(s[i] == ' ')
		{
			for(j = i + 1; j <= index; j++)
			{
				printf("%c", s[j]);
			}
			printf(" ");
			index = i - 1;
		}
	}

	for(j = 0; j <= index; j++)
	{
		printf("%c", s[j]);
	}
	printf("%c", sign);
	index = i - 1;
	
	return 0;
}
