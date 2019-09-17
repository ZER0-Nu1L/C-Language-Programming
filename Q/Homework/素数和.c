/*
��Ŀ���ݣ�
������Ϊ2�ǵ�һ��������3�ǵڶ���������5�ǵ������������������ơ�
���ڣ�������������n��m��0<n<=m<=200����ĳ���Ҫ�����n����������m������֮�����е������ĺͣ�������n�������͵�m��������

�����ʽ:
������������һ����ʾn���ڶ�����ʾm��
�����ʽ��
һ����������ʾ��n����������m������֮�����е������ĺͣ�������n�������͵�m��������
*/ 
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define N 200

bool is_Prime(int number);
//����ķֽ⣬step by step���ؼ�����Ϊ��˳����¡�������ˮ����� 
//��ܣ����ݵ�����(��Ҫ����������)�����ݵĴ������ݵ������
//�ؼ��㣺һ���������ݣ�����(��Ҫis_Prime()) ,�����ı�Ŷ�Ӧ�����  
int main(void)
{
	int min, max;
	scanf("%d %d", &min, &max);
	
	int prime[N] = {[1] = 2};//2 3 5 7 11 13 17 19 77
	int count = 2;
	for(int i = 3; i < N; i++)
	{
		if(is_Prime(i))
		{
			prime[count++] = i;
		}
	}
	
	int sum = 0;
	for(int i = min; i <= max; i++)
	{
		sum += prime[i];
	}
	
	printf("%d", sum);
	return 0;
}

bool is_Prime(int number)
{
	for(int i = 2; i <= (int)sqrt(number); i++)
	{
		if( number % i == 0)
		{
			return false;
		}
	}
	return true;
}
