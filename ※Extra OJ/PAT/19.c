#include<stdio.h> 

int main(void) 
{
	int y, m, d;
	int days = 0;
	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d/%d/%d", &y, &m, &d);
	if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)//∂Ã¬∑Œ Ã‚
		month[2]++;
	
	switch(m)
	{
		case 12: days += month[11];
		case 11: days += month[10];
		case 10: days += month[9];
		case 9:  days += month[8];
		case 8:  days += month[7];
		case 7:  days += month[6];
		case 6:  days += month[5];
		case 5:  days += month[4];
		case 4:  days += month[3];
		case 3:  days += month[2];
		case 2:  days += month[1];break;
	}
	days += d;
	printf("%d", days);
	return 0;
}
