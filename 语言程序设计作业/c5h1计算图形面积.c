#include <stdio.h>

int main(void)
{
	int choice;
	float edge_length, height, length, width, edge_top, edge_bottom, height2, r;
	const float PI =3.1415 ;
	
	printf("Please choose a shape you want to calculate (triangle 1, rectangle 2, ladder 3, circle 4):\n");
	scanf("%d",&choice);
	
	switch (choice)
	{
	
		case 1: 
		{
			printf("\nYour choice is triangle. Please input the edge_length and height:");
			scanf("%f %f",&edge_length , &height);
			printf("\n\narea is: %.4f",0.5*edge_length*height);
		};
		break;
		case 2: 
		{
			printf("\nYour choice is rectangle. Please input the length and width:");
			scanf("%f %f",&length , &width);
			printf("\n\narea is: %.4f",length*width);
		};
		break;
		case 3: 
		{
			printf("\nYour choice is ladder. Please input the edge_top, edge_bottom, and height: ");
			scanf("%f %f %f",&edge_top , &edge_bottom, &height2);
			printf("\n\narea is: %.4f",(edge_top+edge_bottom) *height2*0.5);
		};
		break;
		case 4: 
		{
			printf("\nYour choice is circle. Please input the radium:");
			scanf("%f",&r);
			printf("\n\narea is: %.4f",r*r*PI);
		};
		break;
	}

	return 0;
}
