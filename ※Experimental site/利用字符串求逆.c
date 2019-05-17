#include<stdio.h>
#include<string.h>

int main()
{
	int i, j, t, n;
	char a[80];
	
	printf("……\n");
	gets(a);
	n = strlen(a);
	
	for (i = 0; i <= n/2; i++)
	{
		t =a[i] ;a[i] = a[n-1-i]; a[n-1-i] =t;  // n-1 的理由是 a[]中，是以0开头的，所以首尾相加 = n+1-1-1=n-1
	}
	puts(a);
	
	return 0;
}
