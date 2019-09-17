#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define LEN 10
#define MAX 1000

char sentence[MAX][LEN +1];

int main(void)                        //需要注意的点：1、开头大小写不影响单词本身的性质 
{
	char word1[LEN +1];
	char word2[LEN +1];//定义两个字符串变量解决开头大小写的问题 
	// 
	int index = -1;
	int i = 0, count = 0;
	
	scanf("%s", word1);
	strcpy(word2, word1);
	word2[0] = toupper(word2[0]);
	word1[0] = tolower(word1[0]);
	while(scanf("%s", sentence[i]) != 0)
	{
		if( strcmp(word1, sentence[i]) == 0 || strcmp(word2, sentence[i]) == 0)
		{
			if(index == -1)
			{
				index = i;
			} 
		count++;
		}
		i++;
	}
	
	if(index == -1)
		printf("-1");
	else
		printf("%d %d", count, index);
	return 0;
}
