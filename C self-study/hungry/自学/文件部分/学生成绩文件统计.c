#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE * fp;
	long number;
	char name[20] ;    //为什么不能用字符串型指针》？！！》！！？！ 
	int score;
	int average_score;
	
	if ( (fp = fopen("C:\\Users\\wcb53\\Desktop\\C语言程序设计\\自学\\文件\\d12-1.txt", "r") )== NULL)   //写地址的时候一定要双斜杠！！    Cc大小写没有关系 
	{
		printf("File open error!\n");                //文件打开错误的原因可是是地址输错，文件名没有写错了。 
		exit(0);
	}
	
	int i;
	for (i=0;i<5;i++)
	{
		fscanf(fp, "%ld%s%d", &number, name, &score); //根据缓冲区的原理格式串之间有没有空格都没有关系 
		average_score += score;
		printf("%ld %s %d\n", number, name, score);
	}
	
	printf("average = %d\n", average_score/10);
	
	if (fclose(fp))
	{
		printf("Cannot close the file!\n");
		exit(0);
	}
	
	return 0;
}
