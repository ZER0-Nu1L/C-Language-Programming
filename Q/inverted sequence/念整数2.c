#include<stdio.h>
#include<string.h>
#define N 10
//����ķֽ⣬step by step���ؼ�����Ϊ��˳����¡�������ˮ����� 
//��ܣ����ݵ�����(��Ҫ����������)�����ݵĴ������ݵ������
//�ؼ��㣺һ���������ݣ�1��switch ���ɽ����Ӧ���� 2����ô��˳������֣�(����or����������) 
//        ���� ���ݵ������ʽ���� 
//
int main(void)
{
	char number[N];
	fgets(number, 10, stdin);

	if(number[0] == '-')
	{
		printf("fu");
	}

	for(int i = 0; i < strlen(number); i++)
	{	
		switch(number[i])
		{
			case '0': printf("ling");break;
			case '1': printf("yi");break;
			case '2': printf("er");break;
			case '3': printf("san");break;
			case '4': printf("si");break;
			case '5': printf("wu");break;
			case '6': printf("liu");break;
			case '7': printf("qi");break;
			case '8': printf("ba");break;
			case '9': printf("jiu");break;
		}
		if(i != strlen(number) - 1)
		{
			printf(" ");
		}
	}
	return 0;
}
