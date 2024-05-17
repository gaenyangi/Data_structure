#include<stdio.h> // �ܼ����Ḯ��Ʈ
#include<stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data; //����� ������
	struct ListNode* link; // �ڱ��ڽ��� ����Ű�� �����ͷ� ������带 ����Ŵ = ��ũ
}ListNode;

void insert_node(ListNode **phead,ListNode*p,ListNode*new_node) // ù ��忡 ���Ե� ��� ��������Ͱ� ����ǹǷ� ����������� ������ �ʿ�. ����Ʈ�� ó��, �߰�, ���� ���ԵǴ� ��� �������� �ִ�.
//new_node�� ���ԵǴ� ���, p�� ���� ���, phead�� ����Ʈ�� ����������� ������(����������)
{
	if (*phead == NULL) // ���鸮��Ʈ �ΰ��
	{
		new_node->link = NULL; //���ο� ����Ʈ�� ��������ϱ� ����ų�� ����
		*phead = new_node; // ��������͸� ���ο� ���� ��������.
	}
	else if (p == NULL) // �̹� �ִ� ����Ʈ�� �Ǿտ� ����. ���ʹ� �޸� ����ų �ļ� ��尡 ����
	{
		new_node->link = *phead; // ����尡 ����Ű�� ��ũ�� ���ο� ��尡 ����Ŵ(�Ǿ��̴ϱ�)
		*phead = new_node; // ���������� �Ǿտ� ���ο� ��带 �����Ƿ� ��������ʹ� ���ο� ��带 ����Ŵ.
	}
	else//����Ʈ ���̿� �����ϴ� ���
	{
		new_node->link = p->link; //�����尡 ����Ű�� ���(��ũ)�� ���ο� ��忡 �Ҵ�(�ֳ��ϸ� ���̿� ���� ���ϱ�)
		p->link = new_node; // �׸��� ���� ����� ��ũ�� ���ο� ��带 ����Ű���� ����. 
	}
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed) // �Ǿ� ��� Ȥ�� �߰� ��尡 �����Ǵ� ��� �ΰ���. �� ���� ��¥�� ����Ű�°� �����Ƿ�.
{//���������� p�� ������ ����� ���� ���, removed�� ������ ���
	if (p = NULL) *phead = (*phead)->link; //ù ��� ����
	else p->link = removed->link; //�߰� Ȥ�� ���� ����
	free(removed);
}

void display(ListNode* head) // �ݺ��� �̿��� ����Լ�
{
	ListNode* p = head; // ���Ḯ��Ʈ�� ������ = Ŀ��ó�� �ϳ��� �Űܰ��� ��. ó������ �ؾߵǴϱ� �� Ŀ���� ����� �ּҰ��� �־� ó������ ����. 
	while (p != NULL) //��ũ�� NULL, �� �ļӳ�尡 ���� ����������
	{
		printf("%d->", p->data); //data�� ���
		p = p->link; //���� ��尡 ����Ű�� ��ũ�� ���� ��ũ�� ���� = ���� ��� ���(Ŀ���� �ű�)
	}
	printf("\n");
}

void display2(ListNode* head) // ��͸� �̿��� ����Լ�
{
	ListNode* p = head;
	if (p != NULL)
	{
		printf("%d->", p->link);
		display2(p->link);
	}
}

ListNode* search(ListNode* head, int x) // �� x�� �����ϰ� �ִ� ��� p�� ã�� Ž�� ����. �Լ��� Ÿ���� �Լ��� return ���� ���� ��������. ����ü ListNode�� return �ϸ� ���� ListNode Ÿ������ �Ѵ�.
{
	ListNode* p;
	p = head;
	while (p != NULL)
	{
		if (p->data == x) return p;//Ž�������� ���
		p = p->link;
	}
	return p; //if �� ������� �ʰ� NULL �������� Ž�� ���� = NULL ��ȯ.
}

ListNode* concat(ListNode* head1, ListNode* head2) // �պ�����
{
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1; //�� �� �ϳ��� ����Ʈ�� ���� ����Ʈ�ϰ�� �׳� �ܼ�����
	else
	{
		p = head1;
		while (p->link != NULL) 
		{
			p = p->link;
		}
		p->link = head2; //p�� NULL�� ������, �� head1�� ����Ʈ�� ���� ������ �� ����, �ƹ��͵� ����Ű�°� ���� ������ ��ũ�� ���� ����Ʈ�� ���� ��������.
		return head1; // �� ����Ʈ ���� �� ��������� ��ȯ.
	}
}

ListNode* reverse(ListNode* head) { // ����Ʈ�� ��带 �������� ����� ����.
	ListNode* p, * q, * r;
	p = head; // ó�� ������
	q = NULL; // ������ ������.
	while (p != NULL) {
		r = q; // �� �� ���� �ǵڰ� �ǹǷ� ����Ű�� ���� NULL�� ��.
		q = p;
		p = p->link; //���� ���� �̵�
		q->link = r; //�� ��带 ����Ű�� ��ũ�� �� ��带 ����Ű���� ��ȯ.
	}
	return q; //����ȭ�� ����Ʈ�� ���������
}

int main()
{
	ListNode* p1; //ù ���, p1�� �ּҰ� ��� ������
	p1 = (ListNode*)malloc(sizeof(ListNode)); //�����Ҵ� �� �ռ� ����� ���� ������ ������ �ּҰ��� ����.

	p1->data = 10; //������ ����
	p1->link = NULL; //ó������ ����ų �� ����

	ListNode* p2; //�������
	p2 = (ListNode*)malloc(sizeof(ListNode));

	p2->data = 20;
	p2->link = NULL;
	p1->link = p2; // ù����� ��ũ�� ���� ��带 ����Ŵ
}