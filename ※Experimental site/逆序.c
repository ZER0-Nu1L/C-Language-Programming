#include<stdio.h>

int main (void){
	int a, sum = 0 ;
	int d;
	int i; 
	
	scanf("%d",&a);
	
	for(i = 1;i <= 3;i++){
	
		d = a % 10;
		sum = sum*10 + d;
		a /= 10;    
   }
   printf("%d",sum);

	return 0;	 
}

//  i  a   d  sum  a***a�������ٴ�һ�βݸ����б�Ҫ�� 
//  1  123 3  3    12
//  2  12  2  32   1
//  3  1   1  321  0
//  ??ѭ�������Ƿ���һ 
