#include<stdio.h>

int main(void)
{
	double f, sum = 0;
	char ch;
	
	printf("Enter an expression: ");
	
	scanf("%lf", &sum);
	while(scanf(" %c%lf", &ch, &f) == 2)
	{
		if( (ch != '+')&&(ch != '-')&&(ch != '*')&&(ch != '/')) //!!!!!!!
			break;
		 
		switch(ch)
		{
			case'+':
				sum = sum + f;
				break;
			case'-':
				sum = sum - f;
				break;
			case'*':
				sum = sum * f;
				break;
			case'/':
				sum = sum / f;
				break;
		}
	}

	printf("Value of expression: %g\n",sum);

	return 0;
}

