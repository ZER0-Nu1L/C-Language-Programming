#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE * fp;
	long number;
	char name[20] ;    //Ϊʲô�������ַ�����ָ�롷���������������� 
	int score;
	int average_score;
	
	if ( (fp = fopen("C:\\Users\\wcb53\\Desktop\\C���Գ������\\��ѧ\\�ļ�\\d12-1.txt", "r") )== NULL)   //д��ַ��ʱ��һ��Ҫ˫б�ܣ���    Cc��Сдû�й�ϵ 
	{
		printf("File open error!\n");                //�ļ��򿪴����ԭ������ǵ�ַ����ļ���û��д���ˡ� 
		exit(0);
	}
	
	int i;
	for (i=0;i<5;i++)
	{
		fscanf(fp, "%ld%s%d", &number, name, &score); //���ݻ�������ԭ���ʽ��֮����û�пո�û�й�ϵ 
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
