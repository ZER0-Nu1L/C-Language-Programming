#include<stdio.h>
int main(void)
{
	char *descri[6] = { "Calm","Light air","Breeze","Gale","Storm","Hurricane" };
	int speed;
	int choose;

	printf("Enter a wind speed: ");
	scanf("%d", &speed);

	if (speed < 1)
		choose = 0;
	else if (speed < 4)
		choose = 1;
	else if (speed < 28)
		choose = 2;
	else if (speed < 48)
		choose = 3;
	else if (speed < 64)
		choose = 4;
	else
		choose = 5;

	printf("%s\n", descri[choose]);

	return 0;
}

