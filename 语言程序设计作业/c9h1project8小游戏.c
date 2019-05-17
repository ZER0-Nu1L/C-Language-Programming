#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

int roll_dice(void);
bool play_game(void);
//---------------------------------------------------
//主界面 
//---------------------------------------------------
int main(void)
{
	bool game;
	int win = 0, lose = 0;
	char ch;
	srand( (unsigned int) time(NULL) );
	
	do
	{
		game = play_game();//一定要加括号！！！ 
		if (game)
		{
			printf("You win!\n\n");
			win++;
		}
		else
		{
			printf("You lose!\n\n");
			lose++;
		}
		
		printf("Play again?");
		scanf(" %c", &ch);
		ch = toupper(ch);
		printf("\n");
	}while(ch == 'Y');
	
	printf("Wins: %d   Losses: %d\n", win, lose);
	
	return 0;
 } 
//---------------------------------------------------
//产生随机数（两个骰子数值之和 ）
//--------------------------------------------------- 
int roll_dice(void)
{
	int a, b;
	//srand( (unsigned int) time(NULL) );
	a = rand() % 6 + 1;
	b = rand() % 6 + 1;
	
	return a+b;
}
//---------------------------------------------------
//进行游戏 
//---------------------------------------------------
 bool play_game(void)
{
	int rnd;
	
	rnd = roll_dice();
	
	switch (rnd)
	{
		case 11: case 7:
			printf("You rolled: %d\n", rnd);
			return true;
			break;
		case 2: case 3:case 12:
			printf("You rolled: %d\n", rnd);
			return false;
			break;
		default:
			printf("You rolled: %d\n", rnd);
			printf("You pointis %d\n", rnd);
			while(1)
			{
				rnd = roll_dice();
				switch (rnd)
				{
					case 1 :case 4 :case 5 :case 6 :case 8 :case 9 :case 10 :
						printf("You rolled: %d\n", rnd);
						return true;
						break;
					case 7:
						printf("You rolled: %d\n", rnd);
						return false;
						break;
				}
			}	
			break;
	}
}
