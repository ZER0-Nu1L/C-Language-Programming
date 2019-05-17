#include<stdio.h>
int main(void)
{
	int a, b, c, d, e;
	char ch[11];
	int count;

	printf("Enter the first (single) digit: ");
	scanf("%d", &a);
	printf("Enter first group of five digits: ");
	scanf("%d", &b);
	printf("Enter second group of five digits: ");
	scanf("%d", &c);

	ch[0] = a;

	ch[1] = b / 10000;
	ch[2] = b % 10000 / 1000;
	ch[3] = b % 1000 / 100;
	ch[4] = b % 100 / 10;
	ch[5] = b % 10;

	ch[6] = c / 10000;
	ch[7] = c % 10000 / 1000;
	ch[8] = c % 1000 / 100;
	ch[9] = c % 100 / 10;
	ch[10] = c % 10;

	d = 0;
	for (count = 0; count < 11; count += 2)
	{
		d += ch[count] * 3;
	}

	for (count = 1; count < 11; count += 2)
	{
		d += ch[count];
	}

	d--;
	d %= 10;
	d = 9 - d;
	
	printf("Enter the last (single) digit: ");
	scanf("%d", &e);

	if (d == e)
		printf("VALID\n");
	else
		printf("NOT VALID\n");

	return 0;
}

