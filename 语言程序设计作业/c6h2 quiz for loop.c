#include<stdio.h>

int main()
{
	int i, j;
	int n;
	
	printf("Enter a positive integer:\n");
	scanf("%d", &n);
	printf("The output is:\n");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(j==1)
			printf("%d", j);
			else
			printf(" %d", j);
		}
		printf("\n");
	}
	
	return 0;
}
