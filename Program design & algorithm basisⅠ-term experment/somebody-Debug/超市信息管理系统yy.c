#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100
#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 30
#define MAX_DISCOUNT_LEN 30
#define DATANAME "GoodInfo"
int CurrentCnt = 0;

typedef struct {
	char	good_id[MAX_ID_LEN];
	char	good_name[MAX_NAME_LEN];
	int  	good_price;
	char	good_discount[MAX_DISCOUNT_LEN];
	int		good_amount;
	int		good_remain;
}GoodInfo;
typedef struct node
{
	GoodInfo data;
	struct node *next;
}GoodList;

bool check_nullfile(void)
{
	FILE *fp = fopen(DATANAME, "r");
	if (!fp) {
		printf("商品信息初始化文件不存在！将新建一个文件.\n");
		FILE *fp = fopen(DATANAME, "w");
		fclose(fp);
		return false;
	}
	else {
		int temp;
		int res = fscanf(fp, "%d", &temp);
		fclose(fp);
		if (res <= 0)
			return false;
		else
			return true;
	}
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

void Goodprint(GoodList *p) {
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("ID:%s\t名称:%s\t价格:%d\t折扣:%s\t数量:%d\t剩余:%d\n", p->data.good_id, p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

}

void info_DestroyGoods(GoodList **L) {
	GoodList* last = *L;
	GoodList* p = *L;
//	for (;; p = p->next) {
//		if (*L == NULL) break;//如果已经是空链表就直接结束
//
//		free(last);
//		last = p;
//		if (!p->next) {
//			free(p);
//			break;
//		}
//	}
	if (*L == NULL) return;//如果已经是空链表就直接结束
	for (; p->next != NULL;) {
		p = p->next;
		free(last);
		last = p;
	}
}

void info_DelAll(GoodList **L) {
	FILE* file = fopen(DATANAME, "w");
	fprintf(file, "");//EOF
	fclose(file);
	info_DestroyGoods(L);
	GoodList* head = *L;
	head->next = NULL;
	*L = NULL;
	printf("删除成功！\n");
	CurrentCnt = 0;
}

void info_init(GoodList **L) {

	if (check_nullfile()) {
		FILE* p = fopen(DATANAME, "r");
		for (; !feof(p);) {
			char id[30];
			char name[30];
			int price;
			char discount[30];
			int amount;
			int remain;
			fscanf(p, "%s\t", id);
			fscanf(p, "%s\t", name);
			fscanf(p, "%d\t", &price);
			fscanf(p, "%s\t", discount);
			fscanf(p, "%d\t", &amount);
			fscanf(p, "%d\n", &remain);
			GoodList* h;
			h = (struct node *)malloc(sizeof(GoodList));
			strcpy(h->data.good_id, id);
			h->data.good_amount = amount;
			strcpy(h->data.good_discount, discount);
			strcpy(h->data.good_name, name);
			h->data.good_price = price;
			h->data.good_remain = remain;
			h->next = NULL;

			GoodList* t = *L;
			if (t == NULL) *L = h;
			else {
				for (; t->next != NULL; )
						t = t->next;
				t->next = h;
			}
			CurrentCnt++;
		}
		fclose(p);
	}
	printf("商品链表文件已建立，有%d个商品记录\n", CurrentCnt);
}

void info_save_and_exit(GoodList **L) {

	FILE* file = fopen(DATANAME, "w");

	GoodList *p = *L;
	for (;; p = p->next) {
		if (*L == NULL) break;
		fprintf(file, "%s\t%s\t%d\t%s\t%d\t%d\n", p->data.good_id, p->data.good_name,
			p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
		if (!p->next) break;
	}
	fclose(file);
	if (CurrentCnt == 0) printf("提示：未写入任何商品信息到商品管理系统.txt文件\n");
	else printf("提示：%d个商品信息存入Goodinfo.txt文件\n", CurrentCnt);

	info_DestroyGoods(L);
	CurrentCnt = 0;
}
void info_displayall(GoodList *L)
{
	if (!L->next) { puts("没有商品信息"); return; };
	GoodList* p = L;
	for (;; p = p->next) {
		if (p == L) continue;
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("ID:%s\t名称:%s\t价格:%d\t折扣:%s\t数量:%d\t剩余:%d\n", p->data.good_id, p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		if (!p->next) break;
	}
}

void info_insert(GoodList **L) {

	GoodList *p = (struct node *) malloc(sizeof(GoodList));
	p->next = NULL; 
	printf("输入你要插入的商品信息:");
	printf("商品id:"); scanf("%s", p->data.good_id);
	GoodList *i = *L;
	for (;; i = i->next) {
		if (i == NULL) break;
		if (strcmp(i->data.good_id, p->data.good_id) == 0) {
			printf("错误！该ID已经存在\n");
			return;
		}
		if (!i->next) break;
	}
	printf("商品名称:"); scanf("%s", p->data.good_name);
	printf("商品价格:"); scanf("%d", &p->data.good_price);
	printf("商品折扣:"); scanf("%s", p->data.good_discount);
	printf("商品数量:"); scanf("%d", &p->data.good_amount);
	printf("商品剩余:"); scanf("%d", &p->data.good_remain);
	printf("请输入数字表明你要插入的商品位置，0.商品列表尾部，1.为商品列表头部，i为商品列表中间第i号位置");
	int pos = 0; scanf("%d", &pos);
	if (pos < 0) {
		printf("error! please put a positive number or zero!");
		return;
	}
	if (pos > CurrentCnt + 1) pos = 0;
	if (pos == 0) {
		GoodList* end = *L;
		if (end == NULL) {
			*L = p;
			printf("插入成功！");
			CurrentCnt++;
			return;
		}

		for (; end != NULL && end->next; end = end->next)
			;
		end->next = p; p->next = NULL;
	}
	else
		if (pos == 1) {
			GoodList* head = *L;
			p->next = head->next;
			head->next = p;
		}
		else {
			GoodList* tmp = *L;
			int i = 0;
			for (; i < pos - 1; i++) tmp = tmp->next;
			p->next = tmp->next;
			tmp->next = p;
		}
	printf("插入成功！");
	CurrentCnt++;

}

void info_dele(GoodList **L) {

	printf("输入需要删除商品ID，-1退出查找");
	char id[30]; scanf("%s", id);
	char ex[30]="-1";

	int flag = 0;
	if (strcmp(id, ex) == 0) return;

	GoodList *last = *L;
	GoodList *p = *L;
	for (;; p = p->next) {
		if (*L == NULL) break;

		if (strcmp(p->data.good_id, id) == 0) {
			printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("ID:%s\t名称:%s\t价格:%d\t折扣:%s\t数量:%d\t剩余:%d\n", p->data.good_id, 
				p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

			printf("是否删除该商品（Y/N）");
			char ch;
			for (ch = getchar(); ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n'; ch = getchar()) 
					puts("Please input Y/N");
			if (ch == 'N' || ch == 'n') return;

			last->next = p->next;
			p->next = NULL;
			free(p);
			p = NULL;

			CurrentCnt--;
			printf("Tips:删除id为%s的商品成功\n", id);
			printf("Tips:现在还有%d个商品信息\n", CurrentCnt);
			flag = 1;
			break;
		}
		last = p;
		if (!p->next) break;
	}
	if (!flag) printf("您要删除的商品不存在！");
	return;
}

void info_search(GoodList *L) {

	puts("输入需要查找的商品名称，-1退出查找");
	char name[30]; scanf("%s", name);
	char ex[30];
	strcpy(ex, "-1");
	int flag = 0;
	if (strcmp(name, ex) == 0) return;
	GoodList *p = L;
	for (;; p = p->next) {
		if (p == L) continue;
		if (strcmp(p->data.good_name, name) == 0) {
			printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("ID:%s\t名称:%s\t价格:%d\t折扣:%s\t数量:%d\t剩余:%d\n",
				p->data.good_id, p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			flag = 1;
			break;
		}
		if (!p->next) break;
	}
	if (!flag) printf("您要查找的商品不存在！");
	return;
}

void info_modify(GoodList **L) {

	puts("输入需要修改商品ID，-1退出查找");
	char id[30]; scanf("%s", id);
	char ex[30];
	strcpy(ex, "-1");
	int flag = 0;
	if (strcmp(id, ex) == 0) return;
	GoodList *p = *L;
	for (;; p = p->next) {
		if (p == *L) continue;
		if (strcmp(p->data.good_id, id) == 0) {
			printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("ID:%s\t名称:%s\t价格:%d\t折扣:%s\t数量:%d\t剩余:%d\n", p->data.good_id, p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("输入新的商品信息:");
			printf("商品id:"); scanf("%s", p->data.good_id);
			printf("商品名称:"); scanf("%s", p->data.good_name);
			printf("商品价格:"); scanf("%d", &p->data.good_price);
			printf("商品折扣:"); scanf("%s", p->data.good_discount);
			printf("商品数量:"); scanf("%d", &p->data.good_amount);
			printf("商品剩余:"); scanf("%d", &p->data.good_remain);
			printf("商品修改成功，修改后的信息为:");
			printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("ID:%s\t名称:%s\t价格:%d\t折扣:%s\t数量:%d\t剩余:%d\n", p->data.good_id, p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			flag = 1;
			break;
		}
		if (!p->next) break;
	}
	if (!flag) printf("您要修改的商品不存在！");
	return;
}

void Bubblesort(GoodList **L) {

	GoodList* head = *L;
	GoodList* cur = NULL;
	GoodList* tail = NULL;
	cur = head->next;
	GoodInfo tmp;
	while (cur != tail) {
		while (cur->next != tail) {
			if (cur->data.good_price > cur->next->data.good_price) {
				tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
		}
		tail = cur;
		cur = head->next;
	}
	printf("当前共有%d个商品", CurrentCnt);
	GoodList* m = head->next;
	for (; m; m = m->next) Goodprint(m);
	return;
}

int main(void)
{
	GoodList *head = NULL;

	info_init(&head);
	for (;;) {
		printf("\n\n\n");
		printf("***************************************************************************\n");
		printf("*                                                                         *\n");
		printf("*                      超市商品管理系统                                   *\n");
		printf("*                                                                         *\n");
		printf("***************************************************************************\n");
		printf("1.显示所有商品信息:\n");
		printf("2.修改某个商品信息:\n");
		printf("3.插入某个商品信息:\n");
		printf("4.删除某个商品信息:\n");
		printf("5.查找某个商品信息:\n");
		printf("6.商品存盘并退出系统:\n");
		printf("7.对商品的价格进行排序:\n");
		printf("8.（慎用）删除所有内容:\n");
		printf("其他.不存盘并退出系统:\n");
		printf("***************************************************************************\n");
		printf("输入您的选择:");
		int i = 0;
		scanf("%d", &i);
		switch (i) {
			case 1:info_displayall(head); break;
			case 2:info_modify(&head); break;
			case 3:info_insert(&head); break;
			case 4:info_dele(&head); break;
			case 5:info_search(head); break;
			case 6:info_save_and_exit(&head); goto End;
			case 7:Bubblesort(&head); break;
			case 8:info_DelAll(&head); break;
			default:info_DestroyGoods(&head); goto End;

			printf("\n***************************************************************************\n");
		}
	}

End:
	system("pause");
	return 0;
}
