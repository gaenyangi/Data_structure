#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode {
	int key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* searchBST(treeNode* root, int x) { // ���� Ʈ���� Ž�� ����(left<self<right�� inorder traversal Ʈ�� ���� �� ��)
	treeNode* p = root;  // ��Ʈ ������ ����
	while (p != NULL) { //������忡 �� ������
		if (x < p->key) p = p->left; // ���� ã�����ϴ� Ű ���� p�� Ű ������ �۴ٸ� ���� ����Ʈ���� �̵�
		else if (x == p->key) return p; // ���� ���ٸ� ��ȯ
		else p = p->right; // ���� �ݴ�� ã�����ϴ� Ű���� �ڽ��� Ű������ ũ�ٸ� ������ ����Ʈ���� �̵�
	}
	printf(" ã�� Ű�� �����ϴ� ! "); // p�� NULL�ӿ��� ã�� Ű ��ã���� ���.
	return p;
}

treeNode* insertNode(treeNode* p, int x) { // Ű ���� ���� �´� ��ġ�� �����ϴ� �Լ�
	treeNode* new;
	if (p == NULL) { // Ž�� ����(p==NULL)�� �ڸ��� �� ����� ���� �ڸ�. �� ���ο� ��尡 ���Ե� �ڸ����� �� ��� ����. 
		new = (treeNode*)malloc(sizeof(treeNode));
		new->key = x;
		new->right = NULL;
		new->left = NULL;
		return new;
	}
	// �ְ��� �ϴ� ��ġ�� ã�� ���� �Ʒ� ����� ����. 
	else if (x < p->key) p->left = insertNode(p->left, x); // �ְ��� �ϴ� Ű�� x�� p�� Ű������ ������ ���� ����Ʈ���� ������. ����� ����
	else if (x > p->key)p->right = insertNode(p->right, x); // ���������� �ְ����ϴ� Ű�� x�� p�� Ű�� ���� ũ�� ������ ����Ʈ���� ������. 
	else printf("���� Ű�� ����"); // ����Ʈ���� ���� Ű���� ������ ��尡 ������ �ȵǹǷ� ���� ��ȯ
	return p;
}

void deleteNode(treeNode* root, int key) { // ������ ���� ��尡 �ܸ� ����� ��, ��/�� ���� Ʈ�� �� �Ѱ��� ���� ��, �� �� �� ���� ��, �� 3 ���� ���� ����������.
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {//���� ������ ��带 ã�� ���� Ʈ������ Ű�� Ž���ϴ� �Լ�.
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	if (p == NULL) {
		printf("Ű�� ���� Ʈ���� ����");
		return;
	}

	//case 1 ������ ��尡 �ܸ� ��� �� ��� : �ܸ� ���� �θ����� ������ ������ �ȴ�.
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL; //���� �ܸ������ ���
			else parent->right = NULL; // ������ �ܸ����
		}
		else root = NULL; // Node�� �� ���� ���.
	}

	//case 2 �����Ϸ��� ��尡 �ϳ��� ����Ʈ���� ������ ��� : �ش� ���� ����, ����Ʈ���� �ش� ����� �θ� ��忡 ����
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left; // �����Ϸ��� ����� ����Ʈ��(�ڽ� ���) = child
		else child = p->right;
		if (parent != NULL) {
			if (parent->left == p) parent->left = child; //�θ� ����� ������ �����Ϸ��� ����� ��� �ڽ� ��带 ���ʿ� ����
			else parent->right = child; // ���������� �����ʿ� ����
		}
		else root = child; //���������� Ʈ���� ��尡 �Ѱ� �� �� ���.
	}

	//case 3 �����Ϸ��� ��尡 �� ���� ����Ʈ���� �� ������ ��� : �ش� ��带 ������ �Ŀ� �� �ڸ��� ��ü�� successor�� ã�ƾ� �Ѵ�.
	//����������, successor�� �ڽ� ��带 ���� �� �ְ�, Ʈ���� ��Ģ�� ��Ű�� ���� successor�� �θ��嵵 ��ü�� �ʿ䰡 �ִ�.(��<��<�� ������ Ű ���� Ŀ�� �ϹǷ�)
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) { // successor�� �����Ϸ��� ��庸�� �۰�, ���������� Ŀ�ߵȴ�. �� ���� ����Ʈ������ ���� ū ��忩�� �Ѵ�.(Ȥ�� �����ʿ��� ���� ���� ��嵵 ����)
			succ_parent = succ;
			succ = succ->right; // ���� �� ó������ ���� ����Ʈ���� �����ϰ�, ���Ŀ��� ���������� ��� �̵�(��<��<��)
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left; //successor�� ���� �������̹Ƿ� �׻� ���� �ڽ� �ۿ� ����.(�������� ������ �ڽź��� ũ�Ƿ�)
		else succ_parent->right = succ->left; // ���� successor�� ���� ����Ʈ���� ������ ����Ʈ���Ŀ� ���� successor�� �θ� successor�� �ڽ��� �������ش�. 
		p->key = succ->key; // �����Ϸ��� ��ġ p�� succ�� �ٷ� ����
		p = succ; // �ּڰ��� �ű����ν� �ش� ��� ����, succ���� ��ü��.
	}
}

