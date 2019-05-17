#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
	char s[80];
	int i;
	printf("Enter message: \n");
	//scanf("%s", s);
	gets(s);                           //the `gets' function is dangerous and should not be used.
	printf("In B1FF-speak: ");
	
	for(i=0; s[i] != '\0'; i++)
	{
		s[i] = toupper(s[i]);
		switch (s[i])
		{
			case 'A':
				printf("4");
				break;
			case 'B':
				printf("8");
				break;
			case 'E':
				printf("3");
				break;
			case 'I':
				printf("1");
				break;
			case 'O':
				printf("0");
				break;
			case 'S':
				printf("5");
				break;
			default :
				printf("%c", s[i]);
				break;
		}
	}
	printf("!!!!!!!!!!\n");
	return 0;
}
