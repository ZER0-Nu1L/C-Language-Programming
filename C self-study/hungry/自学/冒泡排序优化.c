#include <stdio.h>

void print(int *p, int n);
void bubble (int a[], int n);

int main (void)
{
	int n;
	int i, j, imin, t; 
	int a[12];
	
	printf("Enter a number as the number of array: \n");
	scanf("%d",&n);
	freopen("C:\\Users\\wcb53\\Desktop\\.txt", "r", stdin);
	printf("Enter numbers as the members of array: \n");
	for (i=0;i<=n-1;i++)
	scanf(" %d",&a[i]);
		
	bubble(a,n);
	
	print(a,n);
	
	return 0;
}


void print(int *p, int n)
{
	int i;
	
	for (i=0;i<=n-1;i++)   
	{
		printf("%4d", *(p+i));	
	}
	printf("\n");
	
	return ;
}

	//冒泡排序
void bubble (int a[], int n)
{
	int i, j, t;
	int flag = 0;
	
	for(i=0;i<n-1;i++)         // 0 to n-1 有 n 个   在两两比较中 只会有 n-1轮 所以不妨令 n-1不可取到。 
	{
	 	for(j=0;j<n-1-i;j++)     // 与选择排序不同，
	 	{                        // 一般选择排序将一轮比较重最小或最大的数放在最前面，所以 j 是 i+1 to n 
	 		if(a[j]>a[j+1])     //而冒泡STEP为正时，最大或最小会冒泡到最后，所以 j 是 0 to n-1-i  ( a[j]和a[j+1]相比较） 
			 {
			 	t = a[j+1] ; a[j+1] = a[j]; a[j] = t;
			 	flag = 1; 
			 } 
		 }
	 	printf("这是第%d次排序后的结果：", i+1); 
		print(a,n);
		
		if(flag==0)
			break;
		else
			flag=0;
	}	
	printf("一共排序%d次",i+1) ;
}
