#include<stdio.h>
int main(void)
{
	int in;

	printf("Enter numerical grade: ");
	scanf("%d", &in);

	if (in > 100 || in < 0)
	{
		printf("Error, grade must be between 0 and 100.\n");
		return -1;
	}

	switch ((in - in % 10) / 10)
	{
	case 10:
	case 9:
		puts("Letter Grade: A");
		break;
	case 8:
		puts("Letter Grade: B");
		break;
	case 7:
		puts("Letter Grade: C");
		break;
	case 6:
		puts("Letter Grade: D");
		break;
	default:
		puts("Letter Grade: F");
	}

	return 0;
}

