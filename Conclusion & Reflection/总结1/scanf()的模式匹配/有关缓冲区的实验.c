#include <stdio.h> 

int main ()
{
	int a, c;
	char b;
	
	scanf("%d %c", &a, &b);            //若直接输入一个数字 和一个长度超过一的     数字 或 一个字符加一个数字  
	printf("1\n");                     //会直接跳过第二个scanf()的步骤  
	scanf("%d",&c);                    //因为缓冲区里已存在符合模式的内容   
	printf("%d %c %d", a, b, c);       // 这就是模式匹配的原理 
	
	
	return 0;
	
}
