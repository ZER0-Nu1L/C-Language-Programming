#include <stdio.h>

void calculate1(int a, int b , int *sum, int *difference); //这样的多参函数的参数里一定要有指针，否则变量回收后该函数没有返回值  或者  没办法传递到指针中去 
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
	*difference = a-b;                                                       //在函数中利用指针对主函数的数据进行访问和修改 
	
	return;
}
//void calculate1(int a, int b , int sum, int difference); 
//{
//	sum = a+b;
//	difference = a-b;
//	
//	return;
//}                                                                             然后就传不回去了！！！   这也许就是scanf相关的原理 
