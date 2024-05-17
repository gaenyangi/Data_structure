#include<stdio.h> // deque: ���ܰ� �Ĵܿ��� ��� ���� ������ ������ ť. (double ended queue)
#include<stdlib.h>//���ʿ��� ���� ������ �����ؾ� �ϹǷ� �Ϲ������� ���߿��� ����Ʈ ���.

typedef int element; // ����� Ÿ�� ����

typedef struct DlistNode { //����� Ÿ�� ����
	element data;
	struct DlistNode* rlink;
	struct DlistNode* llink;
}DlistNode;

typedef struct DequeType { //���� Ÿ�� ����
	DlistNode* head; // ==front 
	DlistNode* tail; // == rear
}DequeType;

void init(DequeType* dq) { // head,tail ������ �ʱ�ȭ
	dq->head = NULL;
	dq->tail = NULL;
}

int is_empty(DequeType* dq) { // �ϳ� �ִ� ��쿡�� head==tail�̰�, �ΰ� �̻��̸� �׻� head �� �����Ƿ� ��ȯ ����� ������� �Ǻ�����.
	return (dq->head == NULL);
}

DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) { // ���ο� ��� ����(�����ͷ�)
	DlistNode* node = (DlistNode*)malloc(sizeof(DlistNode));
	if (node == NULL) error("�޸��Ҵ����");
	node->llink = llink;
	node->data = item;
	node->rlink = rlink;
	return node; // ������ ����� �ּڰ� ��ȯ
}

void add_front(DequeType* dq, element item) { // �� ���� ���� �Լ�
	DlistNode* new_node = create_node(NULL, item, dq->head); // ���ܿ� ���� �ϹǷ� ����带 �����ؼ� ���� ��ũ�� ����, �Ĵ� ��ũ�� ������ ���� ����
	if (is_empty(dq)) dq->tail = new_node; // ���� ���鸮��Ʈ�̸� front==rear�̹Ƿ� dq->tail�� �� ���� ��������.
	else dq->head->llink = new_node; //������ �� �տ� �ִ� ����� llink�� ���ο� ���� ����
	dq->head = new_node; //head �����͸� �� ������ �Ű���
}

void add_rear(DequeType* dq, element item) { // �� �Ĵ� ���� �Լ�
	DlistNode* new_node = create_node(dq->tail, item, NULL); // �ռ��� ���������� ����� ����. �̹����� llink�� tail, rlink�� ����
	if (is_empty(dq)) dq->head = new_node; // ���� ������� �ռ��� ���������� head==rear
	else dq->tail->rlink = new_node; // ������ ������ ����� rlink�� ���� ���ԵǴ� ���� ����
	dq->tail = new_node; //tail �����͸� �� �ڷ� �Ű���

}

element delete_front(DequeType* dq) {// ���� �� �տ��� ����
	element item;
	DlistNode* removed_node;
	if (is_empty(dq)) error("���� ������ ����");
	else {
		removed_node = dq->head; // �Ǿ� �ּڰ� ����
		item = removed_node->data;
		dq->head = dq->head->rlink; //��������͸� �� �տ��� �״��� ���� �ű�
		free(removed_node); //�޸� �Ҵ� ���� 
		if (dq->head == NULL) dq->tail = NULL; //������ ��尡 ����Ʈ�� ������ ����� ��� head=tail==NULL
		else dq->head->llink = NULL; // �װ� �ƴ϶�� �� �� ����� llink�� NULL.
	}
	return item;//������ �׸� ��ȯ.
}

element delete_rear(DequeType* dq) { // ���� �� �ڿ��� ����
	element item;
	DlistNode* removed_node;
	if (is_empty(dq)) error("���� ������ ����");
	else {
		removed_node = dq->tail; //�� ������ �ּڰ� ��ȯ
		item = removed_node->data; // �� ������ ������ ��ȯ
		dq->tail = dq->tail->llink; // ������ ����� �ٷ� ���� ��� �ּڰ����� tail �ű�.
		free(removed_node); // ������ �� �޸� ����
		if (dq->tail == NULL)dq->head = NULL; // �ռ��� �����ϰ� �����ϰ� ���� ���鸮��Ʈ�� �Ǵ� ���
		else dq->tail->rlink = NULL; // �װ� �ƴϸ� �� ������ ����� rlink�� NULL
	}
	return item;
}

