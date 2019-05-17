#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
	int h_12;
	int min;
	int h_24;
	char *time;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &h_24, &min);

	if(h_24==0)
		h_12=12;
	else if(h_24<=12)
		h_12=h_24;
	else if(h_24<24)
		h_12=h_24-12;
	else
		h_12=h_24-12;
	
	
	if(h_24<12)
		time="AM";
	else if(h_24<24)
		time="PM";
	else
		time="PM";
	
	
	printf("Equivalent 12-hour time: %d:%02d %s\n", h_12, min, time);

	return 0;
}