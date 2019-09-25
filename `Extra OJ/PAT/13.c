#include<stdio.h>

int main(void)
{
	int day;
	scanf("%d", &day);
	if(day == 5)
		printf("%d", 7 );
	else
		printf("%d", (day + 2) % 7 );
	return 0;
}
