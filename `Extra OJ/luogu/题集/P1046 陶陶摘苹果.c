#include<stdio.h>
#define N 10

int main(void)
{
	int apple[N];
	int height;
	int count = 0 ;
	
	for(int i = 0 ; i < N; i++)
	{
		scanf("%d", &apple[i]);
	}
	scanf("%d", &height);
	
	for(int i = 0; i < N; i++)
	{
		if(apple[i] - height - 30 <= 0)
		{
			count++;
		}
	}
	printf("%d", count);
	
	return 0;
}
