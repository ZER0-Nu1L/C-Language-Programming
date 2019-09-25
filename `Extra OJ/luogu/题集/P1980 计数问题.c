#include<stdio.h>
int main(void)
{
	int count = 0;
	int n, x;
	int c, d;
	scanf("%d %d", &n, &x);
	for(int i = x; i <= n; i++)
	{
		d = i;//把i拿过来分离，不能改变循环变量，所以只能另存一个！
		while(d != 0)//x为0怎么办！不影响 
		{
			c = d % 10;
			if(x == c)count++;
			d /= 10;
		}
	}
	printf("%d", count);
	return 0;
}


