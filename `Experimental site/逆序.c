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

//  i  a   d  sum  a***a在最面再打一次草稿是有必要的 
//  1  123 3  3    12
//  2  12  2  32   1
//  3  1   1  321  0
//  ??循环变量是否会大一 
