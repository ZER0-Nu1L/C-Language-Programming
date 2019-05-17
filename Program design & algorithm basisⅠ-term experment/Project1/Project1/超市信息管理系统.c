#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//#include "readline.h"
//文件名
#define DATAFILE "database" //get√
//商品的最大数量
#define MAX 100
//全局变量，存储当前商品的数量
int CurrentCnt = 0;
//------------------------------------------------------------------------------
#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_DISCOUNT_LEN 30

typedef struct {
	char	goods_id[MAX_ID_LEN];
	char	goods_name[MAX_NAME_LEN+1];
	int   	goods_price;
	char 	goods_discount[MAX_DISCOUNT_LEN];
	int		goods_amount;
	int		goods_remain;
} GoodsInfo;
//------------------------------------------------------------------------------
typedef struct node {
	GoodsInfo data;
	struct node *next;
} GoodsList;
//------------------------------------------------------------------------------
//定义函数指针
void(*funprt)(GoodsList**itemdb);

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
bool check_nullfile(void);
void Goodsprint(GoodsList *itemdb);
void freeGoodInfo(GoodsList **itemdb);

void init_itemdb(GoodsList **itemdb);
//------------------------------------------------------------------------------
//主界面以及八个功能模块
void main_interface();
void OutputAll(GoodsList **itemdb);
void info_change(GoodsList **itemdb);
void info_insert(GoodsList **itemdb);
void info_dele(GoodsList **itemdb);
void info_search(GoodsList **itemdb);
void save_and_exit(GoodsList ** itemdb);
void bubble_sort(GoodsList **itemdb);
void DelAll(GoodsList **itemdb);

//------------------------------------------------------------------------------
//主函数
int main(void)
{
	GoodsList * itemdb = NULL;
	int choice = 0;

	//if ((itemdb =(GoodsList *) malloc(sizeof(GoodsList))) == NULL)
	//{
	//	printf("Error in setting up a list!\n");
	//	exit(EXIT_FAILURE);
	//}

	init_itemdb(&itemdb);

	while (1)
	{
		main_interface();
		choice = 0;
		printf("请输入您的选择：");
		scanf_s("%d", &choice, 1);

		while (getchar() != '\n')//get√
			;

		switch (choice)
		{
		case 1:funprt = OutputAll;
			break;
		case 2:funprt = info_change;
			break;
		case 3:funprt = info_insert;
			break;
		case 4:funprt = info_dele;
			break;
		case 5:funprt = info_search;
			break;
		case 6:funprt = save_and_exit;
			break;
		case 7:funprt = bubble_sort;
			break;
		case 8:funprt = DelAll;
			break;
		default: goto End;
			break;
		}
		(*funprt)(&itemdb);                      //使用函数指针，满足程序单一入口的原则
		printf("\n");//get√
	}
End:;
	return 0;
}
//------------------------------------------------------------------------------
//主界面 输出
void main_interface()//怎么做成流动式的？
{
	printf(
		"***************************************************\n"
		"*                超市商品管理系统                 *\n"
		"***************************************************\n"
		"1、显示所有商品的信息:\n"
		"2、修改某个商品的信息:\n"
		"3、插入某个商品的信息:\n"
		"4、删除某个商品的信息:\n"
		"5、查找某个商品的信息:\n"
		"6、商品的存盘并退出系统\n"
		"7、对商品的价格进行排序\n"
		"8、(慎用)删除所有内容\n"
		"其他.不存盘并退出系统\n"
		"***************************************************\n"
	);
}

