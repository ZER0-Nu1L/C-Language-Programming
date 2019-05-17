#include<stdio.h>

int main(void)
{
	char ch;
	int s = 0, l = 0;
	
	printf("Enter a sentence:\n");
	
	while( (ch=getchar())!= '\n')
	{
		if ( ch == ' ')
			s++;		
		l++; 
	}
	printf("letters:%d\n", l);
	printf("spaces:%d\n", s);
	
	return 0;
}
	
