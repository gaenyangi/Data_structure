#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>//bool���� ���� ���.
//����Ǵ� �ܸ������ NULL ������ ������ Ȱ���� ���� ��带 ����Ű�� Ʈ��. ���ȣ���� ������� �ʾƵ� ��ȯȣ���� �����Ͽ� ����Ǵ� ������ ���̰�, ����ð��� ����Ǵ� ȿ���� �ִ�. 

typedef struct threadNode {
	int data;
	struct threadNode* left, * right;
	bool is_leftThread, is_rightThread; // �Ϲ� �θ����� �ڽ� ����� ��ġ�� ������ left,right�� ������ �ܸ� ����� ��쿡�� ���� ��带 ����Ű�� �����Ͱ� left,right�� ���ִ�. 
}threadNode;							// �̸� �����ϱ� ���� ������ ������� �ƴ����� ǥ���ϴ� bool ���. (�ֳ��ϸ� �������� �ܸ������ �� ���� ����Ű�� �ڽ��� �����Ƿ� ��ȸ�� �Ұ����߱� ����).

threadNode* find_successor(threadNode* p) { // ������ ����Ʈ�� ��ȸ�ϱ� ���� �־��� ��� p�� �� ���� ��带 ã�� �Լ�, inorder�̹Ƿ� ����, �ڱ��ڽ� ,������ ����Ʈ�� ��. 
	threadNode* q = p->right; // �Է��� v�̹Ƿ� ������ ����Ʈ�� Ȯ��
	if (q == NULL || p->is_rightThread == true) return q; // q�� NULL�̰ų� rightthread�� Ʈ���� Ʈ���� ������ ��� Ȥ�� �������� �� ��带 ����Ű�� �ܸ�����̹Ƿ� q�� ��ȯ. (��, q�� �������� �� ��� ����Ű�Ƿ�)
	while (q->left != NULL) q = p->left; // �ƴ϶�� inorder ������� ���� ����Ʈ���� ���������� ���������ϹǷ� �������� ���� �̵�. 
	return q;
}

void thread_inorder(threadNode* t) { //inorder ������ Ʈ�� ��ȸ
	threadNode* q = t;
	while (q->left) q = q->left; //�ǿ��� �Ʒ� ���� ã��
	do {
		printf("%d", q->data); 
		q = find_successor(q); // ������ ������ ���� ���� �� ��� ã�� �Լ� ����ؼ� ����Լ� �Ⱦ��� ���� ��� �̵�.
	} while (q); //������ Ʈ���� ����ϸ� �� �����ʾƷ� ������ �ܸ���带 �����ϰ�� �׻� ����Ű�� ��尡 �����Ƿ� q�� NULL �� �ƴ�(���������� ������ ����� ��쿡�� return q�� �ϵ��� ������ ����)
}