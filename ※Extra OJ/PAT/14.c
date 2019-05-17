#include<stdio.h> 

int main(void)
{
	int time, add;
	int h, min;
	int sum;
	scanf("%d %d", &time, &add);
	h = time / 100;
	min = time % 100;//
	sum = min + h * 60;
	sum += add;
	
	min = sum % 60;
	h = sum / 60;
	printf("%d%02d", h, min);//
	return 0;
}
