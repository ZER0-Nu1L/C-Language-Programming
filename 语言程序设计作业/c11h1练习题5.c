#include<stdio.h>
#include<math.h>

void split_time(long int total, int *hr, int *min, int *sec);

int main(void)
{
	long int total;
	int sec, min, hr;
	
	printf("Enter total seconds:\n");
	scanf("%ld", &total);
	
	split_time(total, &hr, &min, &sec);
	
	printf(
	"Time:\n"
	"%2d:%2d:%d"
	, hr, min, sec); 
	
	return 0;
}

void split_time(long int total, int *hr, int *min, int *sec)
{
	*sec = total % 60;
	total /= 60;
	*min = total % 60;
	total /= 60;
	*hr = total % 24;
}
