#include <stdio.h> 

int main ()
{
	int a, c;
	char b;
	
	scanf("%d %c", &a, &b);            //��ֱ������һ������ ��һ�����ȳ���һ��     ���� �� һ���ַ���һ������  
	printf("1\n");                     //��ֱ�������ڶ���scanf()�Ĳ���  
	scanf("%d",&c);                    //��Ϊ���������Ѵ��ڷ���ģʽ������   
	printf("%d %c %d", a, b, c);       // �����ģʽƥ���ԭ�� 
	
	
	return 0;
	
}
