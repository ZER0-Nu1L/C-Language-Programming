#include<stdio.h>
#include<string.h>
#include<stdbool.h> 

void read_word(int counts[], char s[], int n);
bool equal_array(int counts1[], int counts2[]);  // 26?

int main(void)
{
	char s1[80]={'0'}, s2[80]={'0'};
	int counts1[26] = {0};
	int counts2[26] = {0};	
	int n1, n2;
	bool flag;
	
	printf("Enter first word: \n");
	fgets(s1, 80, stdin);
	n1 = sizeof(s1)/sizeof(char);
	printf("Enter second word: \n");
	fflush( stdin );
	fgets(s2, 80, stdin);
	n2 = sizeof(s2)/sizeof(char);
	
	read_word(counts1, s1, n1);
	read_word(counts2, s2, n2);
	
	flag = equal_array(counts1, counts2);
	if(flag)
		printf("The words are anagrams.");
	else
		printf("The words are not anagrams.");
	
	return 0;
}

void read_word(int counts[], char s[], int n)
{
	int index = 0, i;
	for (i = 0; i < (int) n; i++)
	{
		index = s[i] -'a';
		counts[index]++;
	}
}

bool equal_array(int counts1[], int counts2[])
{
	int i;
	for(i = 0; i < 26; i++)
	{
		if (counts1[i] != counts2[i] )
		{
			return false;
		}
	}
	return true;
}
