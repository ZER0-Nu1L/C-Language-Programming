#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//#include "readline.h"
//�ļ���
#define DATAFILE "database" //get��
//��Ʒ���������
#define MAX 100
//ȫ�ֱ������洢��ǰ��Ʒ������
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
//���庯��ָ��
void(*funprt)(GoodsList**itemdb);

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
bool check_nullfile(void);
void Goodsprint(GoodsList *itemdb);
void freeGoodInfo(GoodsList **itemdb);

void init_itemdb(GoodsList **itemdb);
//------------------------------------------------------------------------------
//�������Լ��˸�����ģ��
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
//������
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
		printf("����������ѡ��");
		scanf_s("%d", &choice, 1);

		while (getchar() != '\n')//get��
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
		(*funprt)(&itemdb);                      //ʹ�ú���ָ�룬�������һ��ڵ�ԭ��
		printf("\n");//get��
	}
End:;
	return 0;
}
//------------------------------------------------------------------------------
//������ ���
void main_interface()//��ô��������ʽ�ģ�
{
	printf(
		"***************************************************\n"
		"*                ������Ʒ����ϵͳ                 *\n"
		"***************************************************\n"
		"1����ʾ������Ʒ����Ϣ:\n"
		"2���޸�ĳ����Ʒ����Ϣ:\n"
		"3������ĳ����Ʒ����Ϣ:\n"
		"4��ɾ��ĳ����Ʒ����Ϣ:\n"
		"5������ĳ����Ʒ����Ϣ:\n"
		"6����Ʒ�Ĵ��̲��˳�ϵͳ\n"
		"7������Ʒ�ļ۸��������\n"
		"8��(����)ɾ����������\n"
		"����.�����̲��˳�ϵͳ\n"
		"***************************************************\n"
	);
}

