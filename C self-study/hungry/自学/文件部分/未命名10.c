#include<stdio.h>

int main (void) 
{
	#if(!defined(__STDC__))
	printf("非标准C！");
	#elif defined(__STDC_VERSION__)
	printf("标准C版本：%ld", __STDC_VERSION__);
	#else
	printf("旧的标准C！");
	#endif
	
	getchar(); 
	
	return 0;
}
