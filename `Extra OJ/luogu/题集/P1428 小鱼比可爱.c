#include<stdio.h>
#include<memory.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int fish[n], count[n];//variable-sized object may not be initialized
	memset(count, 0, sizeof(count));//if not sizeof(count) then it would make mistakes!
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(fish[i] > fish[j]) count[i]++;
		}
	} 
	for(int i = 0; i < n; i++)
	{
		printf("%d ", count[i]);
	}
	
	return 0;
}
