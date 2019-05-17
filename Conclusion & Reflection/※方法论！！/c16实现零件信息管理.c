#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part{
	int number;
	char name[NAME_LEN+1];
	int on_hand; 
}inventory[MAX_PARTS];

int  find_part(int number);//Because this funtion will be used in most of function below.
int  readline(char str[], int i);//readline is nesscessary for name input;
void insert(void);
void search(void);
void update(void);
void print(void);

int num_part = 0;

int main(void)
{
   for (;;)
   {
	   char option;
	   printf("Enter operation code: \n");
	   scanf(" %c", &option);
	   switch (option) 
	   {
	     case 'i': insert(); break;
	     case 's': search(); break;
	     case 'u': update(); break;
	     case 'p': print(); break;
	     case 'q': exit(EXIT_SUCCESS); break;
	     default:  printf("Illegal code\n"); break;
	   }
	   printf("\n");  //习惯! 
 }
	
	return 0;
}

/*******************************************************************************
*添加新零件                                                                    * 
*此功能需要用户输入零件编号、名称和初始的现货数量。                            * 
*如果零件已经在数据库中，或者数据库已经满了，那么程序必须显示出错信息。        * 
*******************************************************************************/
int find_part(int number)
{
	int i;
	for (i = 0; i < num_part; i++)
	{
		if (inventory[i].number == number)  //捕捉小小的奇怪的点 
		{
			return i;
		}
	}
	return -1;// 
}

/*******************************************************************************
*添加新零件                                                                    * 
*此功能需要用户输入零件编号、名称和初始的现货数量。                            * 
*如果零件已经在数据库中，或者数据库已经满了，那么程序必须显示出错信息。        * 
*******************************************************************************/ 
void insert(void)
{
	if (num_part == MAX_PARTS)
	{
    printf("Data base is full;can't add more parts.\n");//
    return;
	}
	int part_number;
//	int number, on_hand;
//	char name[LEN_NAME+1];
//	 
//	printf("Enter part number: \n");
//	scanf("%c", &number);
//	printf("Enter part name: \n");
//	scanf("%s", name);
//	printf("Enter quantity on hand: \n");
//	scanf("%n", &on_hand);
//	
//	if(find_part(number) != -1)
//	{
//	    printf("Part already exists.\n");
//	    return;
//	}
	printf("\nEnter part number: ");
	scanf("%d", &part_number);
	if (find_part(part_number) >= 0)
	{
		printf("\nPart already exists.\n");
		return;
	}
	
	inventory[num_part].number = part_number;
	
	printf("\nEnter part name: ");
//	scanf("%s", inventory[num_part].name);
	readline(inventory[num_part].name, NAME_LEN);
	printf("\nEnter quantity on hand: ");
	scanf("%d", &inventory[num_part].on_hand);
	printf("\n");
//	inventory[number].number = number;
//	inventory[number].on_hand = on_hand;
//	strcpy(inventory[number].name , name);
	num_part++;
}

/*******************************************************************************
*查询零件                                                                     * 
*此功能需要用户输入零件编号，然后程序显示出零件的名称和当前的现货数量。       * 
*如果零件编号不在数据库中，那么程序必须显示出错信息。                         * 
*******************************************************************************/ 
void search(void)
{
	int number;
	printf("\nEnter part number: \n");
	scanf("%d", &number);
	
	int i = find_part(number);
	if (i >= 0)
	{
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
	{
		printf("Part not found.\n");		
	}

}

/*******************************************************************************
//修改零件信息
//此功能需要用户输入零件编号，如果零件编号在数据库中，则提示用户输入要改变的零件的数量（比如，5表示增加5个，-4表示减少4个）；
//如果不在数据库中，则程序显示出错信息。
*******************************************************************************/
void update(void)
{
	int number, change;
	
	printf("\nEnter part number: ");
	scanf("%d", &number);
	int i = find_part(number);
	if (i >= 0)
	{
		printf("\nEnter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
	{
		printf("Part not found.\n");
	}
}

void print(void)
{
	int i;
	
	printf("\nPart Number   Part Name        Quantity on Hand\n");
	for (i = 0; i < num_part; i++)
	{
	printf("\n    %d       %-30s%d", inventory[i].number,inventory[i].name, inventory[i].on_hand);
	}
	printf("\n");
}

int readline(char str[], int lenth)
{
	int ch, i = 0;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n' && ch != EOF)
	{
		if(i < lenth)
		{
			str[i++] = ch;
			ch = getchar();
		}
	}
	str[i] = '\0';
	return i;
}
