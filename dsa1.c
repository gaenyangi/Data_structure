#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
	int num;
	char name[20];
	int kor, math, eng, com;
}element; // �л��� ������ ��� ����ü�� element�� ����. ���ο��� �й�, �̸� �׸��� 4������ ������ ����.

typedef struct DListNode {
	struct DListNode* llink;
	element data;
	struct DListNode* rlink;
}DListNode; //���� ���Ḯ��Ʈ�� ���ᱸ�� ����(�ռ� ������ �л�����ü element�� ����ü�� ����, �ڱ������� ���� ���� ��������� ��ũ�� ������ �ڱ���������ü)

void init(DListNode* phead); // �ʱ�ȭ �Լ�
DListNode* dinsert_node(DListNode* before, DListNode* new_node); // insert node
void remove_node(DListNode* phead, DListNode* removed);
void search(DListNode* head, element data); // ���ϴ� �й� �л��� ���� ������ ���
void sort_dinsert(DListNode* head); // �й� ������ ����
void display(DListNode* phead); // ���Ḯ��Ʈ ��ü ���
void free_node(DListNode* phead); // �����Ҵ� �޸� ��ȯ

void init(DListNode* phead) { 
	printf("[Init Doubly List]\n");
	phead->llink = phead;
	phead->rlink = phead; // ���� ���� ����Ʈ�� ������ �ʱ� ���¿��� �� ��ũ ��� �ڱ��ڽ��� ����Ų��.
}

DListNode* dinsert_node(DListNode* before, DListNode* new_node) { // before�� �ְ��� �ϴ� ��ġ�� ���� ���, newnode�� ���� ���ԵǴ� ���.
	new_node->llink = before;
	new_node->rlink = before->rlink; //���Ե� ������� �� ��ũ ����
	before->rlink->llink = new_node; // ���� ����� llink�� ������ ��带 ����Ű�� ����.
	before->rlink = new_node; // ���� ����� rlink�� ������ ��带 ����Ű�� ����.
	printf("\n\n new_node ������ \n\n");
}

void remove_node(DListNode* head, element data) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink){
		if (strcmp(p->data.name,data.name)==0) // �̸��� �̿��Ͽ� ���϶��Ͽ����Ƿ� ���ڿ� �� �Լ� strcmp�� �̿��� ��.
		{
			if (p == head)
			{
				printf("���� ����");
				return;
			}
			p->llink->rlink = p->rlink; //removed�� ����Ű�� ���� ����� rlink�� remove�� ������� �� ���� ���(remove�� rlink�� ����Ű�� ���)�� ����Ŵ.
			p->rlink->llink = p->llink; // ���������� removed ���� ���� removed�� llink�� ����Ű�� ���� llink�� ����Ŵ.
			printf("%s �л� ���� ����", data.name);
			free(p);
			return;
		}
	}
	printf("%s �л� ���� ����", data.name);
}

void search(DListNode* head, element data) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) { // �������Ʈ�� ����Ű�� �� ���� �����ؼ� �ٽ� ���� ���ƿ� �� ���� ������ ��ũ�� ����Ű�� ������ ��� �̵�.
		if (p->data.num == data.num) // Ž���ϴ� ����� data�� ���ϴ� data�� ������ ������ �ݺ�.
		{
			printf("%6d %10s %6d %6d %6d %6d\n",p->data.num,p->data.name,p->data.kor,p->data.math,p->data.eng,p->data.com);
			return; //Ž�������ϸ� ��
		}
	}
	printf("%d �� �л��� ��ȣ �˻� ����\n\n", data.num); // ������ ��� ���.
}

void sort_dinsert(DListNode* head) {
	DListNode* p, * q;
	element tmp;
	for (p = head->rlink; p->rlink != head; p = p->rlink){
		for (q = p->rlink; q != head; q = q->rlink){
			if (q->data.num < p->data.num) 
			{
				tmp = p->data;
				p->data = q -> data;
				q->data = tmp; // �Ϲ������� �ϴ� ���� �񱳿� ����. ����Ʈ���� p,q �׸��� �� ���ؼ� �ڸ��ٲٱ�.
			}
		}
	}
}

void display(DListNode* phead) {
	printf("================================================\n");
	printf("| �� ȣ | �� �� | ��� | ���� | ���� | ��ǻ�� |\n");
	printf("================================================\n");
	for (DListNode* p = phead->rlink; p != phead; p = p->rlink) {
		printf("| %3d | %5s | %4d | %4d | %4d | %5d |\n", p->data.num, p->data.name, p->data.kor, p->data.math, p->data.eng, p->data.com);
	}
	printf("================================================\n");
}

void free_node(DListNode* phead) {
	DListNode* p = phead->rlink, * next;
	while (p != phead) {
		next = p;
		free(p);
		p = p->rlink; // �ϳ��� �����̸� ���� �޸� ����.
	}
}

int main()
{
	FILE* fp;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode)); //head ��� ����. 
	DListNode* tmp; // �ӽ÷� ������ �Է� �޴� ���
	element dat; // �ӽ÷� ������ �Է� �޴� ����ü
	int flag; // �Է¹޴� �޴�

	init(head); // ��� �ʱ�ȭ
	
	fp = fopen("data.txt", "rt"); // ���� ����
	if (fp == NULL) {
		printf("file not found\n");
		return 0;
	}

	while (!feof(fp)) { // ���Ͽ��� �����͸� �Է� �޾� tmp�� ����.
		fscanf(fp, "%d %s %d %d %d %d", &dat.num, dat.name, &dat.kor, &dat.math, &dat.eng, &dat.com);
		printf("%6d %10s %6d %6d %6d %6d\n", dat.num, dat.name, dat.kor, dat.math, dat.eng, dat.com);
		tmp = (DListNode*)malloc(sizeof(DListNode));
		tmp->data = dat;
		dinsert_node(head, tmp);
	}

	while (1)
	{
		printf("\n����(0) �л� ������ �Է�(1) �л� �˻�(2) �л� ����(3) ��� ����(4) \n");
		printf("�޴� �Է� : ");
		scanf("%d", &flag);

		switch (flag)
		{
			case 0:
				exit(1);
				break;
			case 1:
				tmp = (DListNode*)malloc(sizeof(DListNode));
				printf("�߰��� �л� ��ȣ : "); scanf("%d", &dat.num);
				printf("�̸� : "); scanf("%s", &dat.name);
				printf("���� : "); scanf("%d", &dat.kor);
				printf("���� : "); scanf("%d", &dat.math);
				printf("���� : "); scanf("%d", &dat.eng);
				printf("��ǻ�� : "); scanf("%d", &dat.com);
				tmp->data = dat;
				dinsert_node(head, tmp);
				break;
			case 2:
				printf("�˻��� �л� ��ȣ : ");
				scanf("%d", &dat.num);
				search(head, dat);
				break;
			case 3:
				printf("������ �л� �̸� : "); scanf("%s", dat.name);
				remove_node(head, dat);
				break;
			case 4:
				printf("\n<���ĵ� ��� ����>\n\n");
				sort_dinsert(head);
				display(head);
				break;

			default:break;
		}
	}
	free_node(head);
	fclose(fp);
}