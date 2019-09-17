#include <stdio.h>
#include <stdlib.h>

void print(int *p, int n);
void choose (int *p, int n);


int main (void)
{
	int n, *p;

	printf("Enter a number as the number of array: \n");
	scanf("%d",&n);
	
	if((p = (int*)calloc(n, sizeof(int)))== NULL)
	{
		printf("Not able to allocate memory.\n"); 
		exit(1);
	}
	
	printf("Enter numbers as the members of array: \n");
	for (int i=0;i<=n-1;i++)
	scanf("%d",p+i);

    choose (p, n);
	 
	print (p, n);
	
	free (p);
	
	return 0;
}


void print(int *p, int n)
{
	for (int i=0;i<=n-1;i++)    
	{
		printf("%6d", *(p+i));	
	}
	printf("\n");
	return ;
}

void choose (int *p, int n)
{
	int imin, t; 
	for(int i=0;i<n-1;i++)
	 {
	 	imin = i;
	 	for(int j=i+1;j<=n-1;j++)
	 	{
	 		if(p[imin]>p[j])
			 {
			 	t = imin ; imin = j; j = t;
			 } 
		 }
		 t=p[imin];p[imin]=p[i];p[i]=t;
		 
	 	printf("这是第%d次排序后的结果：", i+1); 
		print(p,n);
	 }
	
	return;
}
