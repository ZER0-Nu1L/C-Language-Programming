#include"acllib.h"
#include<stdio.h>

int Setup()
{
	initConsole();
	printf("������");
	int width;
	scanf("%d", &width);
	initWindow("test", 100, 100, width, 200);
	beginPaint();
	line(20, 20, width-20, width-20);
	endPaint();
	return 0;
}
