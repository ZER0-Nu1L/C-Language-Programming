#include<stdio.h>
#include<ctype.h>
#include<string.h>

int f( char ch)
{
	const char a[27] = {'0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
	 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; //添0 使数字对应 
	int i = 1;
	
	ch = toupper(ch);//      to upper 变成大写字母  <ctpye.h>
	
	if(isupper(ch))  //    is upper 的判断 <ctype.h> 
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
	
	for(i=0; input[i] != EOF /*&& input[i] != '\n'*/; i++)//没有!='\n' 为什么会有那样的结果？
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
