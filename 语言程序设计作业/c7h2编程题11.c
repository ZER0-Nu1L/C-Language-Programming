#include<stdio.h>

int main(void)
{
	char capital;
	char ch;
	
	printf("Enter a first name and last name:\n");
	
	while(1)
	{
		if ((ch = getchar()) != ' ')
		break;
	}
	capital = ch;
	
	while( getchar() != ' ')
		; //empty loop
		
	while( (ch = getchar()) != '\n')
	{
		printf("%c", ch);
		if(ch=='\n')
			break;
	}
	
	printf(" %c.", capital);
	
	return 0;

}

