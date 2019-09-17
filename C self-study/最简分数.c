/*
	实现分数的最简化 
*/
#include<stdio.h>
int acc(int a,int b)
{    int temp;
      while(b!=0)
       {    temp=a%b;
            a=b; 
            b=temp;            
       }
       return a;
}
 
int main(void)
{   int n,m,c;
     scanf("%d/%d",&n,&m);
     c=acc(n,m);
     n=n/c;
     m=m/c;
     printf("%d/%d",n,m);
     
 	return 0;	
}
