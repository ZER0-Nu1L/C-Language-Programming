#include<stdio.h>

int main(void)
{
	int centermeter=0;
	int foot=0,inch=0;
	
	scanf("%d",&centermeter);
	foot=centermeter/30.48;
	inch=(centermeter/30.48-foot)*12;
	printf("%d %d",foot,inch);
	
	return 0;
}

// һ���������⣬��ȷ�������빫ʽ��*����ϵ  �� 
// ����δ������й�����������������������Ͷ����ݽ����Ӱ�죺 
//	foot=centermeter/30.48;   ��	foot=centermeter/100/0.3048; ������� 
