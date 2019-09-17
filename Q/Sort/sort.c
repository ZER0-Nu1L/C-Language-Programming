#include<stdio.h>
#include<stdbool.h>
#include<memory.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100
#define MIN 1

void select_Descending(int a[], int n);
void select_Ascending(int a[], int n);
void select_recurrence(int a[], int n);
void bublle_Descending(int a[], int n);
void bublle_Ascending(int a[], int n);
void quick(int a[], int low, int high);
int split(int a[], int low, int high);
void sort(int a[], int left, int right);

void print(int a[], int n);
void assignment(int a[], int n);


int main(void)                                                                       //Q��ô���Ժ�������
{
	srand( (unsigned int) time(NULL) );
	int n;
	printf("Enter the number of the array:");
	scanf("%d", &n);
	int a[n], t[n];
	
	assignment(a, n);
	memcpy(t, a, sizeof(a));
	print(t, n);	
	
	char choice;
	printf("Ascending or Descending?(A or D)\n");
	scanf(" %c", &choice);
	choice = toupper(choice);
	
	OPTION:
	switch (choice)
	{
		case 'D':
			printf("The array:\n");
			
			select_Descending(t, n);                          //������switch�Ż� 
			print(t, n);                           //�������ÿ�ε����򣬱Ƚ� 
			memcpy(t, a, sizeof(a));

			bublle_Descending(t, n);
			print(t, n);
			memcpy(t, a, sizeof(a));
			break; 
		case 'A':
			printf("The array:\n");
			
			select_Ascending(t, n);                          //������switch�Ż� 
			print(t, n);                           //�������ÿ�ε����򣬱Ƚ� 
			memcpy(t, a, sizeof(a));
						
			bublle_Ascending(t, n);
			print(t, n);
			memcpy(t, a, sizeof(a));
			break; 
		default:
			printf("Please enter the acceptable character!\n");
			goto OPTION;
			break;
	}
	
	quick(t, 0, n - 1);
	print(t, n);
	memcpy(t, a, sizeof(a));

	sort(t, 0, n - 1);
	print(t, n);
	memcpy(t, a, sizeof(a));
	
	return 0;
}

void print(int a[], int n)
{	
	for (int i = 0; i < n; i++)   
	{
		printf("%4d", a[i]);	
	}
	printf("\n");
}
void assignment(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		a[i] = rand() % MAX + MIN;
	}
}
//-------------������ֻ��Ҫ�ı�max��min�زɼ���ʽ----------------------------- 
void select_Descending(int a[], int n)
{
	int max_index, temp;                  //��������һ��max,��a[max_index]����max��
	for(int i = 0; i < n - 1; i++)
	{
		max_index = i;
		for(int j = i + 1; j < n; j++)
		{
			if(a[max_index] < a[j])
			{
				max_index = j;
			}
		}
		temp = a[max_index]; a[max_index] = a[i]; a[i] = temp;
	}
} 
void select_Ascending(int a[], int n)
{
	int min_index, temp;                  //��������һ��max,��a[max_index]����max��
	for(int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for(int j = i + 1; j < n; j++)
		{
			if(a[min_index] > a[j])
			{
				min_index = j;
			}
		}
		temp = a[min_index]; a[min_index] = a[i]; a[i] = temp;
	}
} 
//-------������ֻ��Ҫ�ı佻���Ƚϴ�С�ķ��ţ��Ķ�ʱ�ο�"��"�ķ���-------------
void bublle_Descending(int a[], int n)
{
	bool flag = false;
	int temp;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)//n - 1���������һ�i��ʾλ���Ѿ�ȷ����Ԫ�ظ���;������I = 0 ���м��� 
		{
			if(a[j] < a[j + 1])
			{
				temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
				flag = true;
			}
		 } 
		 if(flag)
		 	flag = false;		 
		 else
		 	break;
	}
}
void bublle_Ascending(int a[], int n)
{
	bool flag = false;
	int temp;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)//n - 1���������һ��
		{
			if(a[j] > a[j + 1])
			{
				temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
				flag = true;
			}
		 } 
		 if(flag)
		 {
		 	flag = false;
		 }
		 else
		 {
		 	break;
		 }
	}
 } 
 
 void quick(int a[], int low, int high)
{
	int mid = split(a, low, high);
	
	if(low >= high)return;
	quick(a, low, mid - 1);
	quick(a, mid + 1, high);
}

void sort(int a[], int left, int right)
{
    if(left >= right)/*�������������ڻ��ߵ����ұߵ������ʹ����Ѿ��������һ������*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
     
    while(i < j)                               /*�����ڵ�����Ѱ��һ��*/
    {
        while(i < j && key <= a[j])
        {
            j--;
        }         
        a[i] = a[j];
         
        while(i < j && key >= a[i])
        {
            i++;
        }         
        a[j] = a[i];
    }
     
    a[i] = key;/*���ڵ���������һ���Ժ�Ͱ��м���key�ع�*/
    sort(a, left, i - 1);/*�����ͬ���ķ�ʽ�Էֳ�������ߵ�С�����ͬ�ϵ�����*/
    sort(a, i + 1, right);/*��ͬ���ķ�ʽ�Էֳ������ұߵ�С�����ͬ�ϵ�����*/
                       /*��Ȼ�����ܻ���ֺܶ�����ң�ֱ��ÿһ���i = j Ϊֹ*/
}

int split(int a[], int low, int high)
{
	int part_element = a[low];
	
	while(1)
	{
		while(low < high && part_element <= a[high])  //a[high] >= part_element
		{
			high--;
		}
		if(low >= high)break;
		a[low++] = a[high];
		
		while(low < high && a[low] <= part_element)
		{
			low++;
		}
		if(low >= high)break;
		a[high--] = a[low];
	}
	a[high] = part_element;
	return high;
}
//һЩ����������ȼ�����
//�ݹ鷨
//1��2��������ֵ�ķ���λ�� 
//����ԭ����������Ҳ���Խ���ֵ���ں���3����δ��� 
void select_recurrence1(int a[], int n)
{
	if(n == 1)return;                     // ��ֹ����
	
	int temp, max_index = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[max_index] < a[i])
		{
			max_index = i;
		}
	}
	temp = a[0];a[0] = a[max_index]; a[max_index] = temp;//����ֵ������ǰ���λ�ã�Ȼ��ָ�루���飩�����ƶ�һλ
	
	select_recurrence1(a + 1, n - 1);
}
void select_recurrence2(int a[], int n)
{
	if(n == 1)return;                       //���岻�� 
	
	int temp, max_index = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[max_index] < a[i])
		{
			max_index = i;
		}
	}
	temp = a[n-1];a[n-1] = a[max_index]; a[max_index] = temp;//����ֵ�ŵ�����ȥ 
		
	select_recurrence2(a, n - 1);
}

void select_end(int a[], int n)
{
	int min_index, temp;                  //��������һ��max,��a[max_index]����max��
	for(int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for(int j = i + 1; j < n; j++)
		{
			if(a[min_index] > a[j])
			{
				min_index = j;
			}
		}
		temp = a[min_index]; a[min_index] = a[n-1-i]; a[n-1-i] = temp;
	}
}
