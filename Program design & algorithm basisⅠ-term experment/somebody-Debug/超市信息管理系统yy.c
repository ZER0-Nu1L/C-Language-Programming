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
		printf("��Ʒ��Ϣ��ʼ���ļ������ڣ����½�һ���ļ�.\n");
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
	printf("ID:%s\t����:%s\t�۸�:%d\t�ۿ�:%s\t����:%d\tʣ��:%d\n", p->data.good_id, p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

}

void info_DestroyGoods(GoodList **L) {
	GoodList* last = *L;
	GoodList* p = *L;
//	for (;; p = p->next) {
//		if (*L == NULL) break;//����Ѿ��ǿ������ֱ�ӽ���
//
//		free(last);
//		last = p;
//		if (!p->next) {
//			free(p);
//			break;
//		}
//	}
	if (*L == NULL) return;//����Ѿ��ǿ������ֱ�ӽ���
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
	printf("ɾ���ɹ���\n");
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
	printf("��Ʒ�����ļ��ѽ�������%d����Ʒ��¼\n", CurrentCnt);
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
	if (CurrentCnt == 0) printf("��ʾ��δд���κ���Ʒ��Ϣ����Ʒ����ϵͳ.txt�ļ�\n");
	else printf("��ʾ��%d����Ʒ��Ϣ����Goodinfo.txt�ļ�\n", CurrentCnt);

	info_DestroyGoods(L);
	CurrentCnt = 0;
}
void info_displayall(GoodList *L)
{
	if (!L->next) { puts("û����Ʒ��Ϣ"); return; };
	GoodList* p = L;
	for (;; p = p->next) {
		if (p == L) continue;
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("ID:%s\t����:%s\t�۸�:%d\t�ۿ�:%s\t����:%d\tʣ��:%d\n", p->data.good_id, p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		if (!p->next) break;
	}
}

void info_insert(GoodList **L) {

	GoodList *p = (struct node *) malloc(sizeof(GoodList));
	p->next = NULL; 
	printf("������Ҫ�������Ʒ��Ϣ:");
	printf("��Ʒid:"); scanf("%s", p->data.good_id);
	GoodList *i = *L;
	for (;; i = i->next) {
		if (i == NULL) break;
		if (strcmp(i->data.good_id, p->data.good_id) == 0) {
			printf("���󣡸�ID�Ѿ�����\n");
			return;
		}
		if (!i->next) break;
	}
	printf("��Ʒ����:"); scanf("%s", p->data.good_name);
	printf("��Ʒ�۸�:"); scanf("%d", &p->data.good_price);
	printf("��Ʒ�ۿ�:"); scanf("%s", p->data.good_discount);
	printf("��Ʒ����:"); scanf("%d", &p->data.good_amount);
	printf("��Ʒʣ��:"); scanf("%d", &p->data.good_remain);
	printf("���������ֱ�����Ҫ�������Ʒλ�ã�0.��Ʒ�б�β����1.Ϊ��Ʒ�б�ͷ����iΪ��Ʒ�б��м��i��λ��");
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
			printf("����ɹ���");
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
	printf("����ɹ���");
	CurrentCnt++;

}

void info_dele(GoodList **L) {

	printf("������Ҫɾ����ƷID��-1�˳�����");
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
			printf("ID:%s\t����:%s\t�۸�:%d\t�ۿ�:%s\t����:%d\tʣ��:%d\n", p->data.good_id, 
				p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

			printf("�Ƿ�ɾ������Ʒ��Y/N��");
			char ch;
			for (ch = getchar(); ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n'; ch = getchar()) 
					puts("Please input Y/N");
			if (ch == 'N' || ch == 'n') return;

			last->next = p->next;
			p->next = NULL;
			free(p);
			p = NULL;

			CurrentCnt--;
			printf("Tips:ɾ��idΪ%s����Ʒ�ɹ�\n", id);
			printf("Tips:���ڻ���%d����Ʒ��Ϣ\n", CurrentCnt);
			flag = 1;
			break;
		}
		last = p;
		if (!p->next) break;
	}
	if (!flag) printf("��Ҫɾ������Ʒ�����ڣ�");
	return;
}

void info_search(GoodList *L) {

	puts("������Ҫ���ҵ���Ʒ���ƣ�-1�˳�����");
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
			printf("ID:%s\t����:%s\t�۸�:%d\t�ۿ�:%s\t����:%d\tʣ��:%d\n",
				p->data.good_id, p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			flag = 1;
			break;
		}
		if (!p->next) break;
	}
	if (!flag) printf("��Ҫ���ҵ���Ʒ�����ڣ�");
	return;
}

void info_modify(GoodList **L) {

	puts("������Ҫ�޸���ƷID��-1�˳�����");
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
			printf("ID:%s\t����:%s\t�۸�:%d\t�ۿ�:%s\t����:%d\tʣ��:%d\n", p->data.good_id, p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("�����µ���Ʒ��Ϣ:");
			printf("��Ʒid:"); scanf("%s", p->data.good_id);
			printf("��Ʒ����:"); scanf("%s", p->data.good_name);
			printf("��Ʒ�۸�:"); scanf("%d", &p->data.good_price);
			printf("��Ʒ�ۿ�:"); scanf("%s", p->data.good_discount);
			printf("��Ʒ����:"); scanf("%d", &p->data.good_amount);
			printf("��Ʒʣ��:"); scanf("%d", &p->data.good_remain);
			printf("��Ʒ�޸ĳɹ����޸ĺ����ϢΪ:");
			printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("ID:%s\t����:%s\t�۸�:%d\t�ۿ�:%s\t����:%d\tʣ��:%d\n", p->data.good_id, p->data.good_name, p->data.good_price, p->data.good_discount, p->data.good_amount, p->data.good_remain);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			flag = 1;
			break;
		}
		if (!p->next) break;
	}
	if (!flag) printf("��Ҫ�޸ĵ���Ʒ�����ڣ�");
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
	printf("��ǰ����%d����Ʒ", CurrentCnt);
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
		printf("*                      ������Ʒ����ϵͳ                                   *\n");
		printf("*                                                                         *\n");
		printf("***************************************************************************\n");
		printf("1.��ʾ������Ʒ��Ϣ:\n");
		printf("2.�޸�ĳ����Ʒ��Ϣ:\n");
		printf("3.����ĳ����Ʒ��Ϣ:\n");
		printf("4.ɾ��ĳ����Ʒ��Ϣ:\n");
		printf("5.����ĳ����Ʒ��Ϣ:\n");
		printf("6.��Ʒ���̲��˳�ϵͳ:\n");
		printf("7.����Ʒ�ļ۸��������:\n");
		printf("8.�����ã�ɾ����������:\n");
		printf("����.�����̲��˳�ϵͳ:\n");
		printf("***************************************************************************\n");
		printf("��������ѡ��:");
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
