#include <stdio.h>
#include <math.h>
int main(void)
{
	int list[100];
	int i;
	int input;

	for (i = 0; i < 100; i++)
	{
		list[i] = ((i + 1) * 2)*((i + 1) * 2);
	}

	printf("Enter a number: ");

	scanf("%d", &input);

	for (i = 0; list[i] <= input; i++)
		printf("%d\n", list[i]);

	return 0;
}

