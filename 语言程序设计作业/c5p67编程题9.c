#include<stdio.h>

int main(void)

{

	int a, b, c, a1, b1, c1;

	printf("Enter first date (mm/dd/yy):");
	scanf("%d/%d/%d", &a, &b, &c);

	printf("\n\nEnter second date (mm/dd/yy):");                      //»º³åÇøÎÊÌâ
	 
	scanf("%d/%d/%d", &a1, &b1, &c1);

	if ((c < c1)||(c==c1 && a<a1)||(c==c1 && a==a1 && b<b1))
		printf("\n\n%d/%d/%02d is earlier than %d/%d/%02d", a, b, c, a1, b1, c1);

	else 
		printf("\n\n%d/%d/%02d is earlier than %d/%d/%02d", a1, b1, c1, a, b, c);

	return 0;

}

