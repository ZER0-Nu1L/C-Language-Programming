#include<stdio.h>
#include<string.h>
#define LEN 80
void extension(char *ch, char *exe )
{
	while(*ch++ != '.')
		;
//	strcpy(exe, ch);
	while((*exe++ = *ch++))
		;
}

int main(void)
{
	char ch[LEN+1];                                     //÷∏’Î≥ı ºªØ
	char exe[LEN+1];
	printf("Enter full name of a file:\n");
	fgets(ch, LEN, stdin);
	
	extension(ch, exe);
	printf("The extension is: %s", exe);
	
	return 0;
}
