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


int main(void)                                                                       //Q怎么调试函数？！
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
			
			select_Descending(t, n);                          //可以用switch优化 
			print(t, n);                           //可以输出每次的排序，比较 
			memcpy(t, a, sizeof(a));

			bublle_Descending(t, n);
			print(t, n);
			memcpy(t, a, sizeof(a));
			break; 
		case 'A':
			printf("The array:\n");
			
			select_Ascending(t, n);                          //可以用switch优化 
			print(t, n);                           //可以输出每次的排序，比较 
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
//-------------升序降序只需要改变max与min地采集方式----------------------------- 
void select_Descending(int a[], int n)
{
	int max_index, temp;                  //不用再设一个max,用a[max_index]代替max；
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
	int min_index, temp;                  //不用再设一个max,用a[max_index]代替max；
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
//-------升序降序只需要改变交换比较大小的符号，阅读时参考"令"的方法-------------
void bublle_Descending(int a[], int n)
{
	bool flag = false;
	int temp;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)//n - 1是数列最后一项，i表示位置已经确定的元素个数;可以用I = 0 进行检验 
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
		for(int j = 0; j < n - i - 1; j++)//n - 1是数列最后一项
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
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
     
    while(i < j)                               /*控制在当组内寻找一遍*/
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
     
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
                       /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
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
//一些其他方案与等价例子
//递归法
//1、2区别于最值的放置位置 
//而在原来的排序中也可以将最值放在后面3、、未完成 
void select_recurrence1(int a[], int n)
{
	if(n == 1)return;                     // 终止条件
	
	int temp, max_index = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[max_index] < a[i])
		{
			max_index = i;
		}
	}
	temp = a[0];a[0] = a[max_index]; a[max_index] = temp;//把最值放在最前面的位置，然后将指针（数组）往后移动一位
	
	select_recurrence1(a + 1, n - 1);
}
void select_recurrence2(int a[], int n)
{
	if(n == 1)return;                       //主体不变 
	
	int temp, max_index = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[max_index] < a[i])
		{
			max_index = i;
		}
	}
	temp = a[n-1];a[n-1] = a[max_index]; a[max_index] = temp;//把最值放到后面去 
		
	select_recurrence2(a, n - 1);
}

void select_end(int a[], int n)
{
	int min_index, temp;                  //不用再设一个max,用a[max_index]代替max；
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
