#include<stdio.h>

int main(void)
{
	int count[9]={0};
	long n;
	int digital;
	int l = -1;
	
	
	printf("Enter a number:\n");
	scanf("%ld", &n);
	
	while(n != 0)
	{
		digital = n % 10;
		count[digital]++;
		n /= 10;
		l++;
	}
	
	int i;
	
		printf("Repeated digits:\n");
	for(i=0;i<=l;i++)
	{
		if(count[i]>=2)
		{
			printf("%d       %d\n", i, count[i]);
		}
	}
	
	return 0;
}
