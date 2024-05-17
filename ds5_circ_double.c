#include<stdio.h> // ���� ���� ����Ʈ. ������ ����� ��ũ�� �ٽ� ù ��带 ����Ű�� ����Ʈ. ��ȯ�ϹǷ� �� ��忡�� ��� ���� ������ ����. 
//�Ϲ������� ��� �����Ͱ� ������ ��带 ����Ű���� �����ϸ� ����Ʈ�� ó�� �� �������� �����ϴ� ������ �ܼ����Ḯ��Ʈ���� ����(�������� �پ��)
typedef struct {
	int data;
	ListNode* link;
}ListNode;
void insert_first(ListNode** phead, ListNode* node) { //�������Ḯ��Ʈ ó������. ��������ʹ� ������ ��带 ����Ŵ.
	if (*phead == NULL) { //���� ����Ʈ �̹Ƿ� ���� ���� ��带, ����� ��ũ�� ����ų�� ������ �����̹Ƿ� �ڱ��ڽ����� �ٽ� ����.
		*phead = node;
		node->link = NULL;
	}
	else {
		node->link = (*phead)->link; //��ó���̰� ����, ���� �� �������̹Ƿ� ��������Ͱ� ����Ű�� ����� ��ũ�� �Ǿ�. ���� ���ο� ����� ��ũ�� �Ǿ��̾��� ��带 �⸮Ŵ.
		(*phead)->link = node; //���ο� ��尡 �� ���̹Ƿ� �� �� ����� ��ũ ����
	}
}

void insert_last(ListNode** phead, ListNode* node) {//�������Ḯ��Ʈ ���� ����
	if (*phead == NULL){ // ���������� ���鸮��Ʈ�� �հ� ����.
		*phead = node;
		node->link = node; 
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node; // �Ǿ��̴� �� �ڴ� ����Ű�� ��ũ ������ ����
		*phead = node; // ����������� ��ġ�� �� �ڷ� �ű�.
	}
}

// ���� ���� ����Ʈ. �ܼ����Ḯ��Ʈ�� �ݵ�� ���� ��尡 �־�� ã�� �� �ִٴ� ������ �ִ�(������ �ʿ�). �� �ڷ� ��� ��ũ�� �������� �ϸ� �̷� �������� �ذ��� �� �ִ�.
//����� : �����ʹ� ���� ����/������ ���ϰ� �ϱ� ����	�����ϴ� ���. ��������Ϳʹ� �ٸ�. ������¿����� �̰͸� ����.

typedef struct DlistNode{ // ���� ���� ����Ʈ�� ����. rlink�� llink�� �ΰ� �����Ѵ�. 
	int data;
	struct DlistNode* rlink;
	struct DlistNode* llink;
}DlistNode;

void dinsert_node(DlistNode* before, DlistNode* new_node) { // ���߿��Ḯ��Ʈ ���� �Լ�
	new_node->llink = before; //�� ����� ���� ��ũ�� ���� ��带 ����Ŵ
	new_node->rlink = before->rlink; // ������� ������ ��ũ�� ���� ����� ������ ��ũ�� ����Ű�� ���� ���(before�� ���� ��� ���̿� ���ԵǹǷ�)
	before->rlink->llink = new_node; // ���� ����� ������ ��ũ�� ����Ű�� ���(��, ���� ����� ���� ���)�� ���� ��ũ�� ���� ���ԵǴ� ��带 ����Ŵ.
	before->rlink = new_node; // ���� ����� ������ ��ũ�� ���ο� ��带 ����Ŵ.
}

void dremove_node(DlistNode* phead_node, DlistNode* removed) { // �Ʒ�ó�� ���� ���꿡 �ٸ� ��尡 �ʿ� ���� ���� �ڱ��ڽ��� �� �� ��ũ�� ���� ���������� �� �� �ִ�.
	if (removed == phead_node) return; //������ ���� �Ұ�(���� ���¿����� �ڱ��ڽ��� ����Ű�� ������ �ʿ�)
	removed->llink->rlink = removed->rlink; // ������ ����� ���� ����� ������ ��ũ�� ������ ��尡 ����Ű�� ������ ���� ����
	removed->rlink->llink = removed->llink; // ���������� ������ ����� ���� ����� ���� ��ũ�� ������ ����� ���� ��带 ����Ŵ.
	free(removed);
}

