/*
һ����������һ�����������������С����ʽ�������Ƿ���Գ�����������С�����200λ��

*/
#include<stdio.h> 

int main(void)
{
	int a, b;
	int count = 0;
	
	scanf("%d/%d",&a, &b);
	printf("0.");
	while( a!= 0 && count < 200)
	{
		printf("%d", a * 10 / b);
		a = a * 10 % b;
		count++;
	}
	
	return 0;
}