//------------------------------------------------------------------------------
//���һ����Ʒ����Ϣ 
void Goodsprint(GoodsList *list)
{
	printf("��ƷID��%4s  ", list->data.goods_id);
	printf("��Ʒ���ƣ�%6s  ", list->data.goods_name);
	printf("��Ʒ�۸�%3d  ", list->data.goods_price);
	printf("��Ʒ�ۿۣ�%4s  ", list->data.goods_discount);
	printf("��Ʒ������%4d  ", list->data.goods_amount);
	printf("��Ʒ������%4d\n", list->data.goods_remain);
}
//------------------------------------------------------------------------------
//ɾ����������
void DelAll(GoodsList **itemdb)
{
	char judge;
	printf("\n��ȷ��Ҫɾ������������(Y/S)\n");
	scanf_s(" %c", &judge, 1);
	judge = toupper(judge);

	while (judge != 'N' && judge != 'Y')
	{
		printf("��������ȷ��ָ�\n");
		printf("��ȷ��Ҫɾ������������(Y/N)\n");
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
		printf("��Ʒ��Ϣ�Ѿ�ȫ��ɾ����\n");   //
	}
}
//------------------------------------------------------------------------------
//�����������
void OutputAll(GoodsList **itemdb)
{
	if (*itemdb == NULL)
	{
		printf("Ŀǰû����Ʒ��Ϣ��\n");
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
//����һ���µ���Ʒ��Ϣ
//�����ã�ȫ�ֱ���CurrentCnt++
void info_insert(GoodsList **itemdb)
{
	GoodsList *cur = NULL, *prev = NULL;
	GoodsList *new_node;
	char insert_name[MAX_NAME_LEN+1];//ֻ������Ϊָ��������⣨Ұָ��)

	//�涨��������
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

	printf("������Ҫ�������Ʒ�����ƣ�\n");
	scanf_s("%s", insert_name, MAX_NAME_LEN);

	if (*itemdb == NULL)
	{
		goto insert;
	}

	for (prev = NULL, cur = *itemdb;
		cur != NULL && strcmp(cur->data.goods_name, insert_name) != 0; //strcmp д�� strcpy
		prev = cur, cur = cur->next)
		;

insert:
	if (cur == NULL)
	{
		strcpy(new_node->data.goods_name, insert_name);
		printf("������Ҫ�������Ʒ��ID��    ");   scanf_s("%s", new_node->data.goods_id, MAX_ID_LEN);
		printf("������Ҫ�������Ʒ�ļ۸�  ");   scanf_s("%d", &new_node->data.goods_price, 1);
		printf("������Ҫ�������Ʒ���ۿۣ�  ");   scanf_s("%s", new_node->data.goods_discount, MAX_DISCOUNT_LEN);
		printf("������Ҫ�������Ʒ��������  ");   scanf_s("%d", &new_node->data.goods_amount, 1);
		printf("������Ҫ�������Ʒ��ʣ������");   scanf_s("%d", &new_node->data.goods_remain, 1);
	}
	else if (strcpy(cur->data.goods_name, insert_name) == 0)
	{
		printf("����Ʒ�Ѿ����ڣ�\n");
		free(new_node);
		return;
	}

	new_node->next = *itemdb;
	*itemdb = new_node;
	printf("\n��Ʒ��Ϣ����ɹ���\n");
	CurrentCnt++;
	//new_node = cur;
	//if (prev == NULL)
	//	*itemdb = new_node;
	//else
	//	prev->next = new_node;
}

//------------------------------------------------------------------------------
//ɾ��һ����Ʒ��Ϣ
////�����ã�ȫ�ֱ���CurrentCnt--
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

	printf("������Ҫɾ������Ʒ�����ƣ�\n");
	scanf_s("%s", insert_name, MAX_NAME_LEN);

	for (prev = NULL, cur = *itemdb;
		cur != NULL && strcmp(cur->data.goods_name, insert_name) != 0;
		prev = cur, cur = cur->next)
		;

	if (strcmp(cur->data.goods_name, insert_name) != 0)
	{
		printf("����Ʒ�����ڣ�\n");
		return;
	}

	Goodsprint(cur);
	printf("ȷ��Ҫɾ������Ʒ��Ϣ��(Y/N)\n");
	scanf_s(" %c", &judge, 1);
	judge = toupper(judge);

	while (judge != 'N' && judge != 'Y')
	{
		printf("��������ȷ��ָ�\n");
		printf("��ȷ��Ҫɾ������������(Y/N)\n");
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
		printf("\n��Ʒ��Ϣɾ���ɹ���\n");
		CurrentCnt--;
	}

}
//------------------------------------------------------------------------------
//������Ʒ��Ϣ
void info_search(GoodsList **itemdb)
{
	GoodsList *p;
	char insert_name[MAX_NAME_LEN+1];

	printf("������Ҫ���ҵ���Ʒ�����ƣ�\n");
	scanf_s("%s", insert_name, MAX_NAME_LEN);
	for (p = *itemdb;
		p != NULL && strcmp(p->data.goods_name, insert_name) != 0;
		p = p->next)
		;

	if (p == NULL)
	{
		printf("����Ʒ�����ڣ�\n");
		return;
	}
	Goodsprint(p);
}

//------------------------------------------------------------------------------
//����Ʒ��Ϣ���и���
void info_change(GoodsList **itemdb)
{
	GoodsList *p;
	char insert_name[MAX_NAME_LEN+1];

	printf("������Ҫ�޸ĵ���Ʒ�����ƣ�(����\"back\"�˳��޸�)\n");
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
		printf("����Ʒ�����ڣ�\n");
		return;
	}

	printf("�����޸ĺ����Ʒ�ļ۸�  ");   scanf_s("%d", &p->data.goods_price, 1);
	printf("�����޸ĺ����Ʒ���ۿۣ�  ");   scanf_s("%s", p->data.goods_discount, MAX_DISCOUNT_LEN);
	printf("�����޸ĺ����Ʒ��������  ");   scanf_s("%d", &p->data.goods_amount, 1);
	printf("�����޸ĺ����Ʒ��ʣ������");   scanf_s("%d", &p->data.goods_remain, 1);
	printf("\n��Ʒ��Ϣ�޸ĳɹ���\n");
}
//------------------------------------------------------------------------------
//������Ʒ�ļ۸����Ʒ��������
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
		second = (*itemdb)->next;//���ȼ�
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
	printf("������ɣ�\n");
}
//------------------------------------------------------------------------------
//����ļ��Ƿ���ڻ����Ƿ�Ϊ��
//����ļ����ڣ����Զ�һ�����ݣ����ļ��ǲ��ǿյ� ����ֵ��ʾ�Ƿ��ļ�Ϊ�ա�
//����ļ������ڣ����½�һ��
bool check_nullfile(void)
{
	FILE *fp = fopen(DATAFILE, "r");
	int temp;	//temp�����Զ�һ���ļ��е�����
	int res;	//res����fscanf�ķ���ֵ�������true����ʾ�ļ������ݲ��գ���֮Ϊ��
	 //����ļ�������
	if (!fp) {                                                                       //*������� 
		printf("��Ʒ��Ϣ��ʼ���ļ������ڣ�����Ϊ���½�һ��.\n");
		FILE *fp = fopen(DATAFILE, "w");
		fclose(fp);
	}
	//����ļ����ڣ����Զ�һ�����ݣ����ļ��ǲ��ǿյ�
		res = fscanf(fp, "%d", &temp);
		fclose(fp);
		if (res <= 0)
			return false;
		else
			return true;

}
//------------------------------------------------------------------------------
//�����ʼ������
//��ɴ�һ���������ļ�������Ʒ�����
void init_itemdb(GoodsList **itemdb)
{
	GoodsList *pitem;
	FILE * fp;
	
	bool res = check_nullfile();   //����check_nullfile()��������ļ��Ƿ���ڻ����Ƿ�Ϊ��

	if ((fp = fopen(DATAFILE, "rb")) == NULL)
	{
		printf("��Ʒ��Ϣ��ʼ���ļ������ڣ�����Ϊ���½�һ��.\n");
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
	printf("��Ʒ�������ļ��Ѿ���������%d����¼\n", CurrentCnt);
	fclose(fp);
}
//------------------------------------------------------------------------------
//�ͷŶ�̬������ڴ�
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
//����Ʒ��Ϣ���д���
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
	printf("\n|���̳ɹ���\n");

	*itemdb = p;
	//�ͷ��ڴ�
	freeGoodInfo(&itemdb);

	exit(EXIT_SUCCESS);
}