#include<stdio.h>
#include<string.h>

int main(void)
{
	char s1[80]={'0'}, s2[80]={'0'};
	int number1[26] = {0};
	int number2[26] = {0};	
	int i;
	int n;
	int flag = 1;
	
	printf("Enter first word: \n");
	fgets(s1, 80, stdin);
	printf("Enter second word: \n");
	fflush( stdin );
	fgets(s2, 80, stdin);
	
	for (i = 0; i < (int)sizeof(s1)/sizeof(char); i++)
	{
		n = s1[i] -'a';
		number1[n]++;
	}
	
	for (i = 0; i < (int)sizeof(s2)/sizeof(char); i++)
	{
		n = s2[i] -'a';
		number2[n]++;
	}
	
	for(i = 0; i < 26; i++)
	{
		if (number1[i] != number2[i] )
		{
			flag = 0;
			break;
		}
	}
	
	if(flag)
	{
		printf("The words are anagrams.");
	}
	else
	{
		printf("The words are not anagrams.");
	}
	
	return 0;
}
