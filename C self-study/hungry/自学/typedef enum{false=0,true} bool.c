#include<stdio.h>

int main (void) 
{
	typedef enum{false=0,true} bool;
	
	bool flag = true;
		
	flag = 2;
	
	printf("%d", flag);
		
	return 0;
}
