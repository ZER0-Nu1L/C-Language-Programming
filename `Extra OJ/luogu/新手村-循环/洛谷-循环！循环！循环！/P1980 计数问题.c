#include<stdio.h>
int main(void)
{
	int count = 0;
	int n, x;
	int c, d;
	scanf("%d %d", &n, &x);
	for(int i = x; i <= n; i++)
	{
		d = i;//��i�ù������룬���ܸı�ѭ������������ֻ�����һ����
		while(d != 0)//xΪ0��ô�죡��Ӱ�� 
		{
			c = d % 10;
			if(x == c)count++;
			d /= 10;
		}
	}
	printf("%d", count);
	return 0;
}


