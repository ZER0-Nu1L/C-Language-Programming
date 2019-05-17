#include<stdio.h>
#include<string.h>
#define LEN 80
void build_index_url(const char* domain, char *index_url)
{
	char http[LEN + 1] = "http://www.";//3229487298神秘数字指针，或者字符串问题 
	strcpy( index_url, strcat( strcat(http, domain), "/index.html"));//, sizeof(index_url) - 1
//	index_url[sizeof(index_url) - 1] ='\0';
}

int main(void)
{
	char domain[LEN+1];
	char index_url[LEN +1];
	printf("Enter a domain name:\n");
	scanf("%s", domain);
	
	build_index_url(domain, index_url);

	printf("The URL is: %s\n", index_url);
	
	return 0;
}
