#include <stdio.h>
#include <math.h>
int max_s(int, int);
int main(void)
{
	int a;
	int b;

	printf("Enter two integers: ");

	scanf("%d %d", &a, &b);

	printf("Greatest common divisor: %d\n", max_s(a, b));

	return 0;
}

int max_s(int a, int b)
{
	int i;

	int m;
	int n;

	m = a > b ? a : b;
	n = a > b ? b : a;

	if (m == 0)
		return n;
	else if (n == 0)
		return m;

	for (i = n; i > 1; i--)
	{
		if ((m%i) == 0 && (n%i) == 0)
			return i;
	}

	i = 1;
	return i;
}
