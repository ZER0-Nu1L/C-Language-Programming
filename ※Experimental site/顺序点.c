#include<stdio.h> 

int f(int x)
{
	return x;
}

int main(void)
{
	int i = 1;
	
	printf("程序输出：%d\n\n", f(i++));
	printf("int i = 1;\n"
	"printf(""\%d"", f(i++));\n"
	"int f(int x){	return x;}\n"
	"解释：函数调用前应该是一个顺序点，应该已经完成数据更新，那为什么是这个结果呢？\n"
	"理由是：程序的确完成更新，但值传递的是i++这个表达式\n" 
	); 
	
	return 0;
}
