#include<stdio.h>
#include<string.h>
#include<ctype.h>//��һ���ַ�����ÿ�����ʵ�����ĸת��Ϊ��д��ĸ�������ص��ʵ������� 
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
		i++;//©�� 
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

//���ȿ����������ݵĶ��뷽ʽ(�ۺ�ȫ�ֿ���)
//	�ַ����Ķ�����ʱ��Ҫ�Լ�����e.g.readline()	����������ݿ�����readline()��Ҳ������ѭ��scanf()���� 
//			��ʱ�򵥼�����ʵ�ֵ�ʱ��û�п��Ƕ�λ������getchar()ʵ�֣� 
//��Ȼ����ݶ���ķ�ʽ������Ӧ�Ĵ洢��ʽ
//	 �������scanf()�ķ�ʽ���뷽������ݽ��д���
//֮������ݴ����˳����£������ַ�������������뵥�ʣ�Ȼ�󽫵��ʵ�����ĸ��д���� 
//	���룬�����еĲ���Ҳ�������ġ�
//plus.�������뵥�ʸ����Ĳ����ԣ�������Ҫ������м���
