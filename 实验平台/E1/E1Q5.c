#include<stdio.h>
int main(void)
{
	int a[2];
	int b[2];
	printf("Enter two fractions separated by a plus sign: ");
	scanf("%d/%d+%d/%d", &a[0], &b[0], &a[1], &b[1]);
	printf("The sum is %d/%d\n", a[0] * b[1] + a[1] * b[0], b[0] * b[1]);
	return 0;
}

