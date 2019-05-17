#include<stdio.h>

int main(void)
{
	double f, sum = 0;
	char ch;
//	freopen("C:\\Users\\wcb53\\Desktop\\data.txt", "r", stdin);
	printf("Enter an expression:\n");   //1、对问题分解的过程 
	
	scanf("%lf", &sum);
	while(scanf(" %c%lf", &ch, &f) == 2) //对于格式要求多变（好多未知的空格）的编程题，善用scanf()的模式匹配解决问题
										 //当然仅仅如此是不够的，利用好scanf（）的返回值才能更好地保证输入
	{
		if( (ch != '+')&&(ch != '-')&&(ch != '*')&&(ch != '/')) //在逻辑用语里注意 || 与 && 也涉及到否命题中 当初写此代码时 写成 || 一直没有发现

			break;
		 
		switch(ch)
		{
			case'+':
				sum = sum + f;
				break;
			case'-':
				sum = sum - f;
				break;
			case'*':
				sum = sum * f;
				break;
			case'/':
				sum = sum / f;
				break;
		}
	}

	printf("Value of expression: %g\n",sum);

	return 0;
}

