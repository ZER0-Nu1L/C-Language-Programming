#include<stdio.h>
#include<math.h>

int main()
{
	int i, upper;
	
	printf("Enter the upper bound:\n\n");
	scanf("%d", &upper);

	upper =sqrt(upper);
	
	
	for(i=1;i<=upper;i++)
	{
		if(i*i %2 == 0)
		printf("%d\n", i*i);
	}
		
	return 0;
}
