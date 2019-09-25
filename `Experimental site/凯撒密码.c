#include<stdio.h>// µœ÷“∆Œª
#include<ctype.h>
#include<string.h>
#define MAX_LEN 80

void Caesar_cipher(char str[], int n);

int main(void)
{
	char str[MAX_LEN+1];	int n;
	printf("Enter a range of alpha:");	scanf("%s", str);
	printf("Enter a number as key");	scanf("%d", &n);
	
	Caesar_cipher(str, n);
	printf("After encrypt:%s", str);
	
	return 0;
}
void Caesar_cipher(char str[], int n)
{
	for(int i = 0; i < strlen(str); i++)
	{
		if(isupper(str[i]))
			str[i] = (str[i] - 'A' + n) % 26 + 'A';
		else if(islower(str[i]))
			str[i] = (str[i] - 'a' + n) % 26 + 'a';
		else if(isdigit(str[i]))
			str[i] = (str[i] - '0' + n + 1) % 10 + '0';
		else
		{
			if(i % 2 == 0)	str[i] = '@';
			if(i % 3 == 0)	str[i] = '#';
			if(i % 5 == 0)	str[i] = '%';
			if(i % 7 == 0)	str[i] = '&';
			if(i % 11 == 0)	str[i] = '*';
		}
	}
}
