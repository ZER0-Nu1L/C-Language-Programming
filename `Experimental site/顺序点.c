#include<stdio.h> 

int f(int x)
{
	return x;
}

int main(void)
{
	int i = 1;
	
	printf("���������%d\n\n", f(i++));
	printf("int i = 1;\n"
	"printf(""\%d"", f(i++));\n"
	"int f(int x){	return x;}\n"
	"���ͣ���������ǰӦ����һ��˳��㣬Ӧ���Ѿ�������ݸ��£���Ϊʲô���������أ�\n"
	"�����ǣ������ȷ��ɸ��£���ֵ���ݵ���i++������ʽ\n" 
	); 
	
	return 0;
}
