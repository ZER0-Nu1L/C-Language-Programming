#include<stdio.h>

int main (void) 
{
	#if(!defined(__STDC__))
	printf("�Ǳ�׼C��");
	#elif defined(__STDC_VERSION__)
	printf("��׼C�汾��%ld", __STDC_VERSION__);
	#else
	printf("�ɵı�׼C��");
	#endif
	
	getchar(); 
	
	return 0;
}
