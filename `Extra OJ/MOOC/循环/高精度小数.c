/*
一个程序，输入一个分数，计算出它的小数形式。无论是否可以除尽，输出最多小数点后200位。

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
