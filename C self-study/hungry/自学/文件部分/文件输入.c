#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE * fp;
	long number;
	char name[20] ;    //为什么不能用字符串型指针》？！！》！！？！ 
	int score;
	
	if ( (fp = fopen("C:\\Users\\wcb53\\Desktop\\C语言程序设计\\自学\\文件\\新建.txt", "w") )== NULL)   //写地址的时候一定要双斜杠！！    Cc大小写没有关系 
	{
		printf("File open error!\n");                //文件打开错误的原因可是是地址输错，文件名没有写错了。 
		exit(0);
	}
	
	int i;
	for (i=0;i<5;i++)
	{
		scanf("%ld", &number);
		scanf("%s", &name);
		scanf("%d", &score);
		fprintf(fp, "%ld %s %d\n", number, name, score);
		}
	
	if (fclose(fp))
	{
		printf("Cannot close the file!\n");
		exit(0);
	}
	
	return 0;
}
