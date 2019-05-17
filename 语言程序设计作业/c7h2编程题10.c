#include<stdio.h>
#include<ctype.h>

int main(void)
{
	char ch;	
	int n=0;
	
	printf("Enter a sentence:\n");
	
	while((ch = getchar()) != '\n')
	{
		ch = toupper(ch);
		switch(ch) 
		{	
			case'A': case'E': case'I': case'O': case'U': 
				n++;
				break;
		}
	}
	
	printf("Your sentence contains %d vowels.\n",n);
	
	return 0;

}

