#include<stdio.h>
#include<string.h>

#define MAX_REMIND 6
#define MSG_LEN 80

struct reminder{
	unsigned short date;
	char message[MSG_LEN+1];
}remind[MAX_REMIND];

void print(struct reminder remind[], int number);
void select(struct reminder remind[], int number);
int read_line(char str[], int n);

int main(void)
{
	int number = 0;
	
	while(1)
	{
		printf("Enter day and reminder: \n\n");
		scanf("%2hu", &remind[number].date);
		read_line(remind[number].message, MSG_LEN);
		if(remind[number].date == 0)
		{
			break;
		}
		number++;
	}
	select(remind, number);
	print(remind, number);
	return 0;
}

void print(struct reminder remind[], int number)
{
	int i;
	printf("Day Reminder\n");
	for(i = 0; i < number; i++)
	{
		printf("%3hu%s\n", remind[i].date, remind[i].message );
	}
}

void select(struct reminder remind[], int number)
{
	if(number == 1)return;
	
	int i, imax = 0;
	struct reminder temp;
	for(i = 1; i < number; i++)
	{
		if(remind[i].date > remind[imax].date )
		{
			imax = i;
		}
	}
	temp = remind[number-1]; remind[number-1] = remind[imax]; remind[imax] = temp;
	select(remind, number - 1);
}

int read_line(char str[], int n)
{
	int i = 0, ch;
	
	while((ch = getchar()) != '\n' && i < n)
	{
		str[i] = ch;
		i++;
	}
	str[i] = '\0';
	return i;
}
