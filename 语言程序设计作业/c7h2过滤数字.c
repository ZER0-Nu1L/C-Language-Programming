#include<stdio.h>

int main(void)
{
	char ch;
	
	printf("Please input a line of string:\n");
	
	while( (ch=getchar())!= '\n')
	{
		if ( (ch >= '0') && (ch <= '9'))
			continue;
		else
			printf("%c", ch);
		
	}
	return 0;

}

