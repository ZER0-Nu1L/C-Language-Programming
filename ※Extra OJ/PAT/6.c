#include<stdio.h>

int main(void)
{
	int centermeter=0;
	int foot=0,inch=0;
	
	scanf("%d",&centermeter);
	foot=centermeter/30.48;
	inch=(centermeter/30.48-foot)*12;
	printf("%d %d",foot,inch);
	
	return 0;
}

// 一、进制问题，明确操作数与公式，*、关系  ； 
// 二、未解决，有关数据类型与运算符两侧类型对数据结果的影响： 
//	foot=centermeter/30.48;   与	foot=centermeter/100/0.3048; 结果差距大； 
