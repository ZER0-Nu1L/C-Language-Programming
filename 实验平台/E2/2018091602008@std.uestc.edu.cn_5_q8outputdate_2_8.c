#include <stdio.h>
#include <math.h>
int main(void)
{
	int day;
	int start;
	int i;
	int count;

	printf("Enter number of days in month: ");
	scanf("%d", &day);

	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &start);

	putchar('\n');

	
	for (i = 0; i < start - 1; i++)
	{
		if(i==0)
			printf("  ");
		else
			printf("   ");
	}
	for (i = start, count = 0; count < day; i++)
	{
		if (i % 7 == 1)
			printf("%2d", count + 1);
		else
			printf("%3d", count + 1);
		if ((i % 7) == 0)
			putchar('\n');
		count++;
	}
	if ((i-1) % 7 != 0)
	putchar('\n');
	return 0;
}

