#include<stdio.h>
#define N 10
void find_two_largest(int a[],int **max,int **max2,int *num,int *num2);

int main() 
{ 
    int a[N], *p, *max, *max2, num, num2;
  
    printf("Please input 10 integers: \n");
    for(p = a; p < a + N; p++)
	{ 
        scanf(" %d",p);
    }
    
    find_two_largest(a, &max, &max2, &num, &num2);
    
 	printf("The largest: %d\nThe index of the largest: %d\n" 
           "The second largest: %d\n" 
           "The index of the second largest: %d\n",*max, num, *max2, num2);
    return 0;     
} 
void find_two_largest(int a[],int **max,int **max2,int *num,int *num2)
{
	int i;
	int m, m2;
	*max = &m;
	*max2 = &m2;
	**max = **max2 = a[0];//有问题，加入a[0] 就是最大值 
	*num = *num2 = 0;
	
	for(i = 0; i < N; i++)
	{
		if(a[i] > **max)
		{
			**max = a[i];
			*num = i;
		}
	}
	for(i = 0; i < *num; i++)
	{
		if(a[i] > **max2)
		{
			**max2 = a[i];
			*num2 = i;
		}
	}
	for(i = *num + 1; i < N; i++)
	{
		if(a[i] > **max2)
		{
			**max2 = a[i];
			*num2 = i;
		}
	}
 }
