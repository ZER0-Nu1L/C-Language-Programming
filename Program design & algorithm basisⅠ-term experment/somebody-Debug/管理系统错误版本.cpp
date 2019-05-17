#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_DISCOUNT_LEN 30
int currentCnt = 0;//ȫ�ֱ������洢��ǰ��Ʒ������

typedef struct {
	char id[MAX_ID_LEN];
	char name[MAX_NAME_LEN];
	char discount[MAX_DISCOUNT_LEN];

	int price;
	int amount;
	int remain;
} Goods;

typedef struct node {
	Goods info;
	struct node *next;
} GoodsList;
GoodsList *list = NULL, *list_last = NULL;//����Ŀ�ͷ�ͽ�β��ȫ�ֱ����Ŀ�ʼ����Ϊnull 


char s[180];//��������
void freeGoodInfo(GoodsList **L)
{
	GoodsList *p = NULL;
	while (p != NULL)
	{
		p = (*L)->next;
		free(*L);
		*L = p;
	}
	currentCnt = 0;
}
void save_and_exit(GoodsList ** L)
{
	FILE *fp;
	GoodsList *p = NULL;

	if (L == NULL)
	{
		printf("the linked list is empty!\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen("goodsinfo.txt", "wb")) == NULL)
	{
		perror("File open error:");
		exit(EXIT_FAILURE);
	}

	p = *L;
	while (*L != NULL)
	{
		if (fwrite(*L, sizeof(GoodsList), 1, fp) == 1)
		{
			*L = (*L)->next;
		}
	}

	fclose(fp);
	printf("\n|���̳ɹ���\n");

	*L = p;
	//�ͷ��ڴ�
	freeGoodInfo(L);

	exit(EXIT_SUCCESS);
}



void outputMenu()
{
	puts("*******************************************");
	puts("1. ��ʾ������Ʒ����Ϣ��");
	puts("2. �޸�ĳ����Ʒ����Ϣ��");
	puts("3. ����ĳ����Ʒ����Ϣ��");
	puts("4. ɾ��ĳ����Ʒ����Ϣ��");
	puts("5. ����ĳ����Ʒ����Ϣ��");
	puts("6. ��Ʒ���̲��˳�ϵͳ��");
	puts("7. ����Ʒ�۸��������");
	puts("8. �����ã�ɾ���������ݣ�");
	puts("����. �����̲��˳�ϵͳ��");
	puts("*******************************************");
	return;
}

void jianlishuzu(GoodsList **L, GoodsList **LL)
{
	GoodsList *p;

	*L = (GoodsList *)malloc(sizeof(GoodsList));

	p = *L;
	p->next = NULL;

	FILE *fp = fopen("goodsinfo.txt", "r");

	if (fp == NULL)
	{
		printf("��Ʒ��Ϣ��ʼ���ļ������ڣ�����Ϊ���½�һ����\n");
		fclose(fp);
		fp = fopen("goodsinfo.txt", "w");
		fclose(fp);
		*LL = p;
		return;
	}

	while (1)
	{
		if (fgets(s, 180, fp) == NULL) break;
		int i, t = 0;

		for (i = 0; s[i] >= 32; i++) p->info.id[t++] = s[i];
		p->info.id[t++] = '\0'; t = 0;

		for (i++; s[i] != '\t'; i++) p->info.name[t++] = s[i];
		p->info.name[t++] = '\0'; t = 0;

		p->info.price = 0;
		for (i++; s[i] >= 32; i++) p->info.price = p->info.price * 10 + s[i] - '0';

		for (i++; s[i] >= 32; i++) p->info.discount[t++] = s[i];
		p->info.discount[t++] = '\0'; t = 0;

		p->info.amount = 0;
		for (i++; s[i] >= 32; i++) p->info.amount = p->info.amount * 10 + s[i] - '0';

		p->info.remain = 0;
		for (i++; s[i] >= 32; i++) p->info.remain = p->info.remain * 10 + s[i] - '0';

		++currentCnt;

		p->next = (GoodsList *)malloc(sizeof(GoodsList));
		p = p->next;
		p->next = NULL;
	}

	*LL = p;
	printf("��Ʒ�������ļ��ѽ������� %d ����Ʒ��¼��\n", currentCnt);

	fclose(fp);
	return;
}
void read_line(char s[], int n)
{
	char ch; int i = 0;
	while ((ch = getchar()) < 32)
	{
		if (ch == EOF)
		{
			s[i] = '\0';
			return;
		}
	}
	s[i++] = ch;
	while ((ch = getchar()) >= 32 && i < n) s[i++] = ch;
	s[i] = '\0';
	return;
}

void printOneInfo(Goods a)
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("ID��%s\t���ƣ�%s\t�۸�%d\t�ۿۣ�%s\t������%d\tʣ�ࣺ%d", a.id, a.name, a.price, a.discount, a.amount, a.remain);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	return;
}

void printAllInfo(GoodsList *L)
{
	int i;
	for (i = 0; i < currentCnt; i++)
	{
		printOneInfo(L->info);
		L = L->next;
	}
	return;
}

void readItem(Goods *a)
{
	puts("�����µ���Ʒ��Ϣ��");
	printf("��Ʒ ID��"); read_line(a->id, 30);
	printf("��Ʒ���ƣ�"); read_line(a->name, 30);
	printf("��Ʒ�۸�"); scanf("%d", &a->price);
	printf("��Ʒ�ۿۣ�"); read_line(a->discount, 30);
	printf("��Ʒ������"); scanf("%d", &a->amount);
	printf("��Ʒʣ�ࣺ"); scanf("%d", &a->remain);
	return;
}

void infoChange(GoodsList **L)
{
	int i = 0, f = 0;
	GoodsList *p = *L;

	printf("������Ҫ�޸ĵ���Ʒ ID��-1 �˳��޸ģ���");
	read_line(s, 30);

	if (s[0] == '-' && s[1] == '1' && s[2] == '\0') return;

	while (i < currentCnt)
	{
		if (strcmp(p->info.id, s) == 0)
		{
			f = 1;
			break;
		}
		p = p->next;
		i++;
	}

	if (!f)
	{
		puts("��Ҫ�޸ĵ���Ʒ�����ڣ�");
		return;
	}

	readItem(&p->info);

	puts("�޸���Ʒ��Ϣ�ɹ����޸ĺ����ƷΪ��");
	printOneInfo(p->info);

	return;
}

void infoInsert(GoodsList **L, GoodsList **LL)
{
	Goods a; int position, i;
	readItem(&a);

err:
	printf("���������Ա�ʾ��Ҫ�������Ʒλ�ã�0. ��Ʒ�б�β�� 1. ��Ʒ�б�ͷ�� 2. ��Ʒ�б��м�� i ��λ�ã�");
	scanf("%d", &position);

	if (!position)
	{
		(*LL)->info = a;
		(*LL)->next = (GoodsList*)malloc(sizeof(GoodsList));
		(*LL) = (*LL)->next;
		(*LL)->next = NULL;
		++currentCnt;
		return;
	}

	if (position == 1)
	{
		GoodsList *nHead = (GoodsList*)malloc(sizeof(GoodsList));
		nHead->info = a;
		nHead->next = *L;
		*L = nHead;
		++currentCnt;
		return;
	}

	GoodsList *p = *L, *nItem;
	nItem = (GoodsList*)malloc(sizeof(GoodsList));
	nItem->info = a;
	nItem->next = NULL;

	for (i = 1; i < position - 1; i++)
	{
		if (p->next == NULL)
		{
			puts("δ�ҵ���λ�ã����������룡");
			goto err;
		}
		else p = p->next;
	}

	nItem->next = p->next;
	p->next = nItem;
	++currentCnt;
	return;
}

void infoDelete(GoodsList **L)
{
	char option[3];
	int f = 0;
	GoodsList *p = *L, *q;

	printf("������Ҫɾ������Ʒ ID��-1 �˳�ɾ������");
	read_line(s, 30);

	if (s[0] == '-' && s[1] == '1' && s[2] == '\0') return;

	if (strcmp((*L)->info.id, s) == 0)
	{
		printOneInfo((*L)->info);
		puts("�Ƿ�ɾ������Ʒ����Y/N����");
		scanf("%s", option);
		if (option[0] == 'N' || option[0] == 'n') return;
		else if (option[0] == 'Y' || option[0] == 'y')
		{
			p = p->next;
			free(*L);
			*L = p;
			currentCnt--;
			printf("Tips: ɾ�� ID Ϊ %s ����Ʒ�ɹ���", s);
			printf("Tips: ��ǰʣ����Ʒ %d ����\n", currentCnt);
			return;
		}
		else
		{
			puts("���Ϸ������룡");
			return;
		}
	}

	while ((p->next) != list_last)
	{
		if (strcmp((p->next)->info.id, s) == 0)
		{
			f = 1;
			break;
		}
		p = p->next;
	}

	if (!f)
	{
		puts("��Ҫɾ������Ʒ�����ڣ�");
		return;
	}

	printOneInfo((p->next)->info);
	puts("�Ƿ�ɾ������Ʒ����Y/N����");
	scanf("%s", option);

	if (option[0] == 'N' || option[0] == 'n') return;
	else if (option[0] == 'Y' || option[0] == 'y')
	{
		q = p;
		p = p->next;
		q->next = p->next;
		free(p);
		currentCnt--;
		printf("Tips: ɾ�� ID Ϊ %s ����Ʒ�ɹ���", s);
		printf("Tips: ��ǰʣ����Ʒ %d ����\n", currentCnt);
	}
	else puts("���Ϸ������룡");
	return;
}

void infoSearch(GoodsList *L)
{
	GoodsList *p = L;

	printf("������Ҫ���ҵ���Ʒ���ƣ�-1 �˳����ң���");
	read_line(s, 30);

	if (s[0] == '-' && s[1] == '1' && s[2] == '\0') return;

	while (p != list_last)
	{
		if (strcmp(p->info.id, s) == 0)
		{
			printOneInfo(p->info);
			return;
		}
		p = p->next;
	}

	puts("��Ҫ���ҵ���Ʒ�����ڣ�");
	return;
}

void deleteAll(GoodsList **L)
{
	GoodsList *q;

	while ((*L) != NULL)
	{
		q = (*L)->next;
		free(*L);
		*L = q;
	}

	*L = NULL;
	list_last = NULL;
	currentCnt = 0;
	return;
}



void bubbleSort(GoodsList **L)
{
	int i, j;

	if (currentCnt <= 1) return;

	for (i = 0; i < currentCnt; i++)
	{
		GoodsList *p = *L, *q = (*L)->next, *r;

		if (p->info.price > q->info.price)
		{
			p->next = q->next;
			q->next = p;
			*L = q;
		}

		p = *L;

		for (j = 1; j < currentCnt - i - 1; j++)
		{
			q = p->next;
			r = q->next;

			if (q->info.price > r->info.price)
			{
				q->next = r->next;
				r->next = q;
				p->next = r;
			}

			p = p->next;
		}
	}
	return;
}



int main()
{
	jianlishuzu(&list, &list_last);
	puts("������Ʒ����ϵͳ");
	while (1)
	{
		int option;

		outputMenu();
		printf("��������ѡ��");
		scanf("%d", &option);

		switch (option)
		{
		case 1: printAllInfo(list); break;
		case 2: infoChange(&list); break;
		case 3: infoInsert(&list, &list_last); break;
		case 4: infoDelete(&list); break;
		case 5: infoSearch(list); break;
		case 6: save_and_exit(&list); return 0;
		case 7: bubbleSort(&list); break;
		case 8: deleteAll(&list); break;
		default: return 0;
		}
	}
	return 0;
}
