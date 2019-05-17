#include<stdio.h> 
#define N 100

int main(void)
{
	char a[N], ch;
	char *p = a;
	
	printf("Enter a message: Reversal is: ");
	while( (ch = getchar() ) != '\n'&& p < a + N && ch != '?')
	{
		*p++ = ch;
		if(ch == '.')
			break;
	}
	
	//printf("Reversal is: ");
	for(p = p - 1; p >= a; p--)
	{
		printf("%c", *p);
	}
	printf("\n");
	return 0;
}

