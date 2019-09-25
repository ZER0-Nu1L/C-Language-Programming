#include<stdio.h>
#include<string.h>
#include<ctype.h>//将一个字符串中每个单词的首字母转换为大写字母，并返回单词的数量。 
#define LEN 80
#define NUM 10
int main(void)
{
	char ch[NUM][LEN + 1];
	int count = 0, i = 0;
//	freopen("C:\\Users\\wcb53\\Desktop\\data.txt", "r", stdin);//
	printf("Pls input a sentence: \n");
	while(scanf("%s", ch[i]) == 1)
	{
		ch[i][0] = toupper(ch[i][0]);
		count++;
//		printf("%s ", ch[i]);//
		i++;//漏了 
	}
	printf("Total words: %d\n", count);
	printf("After capitalization: ");
	for(i = 0; i < count; i++)//undefined reference to 'WinMain@16
	{
		printf("%s ", ch[i]);
	}
	printf("\n");
	return 0;
}

//※先考虑输入数据的读入方式(综合全局考虑)
//	字符串的读入有时候要自己定义e.g.readline()	这里读入数据可以用readline()，也可以用循环scanf()操作 
//			当时简单计算器实现的时候，没有考虑多位数，用getchar()实现！ 
//※然后根据读入的方式决定对应的存储方式
//	 这道题用scanf()的方式读入方便对数据进行处理
//之后的数据处理便顺理成章：定义字符串数组逐个读入单词，然后将单词的首字母大写即可 
//	想想，命令行的操作也是这样的√
//plus.由于输入单词个数的不定性，所以需要对其进行计数
