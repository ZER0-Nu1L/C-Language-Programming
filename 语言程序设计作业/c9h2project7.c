#include<stdio.h>

int mypower(int x, int n);

int main(void) 
{
	int x, n;
	scanf("%d %d", &x ,&n);
	printf("mypower(%d,%d):  %d", x, n, mypower(x, n));
	
	return 0;
}

int  mypower(int x, int n)
{
	return n > 0 ? x * mypower(x, n - 1) : 1;// too few argyments to function 
}
