#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE * fp;
	long number;
	char name[20] ;    //Ϊʲô�������ַ�����ָ�롷���������������� 
	int score;
	
	if ( (fp = fopen("C:\\Users\\wcb53\\Desktop\\C���Գ������\\��ѧ\\�ļ�\\�½�.txt", "w") )== NULL)   //д��ַ��ʱ��һ��Ҫ˫б�ܣ���    Cc��Сдû�й�ϵ 
	{
		printf("File open error!\n");                //�ļ��򿪴����ԭ������ǵ�ַ����ļ���û��д���ˡ� 
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
