#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reversed_array(int number);

int main(void)
{
	int number;
	printf("Enter a number:");
	scanf("%d", number);
	reversed_array(number);
	
	return 0;
}

void reversed_array(int number)
{
	char a[10];
	itoa(number, a, 10);
	for(int i = strlen(a); i >=0; i--)
	{
		printf("%c", a[i]);
	}
}
