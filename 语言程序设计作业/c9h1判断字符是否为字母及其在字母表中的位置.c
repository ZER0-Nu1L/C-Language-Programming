#include<stdio.h>
#include<ctype.h>
#include<string.h>

int f( char ch)
{
	const char a[27] = {'0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
	 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; //��0 ʹ���ֶ�Ӧ 
	int i = 1;
	
	ch = toupper(ch);//      to upper ��ɴ�д��ĸ  <ctpye.h>
	
	if(isupper(ch))  //    is upper ���ж� <ctype.h> 
	{
		while(ch != a[i++]);
		//empty loop 
		return i - 1;
	}
	else
	{
		return -1;
	}
}

int main(void)
{
	char input[80];
	int i;
	
	printf("Please input a line of characters:\n\n");
	fgets(input, 80, stdin);
	
	for(i=0; input[i] != EOF /*&& input[i] != '\n'*/; i++)//û��!='\n' Ϊʲô���������Ľ����
	{
		if(f(input[i]) != -1)
		{
			printf("The location of %c is: %d\n", input[i], f(input[i]));
		}
		else
		{
			printf("This character is not a letter.\n");
		}
	}
	return 0;
} 
