#include<stdio.h>

int main(void)
{
	double f, sum = 0;
	char ch;
//	freopen("C:\\Users\\wcb53\\Desktop\\data.txt", "r", stdin);
	printf("Enter an expression:\n");   //1��������ֽ�Ĺ��� 
	
	scanf("%lf", &sum);
	while(scanf(" %c%lf", &ch, &f) == 2) //���ڸ�ʽҪ���䣨�ö�δ֪�Ŀո񣩵ı���⣬����scanf()��ģʽƥ��������
										 //��Ȼ��������ǲ����ģ����ú�scanf�����ķ���ֵ���ܸ��õر�֤����
	{
		if( (ch != '+')&&(ch != '-')&&(ch != '*')&&(ch != '/')) //���߼�������ע�� || �� && Ҳ�漰���������� ����д�˴���ʱ д�� || һֱû�з���

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