//------------------------------------------------------------------------------
//输出一个商品的信息 
void Goodsprint(GoodsList *list)
{
	printf("商品ID：%4s  ", list->data.goods_id);
	printf("商品名称：%6s  ", list->data.goods_name);
	printf("商品价格：%3d  ", list->data.goods_price);
	printf("商品折扣：%4s  ", list->data.goods_discount);
	printf("商品数量：%4d  ", list->data.goods_amount);
	printf("商品余数：%4d\n", list->data.goods_remain);
}
//------------------------------------------------------------------------------
//删除所有数据
void DelAll(GoodsList **itemdb)
{
	char judge;
	printf("\n你确定要删除所有数据吗？(Y/S)\n");
	scanf_s(" %c", &judge, 1);
	judge = toupper(judge);

	while (judge != 'N' && judge != 'Y')
	{
		printf("请输入正确地指令！\n");
		printf("你确定要删除所有数据吗？(Y/N)\n");
		scanf_s(" %c", &judge, 1);
		judge = toupper(judge);
	}
	if (judge == 'N')
	{
		return;
	}
	else if( judge == 'Y')
	{
		GoodsList * p1 = *itemdb;
		GoodsList * p2 = p1;
		while (p1 != NULL)
		{
			p2 = p2->next;
			free(p1);                                                  //
			p1 = p2;
		}
		CurrentCnt = 0;
		*itemdb = NULL;
		printf("商品信息已经全部删除！\n");   //
	}
}
//------------------------------------------------------------------------------
//输出所有数据
void OutputAll(GoodsList **itemdb)
{
	if (*itemdb == NULL)
	{
		printf("目前没有商品信息！\n");
		return ;
	}
	GoodsList *list;
	printf("++++++++++++++++++++++++++++++++++++++++++++++++"
		"+++++++++++++++++++++++++++++++++++++++++++++++\n");
	for (list = *itemdb;list != NULL; list = list->next)
	{
		Goodsprint(list);
		printf("++++++++++++++++++++++++++++++++++++++++++++++++"
		     "+++++++++++++++++++++++++++++++++++++++++++++++\n");
	}
}
//------------------------------------------------------------------------------
//插入一项新的商品信息
//副作用：全局变量CurrentCnt++
void info_insert(GoodsList **itemdb)
{
	GoodsList *cur = NULL, *prev = NULL;
	GoodsList *new_node;
	char insert_name[MAX_NAME_LEN+1];//只是申明为指针出现问题（野指针)

	//规定数据上限
	if (CurrentCnt == MAX)
	{
		printf("Database is full!\n");
		exit(EXIT_FAILURE);
	}
	else if ((new_node = (GoodsList *)malloc(sizeof(GoodsList))) == NULL)
	{
		printf("Error in mallocating!\n");
		exit(EXIT_FAILURE);
	}

	printf("输入你要插入的商品的名称：\n");
	scanf_s("%s", insert_name, MAX_NAME_LEN);

	if (*itemdb == NULL)
	{
		goto insert;
	}

	for (prev = NULL, cur = *itemdb;
		cur != NULL && strcmp(cur->data.goods_name, insert_name) != 0; //strcmp 写成 strcpy
		prev = cur, cur = cur->next)
		;

insert:
	if (cur == NULL)
	{
		strcpy(new_node->data.goods_name, insert_name);
		printf("输入你要插入的商品的ID：    ");   scanf_s("%s", new_node->data.goods_id, MAX_ID_LEN);
		printf("输入你要插入的商品的价格：  ");   scanf_s("%d", &new_node->data.goods_price, 1);
		printf("输入你要插入的商品的折扣：  ");   scanf_s("%s", new_node->data.goods_discount, MAX_DISCOUNT_LEN);
		printf("输入你要插入的商品的总量：  ");   scanf_s("%d", &new_node->data.goods_amount, 1);
		printf("输入你要插入的商品的剩余量：");   scanf_s("%d", &new_node->data.goods_remain, 1);
	}
	else if (strcpy(cur->data.goods_name, insert_name) == 0)
	{
		printf("该商品已经存在！\n");
		free(new_node);
		return;
	}

	new_node->next = *itemdb;
	*itemdb = new_node;
	printf("\n商品信息插入成功！\n");
	CurrentCnt++;
	//new_node = cur;
	//if (prev == NULL)
	//	*itemdb = new_node;
	//else
	//	prev->next = new_node;
}

//------------------------------------------------------------------------------
//删除一项商品信息
////副作用：全局变量CurrentCnt--
void info_dele(GoodsList **itemdb)
{
	GoodsList *cur, *prev;
	char insert_name[MAX_NAME_LEN+1];
	char judge;

	if (CurrentCnt == 0)
	{
		printf("Database is empty!\n");
		exit(EXIT_FAILURE);
	}

	printf("输入你要删除的商品的名称：\n");
	scanf_s("%s", insert_name, MAX_NAME_LEN);

	for (prev = NULL, cur = *itemdb;
		cur != NULL && strcmp(cur->data.goods_name, insert_name) != 0;
		prev = cur, cur = cur->next)
		;

	if (strcmp(cur->data.goods_name, insert_name) != 0)
	{
		printf("该商品不存在！\n");
		return;
	}

	Goodsprint(cur);
	printf("确定要删除此商品信息吗？(Y/N)\n");
	scanf_s(" %c", &judge, 1);
	judge = toupper(judge);

	while (judge != 'N' && judge != 'Y')
	{
		printf("请输入正确地指令！\n");
		printf("你确定要删除所有数据吗？(Y/N)\n");
		scanf_s(" %c", &judge, 1);
		judge = toupper(judge);
	}
	if (judge == 'N')
	{
		return;
	}
	else if (judge == 'Y')
	{
		if (prev == NULL)
		{
			*itemdb = cur->next;
		}
		else
		{	
			prev->next = cur->next;
		}
		free(cur);
		printf("\n商品信息删除成功！\n");
		CurrentCnt--;
	}

}
//------------------------------------------------------------------------------
//查找商品信息
void info_search(GoodsList **itemdb)
{
	GoodsList *p;
	char insert_name[MAX_NAME_LEN+1];

	printf("输入你要查找的商品的名称：\n");
	scanf_s("%s", insert_name, MAX_NAME_LEN);
	for (p = *itemdb;
		p != NULL && strcmp(p->data.goods_name, insert_name) != 0;
		p = p->next)
		;

	if (p == NULL)
	{
		printf("该商品不存在！\n");
		return;
	}
	Goodsprint(p);
}

