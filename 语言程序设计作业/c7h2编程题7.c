#include<stdio.h>
#include<ctype.h>

int main(void)
{
	char op;
	int mo1, de1, mo2, de2;
	int mo, de;
	
	printf("Enter two fractions separated by a +, -, * or / sign: \n");
	scanf("%d/%d %c %d/%d", &mo1, &de1, &op, &mo2, &de2);
	
	switch(op)
	{
		case'+':
			de = de1 * de2;
			mo = de1*mo2 + de2*mo1;
			printf("The result is %d/%d", mo, de);
			break;
		case'-':
			de = de1 * de2;
			mo = -de1*mo2 + de2*mo1;
			printf("The result is %d/%d", mo, de);
			break;
		case'*':
			de = de1 * de2;
			mo = mo2 * mo1;
			printf("The result is %d/%d", mo, de);
			break;
		case'/':
			de = de1 * mo2;
			mo = de2 * mo1;
			printf("The result is %d/%d", mo, de);
			break;
	}
	return 0;

}

