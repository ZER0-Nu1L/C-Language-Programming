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

	//ð������
void bubble (int a[], int n)
{
	int i, j, t;
	int flag = 0;
	
	for(i=0;i<n-1;i++)         // 0 to n-1 �� n ��   �������Ƚ��� ֻ���� n-1�� ���Բ����� n-1����ȡ���� 
	{
	 	for(j=0;j<n-1-i;j++)     // ��ѡ������ͬ��
	 	{                        // һ��ѡ������һ�ֱȽ�����С��������������ǰ�棬���� j �� i+1 to n 
	 		if(a[j]>a[j+1])     //��ð��STEPΪ��ʱ��������С��ð�ݵ�������� j �� 0 to n-1-i  ( a[j]��a[j+1]��Ƚϣ� 
			 {
			 	t = a[j+1] ; a[j+1] = a[j]; a[j] = t;
			 	flag = 1; 
			 } 
		 }
	 	printf("���ǵ�%d�������Ľ����", i+1); 
		print(a,n);
		
		if(flag==0)
			break;
		else
			flag=0;
	}	
	printf("һ������%d��",i+1) ;
}
