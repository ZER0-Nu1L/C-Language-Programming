#include<stdio.h>
 
int main()
{
    int m,n;
	scanf("%d/%d",&m,&n);
	
	//����ĸ�Ƿ��ӵ�����ʱ 
	if(m%n==0){
		printf("%d/1", m/n);
	}
	//��ĸ���Ƿ��ӵ�����ʱ
	else{
		int i = 2, min_value;
		//ȡ���ӡ���ĸ�н�С���Ǹ�ֵ 
		min_value = m > n?n:m;
		while(1){
			if(m%i== 0 && n%i == 0){
				m = m/i;
				n = n/i;
				continue;
			}
			i++;
			//ѡȡ����2��min_value�������ǲ�����ÿ�λ����ķ��ӷ�ĸ�Ĺ�����ʱ���Ѿ�������� 
			if(i > min_value) break; 
		}
		printf("%d/%d",m,n);
	} 
    return 0;
} 
