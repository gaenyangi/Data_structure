#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a>b)?(a):(b))

typedef struct Node { // ���Ḯ��Ʈ�� Ʈ�� ����.
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int data) { //��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void preorederTraversal(Node* root) { // root->left->right�� ������ Ž���ϴ� preorder �˰���
	if (root != NULL) {
		printf("%d", root->data); //root �ڱ��ڽ��� �����͸� ��ȯ�ϰ�,
		preorderTraversal(root->left); // ���� ����Ʈ�� ��ȸ�ϰ� ���ȣ��. ���� ����sub�� �ڽ��� data�� ��ȯ�ϰ� ���� Ȥ�� ���������� ������.
		preorderTraversal(root->right); // ������ ����Ʈ�� ��ȸ. �� �� �����Ͱ� ���� ����(Ȥ�� �ܸ�)����� if ������ Ż��. ���� ����Լ��� �� ������ ����.
	}
}

void postorderTraversal(Node* root) { // ���������� ���� ����Ʈ��->������ ����Ʈ��->root ������ Ž���ϴ� postorder
	if (root != NULL) {
		postorderTraversal(root->left); // ���� ����Ʈ��
		postorderTraversal(root->right); // ������ ����Ʈ��
		printf("%d", root->data); // root �ڱ��ڽ� ������ ��ȯ. & ����Լ��� �ٽ� �ݺ�
	}
}

void inorderTraversal(Node* root) { // ����->�ڱ��ڽ�->������ ��
	if (root != NULL) {
		inorderTraversal(root->left);
		printf("%d", root->data);
		inorderTraversal(root->right);
	}
}

int count(Node* rt) { // �ش� Ʈ���� ��尡 � �ִ��� Ȯ���ϴ� �Լ�. �� ����Ʈ���� ��� ���ȣ���ϸ� +1�� �Ͽ� ���. 
	int countnum = 0;
	if (rt == NULL) return 0;
	countnum = 1 + count(rt->left) + count(rt->right);
	return countnum;
}

int get_leaf_count(Node* rt) { // �̹����� �ش� Ʈ���� �ܸ����(�ڽ��� ����)����� ���� ���. ���������� �ڽ��� ���� ��쿡�� +1�� �ϰ�, ��ͷ� ��� �ҷ��� ���. 
	int countnum = 0;
	if (rt == NULL) return 0;
	if (rt->left == NULL && rt->right == NULL) return 1;
	countnum = get_leaf_count(rt->left) + get_leaf_count(rt->right);
	return countnum;
}

int get_height(Node* rt) { // �ش�Ʈ���� ���� ���
	int height = 0;
	if (rt == NULL) return 0;
	height = 1 + max(get_height(rt->left), get_height(rt->right));//�� �� �߿� ���� ���� ����Ʈ���� �����Ͽ� ���� ���� ��ȯ�Ͽ� ���� ���
	return height;
}

