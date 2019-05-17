#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int main(void)
{
	int l, n, sum = 0;
	scanf("%d %d", &l, &n);
	l++;
	bool tree[l];
	memset(tree, true, l);
	
	int begin[n], end[n];
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &begin[i], &end[i]);
	}
	for(int i = 0; i < n; i++)
	{
		memset(tree + begin[i], false, end[i] - begin[i] + 1);
	}
	for(int i = 0; i < l; i++)
	{
		if(tree[i])
			sum++;
	}
	printf("%d\n", sum);
	
}
