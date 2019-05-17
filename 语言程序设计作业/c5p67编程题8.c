#include <stdio.h>

int main(void)
{
	int h, min;
	int t;
	int i = 0;                          //³õÊ¼»¯£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
	int choice;
	
	printf("Enter a 24-hour time:\n");
	scanf("%d:%d",&h, &min);
	
	t = h*60 + min;
	
	int time[8] ={8*60, 9*60 + 43, 11*60 +19, 12*60 + 47, 14*60, 15*60 +45, 19*60, 21*60 +45}; 
	 	
	while(1)
	{
	
		if(t< time[0])
		{
			choice = 0;
			break;
		}
		
		
		if(t < time[i])   ///<! 
		{
				
			if (t-time[i-1] > time[i]-t)
			{
				choice = i;
				break;
			}
			else
			{
				choice = i-1;
				break;
			}
	
		}
		i++; 
	}
	
	switch (choice)
	{
		case 0: 
			printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.");
			break;		
		case 1: 
			printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.");
			break;
		case 2: 
			printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.");
			break;
		case 3: 
			printf("Closest departure time is 12:47 a.m., arriving at 3:00 p.m.");
			break;
		case 4: 
			printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.");
			break;
		case 5: 
			printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.");
			break;
		case 6: 
			printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.");
			break;
		case 7: 
			printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.");
			break;
		}
	
	return 0;
} 
