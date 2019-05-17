#include<stdio.h>
#include<limits.h> 
#define N 10

void find_two_largest(int a[], int n, int *imax, int *ismax, int *max, int *smax);

int main(void)
{
	int a[N];
	int imax = 0, ismax = 0;
	int max, smax;
	int *p = a;
	printf("Please input 10 integers: \n");
	for(p = a; p < a + N; p++)
	{
		scanf("%d", p);
	}
	
	find_two_largest(a, N, &imax, &ismax, &max, &smax);
	
	printf("The largest:%d\n", max);
	printf("The index of the largest:%d\n", imax);
	printf("The second largest:%d\n", smax);
	printf("The index of the second largest:%d\n", ismax);
	
	return 0;
 } 

void find_two_largest(int a[], int n, int *imax, int *ismax, int *max, int *smax)
{
	int *p = a;
	int *pimax = imax, *pismax = ismax;
	int *pmax = max, *psmax = smax;
	
	*pmax = *psmax = INT_MIN;
	for(p = a; p < a + N; p++)
	{
 		if(*p > *pmax)
 		{
 			*pmax = *p; *pimax = p - a;
		}
	}
 	
 	for(p = a; p < a + *pimax; p++)
 	{
		if(*p > *psmax)
 		{
 			*psmax = *p; *pismax = p - a;
		}
	}
	 
	for(p = a + *pimax + 1; p < a + N; p++)
 	{
		if(*p > *psmax)
 		{
 			*psmax = *p, *pismax = p - a;
		}
	} 
 }
