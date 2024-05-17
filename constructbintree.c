#include<stdio.h>
#include<stdlib.h>
//����Ʈ�� �����ϴ� ��ü ���α׷�.

typedef struct Node {
	int key;
	struct Node* left, * right;
}Node;

Node* newNode(int key) { // ��� ����
	Node* node = (Node*)malloc(sizeof(Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void inorderTraversal(Node* root) { // inorder traversal ��ȸ �Լ� ( LVR)
	if (root == NULL) return; // �Ʊ�� �ݴ�� NULL�̸� �����ϵ��� ����.
	inorderTraversal(root->left);
	printf("%d", root->key);
	inorderTraversal(root->right);
}

void preorderTraversal(Node* root) { //preordertraversal ��ȸ �Լ�(VLR)
	if (root == NULL) return;
	printf("%d", root->key);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

Node* construct(int inorder[], int start, int end, int preorder[], int* pIndex) { // �־��� inorder, preorder �������� �°� ����Ʈ�� �����ϴ� ����Լ�
	if (start > end) return NULL;
	Node* node = newnode(preorder[(*pIndex++)]); // preorder�� ���� ��Ҵ� ��Ʈ ���, inorder[start,end]�� ������ ����Ʈ��.
	int i;
	for (i = start; i <= end; i++) {
		if (inorder[i] == node->key) break;
	}

	node->left = construct(inorder, start, i - 1, preorder, pIndex); // ���ȣ��. ���� ����Ʈ�� ����
	node->right = construct(inorder, i + 1, end, preorder, pIndex); // ���ȣ��. ������ ����Ʈ�� ����.
	return node;
}

Node* constructTree(int inorder[], int preorder[], int n) { // �ռ� �������� �̾� Ʈ�� ����, �Է��� ��ȿ�ϴٰ� ����.
	int pIndex = 0; //��Ʈ���� ���� ���������� �ε��� 0�� ����.
	return construct(inorder, 0, n - 1, preorder, &pIndex);
}

int main() {
	
	int inorder[] = { 4, 2, 1, 7, 5, 8, 3, 6 };
	int preorder[] = { 1, 2, 4, 3, 5, 7, 8, 6 };
	int n = sizeof(inorder) / sizeof(inorder[0]);
	struct Node* root = constructTree(inorder, preorder, n);
	// ������ Ʈ���� Ž��
	printf("The inorder traversal is "); inorderTraversal(root);
	printf("\nThe preorder traversal is "); preorderTraversal(root);
	return 0;
}