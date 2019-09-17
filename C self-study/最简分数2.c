#include<stdio.h>
 
int main()
{
    int m,n;
	scanf("%d/%d",&m,&n);
	
	//当分母是分子的因子时 
	if(m%n==0){
		printf("%d/1", m/n);
	}
	//分母不是分子的因子时
	else{
		int i = 2, min_value;
		//取分子、分母中较小的那个值 
		min_value = m > n?n:m;
		while(1){
			if(m%i== 0 && n%i == 0){
				m = m/i;
				n = n/i;
				continue;
			}
			i++;
			//选取因子2到min_value，当它们不再是每次化简后的分子分母的公因子时，已经化简结束 
			if(i > min_value) break; 
		}
		printf("%d/%d",m,n);
	} 
    return 0;
} 
