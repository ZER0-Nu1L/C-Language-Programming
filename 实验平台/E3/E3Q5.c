#include<stdio.h>
#include<string.h>

int main(void)
{
	char s[80];
	int i;
	int n;
	
	printf("Enter message to be encrypted: ");
	fgets(s, 80, stdin);
	printf("Enter shift amount (1-25): ");
	scanf(" %d", &n);

	for(i = 0; i < (int)(sizeof(s)/sizeof(char)) ; i++)                           //!
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] = (s[i] - 'A' + n) % 26 +'A';
		if(s[i] >= 'a' && s[i] <= 'z')
			s[i] = (s[i] - 'a' + n) % 26 +'a';
	}
	
	printf("Encrypted message: %s", s);
	return 0;
}