//------------------------------------------------------------------------------
//对商品信息进行更新
void info_change(GoodsList **itemdb)
{
	GoodsList *p;
	char insert_name[MAX_NAME_LEN+1];

	printf("输入你要修改的商品的名称：(输入\"back\"退出修改)\n");
	scanf_s("%s", insert_name, MAX_NAME_LEN);

	if (strcmp("back", insert_name) == 0)
	{
		return;
	}

	for (p = *itemdb;
		p != NULL && strcmp(p->data.goods_name, insert_name) != 0;
		p = p->next)
		;

	if (p == NULL)
	{
		printf("该商品不存在！\n");
		return;
	}

	printf("输入修改后的商品的价格：  ");   scanf_s("%d", &p->data.goods_price, 1);
	printf("输入修改后的商品的折扣：  ");   scanf_s("%s", p->data.goods_discount, MAX_DISCOUNT_LEN);
	printf("输入修改后的商品的总量：  ");   scanf_s("%d", &p->data.goods_amount, 1);
	printf("输入修改后的商品的剩余量：");   scanf_s("%d", &p->data.goods_remain, 1);
	printf("\n商品信息修改成功！\n");
}
//------------------------------------------------------------------------------
//根据商品的价格对商品进行排序
void bubble_sort(GoodsList **itemdb)
{
	bool flag = false;
	int count = 0;
	GoodsList *first, *second;
	GoodsInfo temp_value;

	first = *itemdb;
	while (first != NULL)
	{
		count++;
		first = first->next;
	}

	for (int i = 1; i < count; i++)
	{
		first = *itemdb;
		second = (*itemdb)->next;//优先级
		for (int j = 0; j < count - i; j++)
		{
			if (first->data.goods_price > second->data.goods_price)
			{
				temp_value = second->data;
				second->data = first->data;
				first->data = temp_value;
				flag = true;
			}
			first = first->next;
			second = second->next;
		}
		if (flag)
			flag = false;
		else
			break;
	}
	printf("排序完成！\n");
}
//------------------------------------------------------------------------------
//检查文件是否存在或者是否为空
//如果文件存在，就试读一个数据，看文件是不是空的 返回值表示是否文件为空。
//如果文件不存在，就新建一个
bool check_nullfile(void)
{
	FILE *fp = fopen(DATAFILE, "r");
	int temp;	//temp用来试读一个文件中的数据
	int res;	//res接收fscanf的返回值，如果是true，表示文件有内容不空，反之为空
	 //如果文件不存在
	if (!fp) {                                                                       //*大概明白 
		printf("商品信息初始化文件不存在！程序将为您新建一个.\n");
		FILE *fp = fopen(DATAFILE, "w");
		fclose(fp);
	}
	//如果文件存在，就试读一个数据，看文件是不是空的
		res = fscanf(fp, "%d", &temp);
		fclose(fp);
		if (res <= 0)
			return false;
		else
			return true;

}
//------------------------------------------------------------------------------
//链表初始化函数
//完成从一个二进制文件读入商品链表库
void init_itemdb(GoodsList **itemdb)
{
	GoodsList *pitem;
	FILE * fp;
	
	bool res = check_nullfile();   //调用check_nullfile()函数检查文件是否存在或者是否为空

	if ((fp = fopen(DATAFILE, "rb")) == NULL)
	{
		printf("商品信息初始化文件不存在！程序将为您新建一个.\n");
		FILE *fp = fopen(DATAFILE,"wb"); 

	}

	while (1)
	{
		if ((pitem = (GoodsList *)malloc(sizeof(GoodsList))) == NULL)
		{
			printf("Error in mallocating!\n");
			exit(EXIT_FAILURE);
		}

		if (fread(pitem, sizeof(GoodsList), 1, fp) == 1 && res)
		{
			pitem->next = *itemdb;
			*itemdb = pitem;
			CurrentCnt++;
		}
		else
			break;
	}
	printf("商品的链表文件已经建立，有%d条记录\n", CurrentCnt);
	fclose(fp);
}
//------------------------------------------------------------------------------
//释放动态分配的内存
void freeGoodInfo(GoodsList **itemdb)
{
	GoodsList *p = NULL;
	while (p != NULL)
	{
		p = (*itemdb)->next;
		free(*itemdb);
		*itemdb = p;
	}
	CurrentCnt = 0;
}
//------------------------------------------------------------------------------
//对商品信息进行存盘
void save_and_exit(GoodsList ** itemdb)
{
	FILE *fp;
	GoodsList *p = NULL;

	if (itemdb == NULL)
	{
		printf("the linked list is empty!\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(DATAFILE, "wb")) == NULL)
	{
		perror("File open error:");
		exit(EXIT_FAILURE);
	}

	p = *itemdb;
	while (*itemdb != NULL)
	{
		if (fwrite(*itemdb, sizeof(GoodsList), 1, fp) == 1)
		{
			*itemdb = (*itemdb)->next;
		}
	}

	fclose(fp);
	printf("\n|存盘成功！\n");

	*itemdb = p;
	//释放内存
	freeGoodInfo(&itemdb);

	exit(EXIT_SUCCESS);
}