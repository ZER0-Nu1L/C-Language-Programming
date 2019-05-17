#include <stdio.h>

int main ()
{
	int a, b, c, d, e;
	
	printf("Enter ISBN:");
	scanf("%d-%d-%d-%d-%d",&a, &b, &c, &d, &e);
	printf(" GS1 prefix: %d", a);
	printf("\nGroup identifier: %d", b);
	printf("\nPublisher code: %d", c);
	printf("\nItem number: %d", d);
	printf("\nCheck digit: %d", e);
	
	return 0;
}
