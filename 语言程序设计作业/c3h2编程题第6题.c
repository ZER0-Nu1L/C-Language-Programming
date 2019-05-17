#include <stdio.h>

int main ()
{
	int mu1, mu2, mu12, son1, son2, son12 ;
	mu1=mu2=son1=son2=mu12=son12=0;
	
	printf("Enter two fractions separated by a plus sign:");
	scanf("%d/%d+%d/%d",&son1, &mu1, &son2, &mu2);
	
	mu12 = mu1 * mu2;
	son12 = mu1 * son2 + mu2 * son1;
	
	printf(" The sum is %d/%d", son12, mu12);
	
	return 0;
}	
