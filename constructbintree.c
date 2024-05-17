#include<stdio.h>
#include<stdlib.h>
//이진트리 구성하는 전체 프로그램.

typedef struct Node {
	int key;
	struct Node* left, * right;
}Node;

Node* newNode(int key) { // 노드 생성
	Node* node = (Node*)malloc(sizeof(Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void inorderTraversal(Node* root) { // inorder traversal 순회 함수 ( LVR)
	if (root == NULL) return; // 아까랑 반대로 NULL이면 리턴하도록 구성.
	inorderTraversal(root->left);
	printf("%d", root->key);
	inorderTraversal(root->right);
}

void preorderTraversal(Node* root) { //preordertraversal 순회 함수(VLR)
	if (root == NULL) return;
	printf("%d", root->key);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

Node* construct(int inorder[], int start, int end, int preorder[], int* pIndex) { // 주어진 inorder, preorder 시퀀스에 맞게 이진트리 생성하는 재귀함수
	if (start > end) return NULL;
	Node* node = newnode(preorder[(*pIndex++)]); // preorder의 다음 요소는 루트 노드, inorder[start,end]로 구성된 서브트리.
	int i;
	for (i = start; i <= end; i++) {
		if (inorder[i] == node->key) break;
	}

	node->left = construct(inorder, start, i - 1, preorder, pIndex); // 재귀호출. 왼쪽 서브트리 생성
	node->right = construct(inorder, i + 1, end, preorder, pIndex); // 재귀호출. 오른쪽 서브트리 생성.
	return node;
}

Node* constructTree(int inorder[], int preorder[], int n) { // 앞선 시퀀스에 이어 트리 형성, 입력이 유효하다고 가정.
	int pIndex = 0; //루트노드는 이전 시퀀스에서 인덱스 0에 존재.
	return construct(inorder, 0, n - 1, preorder, &pIndex);
}

int main() {
	
	int inorder[] = { 4, 2, 1, 7, 5, 8, 3, 6 };
	int preorder[] = { 1, 2, 4, 3, 5, 7, 8, 6 };
	int n = sizeof(inorder) / sizeof(inorder[0]);
	struct Node* root = constructTree(inorder, preorder, n);
	// 구성된 트리를 탐색
	printf("The inorder traversal is "); inorderTraversal(root);
	printf("\nThe preorder traversal is "); preorderTraversal(root);
	return 0;
}