#include <stdio.h>

void calculate1(int a, int b , int *sum, int *difference); //�����Ķ�κ����Ĳ�����һ��Ҫ��ָ�룬����������պ�ú���û�з���ֵ  ����  û�취���ݵ�ָ����ȥ 
//void calculate2(int a, int b , int *sum, int *difference); 

int main (void)
{
	int a, b;
	int sum, difference;
//	int *pa, *pb;

//	pa = &a;
//	pb = &b;
	
	printf("Enter two number: ");
	scanf("%d %d", &a, &b);
	calculate1(a, b , &sum, &difference);
	printf("%d %d",sum, difference);
	
	return 0;
}

void calculate1(int a, int b , int *sum, int *difference)
{
	*sum = a+b;
	*difference = a-b;                                                       //�ں���������ָ��������������ݽ��з��ʺ��޸� 
	
	return;
}
//void calculate1(int a, int b , int sum, int difference); 
//{
//	sum = a+b;
//	difference = a-b;
//	
//	return;
//}                                                                             Ȼ��ʹ�����ȥ�ˣ�����   ��Ҳ�����scanf��ص�ԭ�� 
