#include<stdio.h>
#include<string.h>
#define N 10

int main(int argc, char *argv[])
{
	int i, index = 0;
	
	for(i = 0; i < argc; i++)
	{
		if( strcmp( argv[i], "echo") == 0)
		{
			index = i;
			break;
		}
	}
	
	for(i = index + 1; i < argc; i++)
	{
		printf("%s ", argv[i]);
	}
	printf("\n");
	
	return 0;
}
