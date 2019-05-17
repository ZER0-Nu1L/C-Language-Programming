#include<stdio.h>

int main(void)
{
	char ch;
	float f;
	int sum = 0, w = 1;
	
	printf("Enter a sentence:\n");
	
	while( (ch=getchar())!= '\n')
	{
		if(ch == ' ')
		{
			w++;
		}
		else
		{
			sum++;
		}
	}
	
	f = sum*1.0 / w;
	printf("Average word length: %.1f\n", f);
	
	return 0;
}
	
