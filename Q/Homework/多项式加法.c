#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define MAX 101
int main(void)
{
	int a[MAX] = {0};
	int i, coe;
	
//	freopen("C:\\Users\\wcb53\\Desktop\\data.txt", "r", stdin);//

	bool first = true;	
	while(scanf("%d", &i) == 1)
	{
		scanf("%d", &coe);
		a[i] += coe;
	}
	
	for(i = 100; i >= 0; i--)
	{
		if(a[i] != 0 && first)//�����������һ��������
		{
			if(a[i] == 1)
			{
				printf("x%d", i);//����ϵ��Ϊһ����� 
			}
			else
			{
				printf("%dx%d",a[i], i);
			}
			first = false;
		}
		else if(i == 0)//��������ݵ����� 
		{
			if(a[0] > 0)
			{
				printf("+%d", a[i], i);
			}
			else if(a[0] < 0)
			{
				printf("-%d", abs(a[i]), i);//����������������������� 
			}
		}
		else if(i == 1)//����һ���ݵ����� 
		{
			if(a[1] > 0)
			{
				if(a[i] == 1)
				{
					printf("+x");
				}
				else
				{
					printf("+%dx", a[i], i);
				}
			}
			else if(a[1] < 0)
			{
				if(a[i] == -1)
				{
					printf("-x");
				}
				else
				{
					printf("-%dx", abs(a[i]), i);
				}
			}
		}
		else if(a[i] > 0)
		{
			if(a[i] == 1)
			{
				printf("+x%d", i);
			}
			else
			{
				printf("+%dx%d", a[i], i);
			}
			
		}
		else if(a[i] < 0)
		{
			if(a[i] == -1)
			{
				printf("-x%d", i);
			}
			else
			{
				printf("-%dx%d", abs(a[i]), i);
			}
		}
		
	}
	if(first)
	{
		printf("0");//������ȫ�෴����� 
	}
	
	return 0;
}
