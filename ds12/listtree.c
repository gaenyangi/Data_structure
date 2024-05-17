#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a>b)?(a):(b))

typedef struct Node { // 연결리스트로 트리 구현.
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int data) { //노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void preorederTraversal(Node* root) { // root->left->right의 순서로 탐색하는 preorder 알고리즘
	if (root != NULL) {
		printf("%d", root->data); //root 자기자신의 데이터를 반환하고,
		preorderTraversal(root->left); // 왼쪽 서브트리 순회하고 재귀호출. 따라서 왼쪽sub도 자신의 data를 반환하고 왼쪽 혹은 오른쪽으로 내려감.
		preorderTraversal(root->right); // 오른쪽 서브트리 순회. 이 때 데이터가 없는 리프(혹은 단말)노드라면 if 문에서 탈출. 또한 재귀함수로 이 과정을 구현.
	}
}

void postorderTraversal(Node* root) { // 마찬가지로 왼쪽 서브트리->오른쪽 서브트리->root 순으로 탐색하는 postorder
	if (root != NULL) {
		postorderTraversal(root->left); // 왼쪽 서브트리
		postorderTraversal(root->right); // 오른쪽 서브트리
		printf("%d", root->data); // root 자기자신 데이터 반환. & 재귀함수로 다시 반복
	}
}

void inorderTraversal(Node* root) { // 왼쪽->자기자신->오른쪽 순
	if (root != NULL) {
		inorderTraversal(root->left);
		printf("%d", root->data);
		inorderTraversal(root->right);
	}
}

int count(Node* rt) { // 해당 트리에 노드가 몇개 있는지 확인하는 함수. 각 서브트리를 계속 재귀호출하며 +1을 하여 계산. 
	int countnum = 0;
	if (rt == NULL) return 0;
	countnum = 1 + count(rt->left) + count(rt->right);
	return countnum;
}

int get_leaf_count(Node* rt) { // 이번에는 해당 트리의 단말노드(자식이 없는)노드의 개수 계산. 마찬가지로 자식이 없는 경우에만 +1을 하고, 재귀로 계속 불러와 계산. 
	int countnum = 0;
	if (rt == NULL) return 0;
	if (rt->left == NULL && rt->right == NULL) return 1;
	countnum = get_leaf_count(rt->left) + get_leaf_count(rt->right);
	return countnum;
}

int get_height(Node* rt) { // 해당트리의 높이 계산
	int height = 0;
	if (rt == NULL) return 0;
	height = 1 + max(get_height(rt->left), get_height(rt->right));//각 층 중에 가장 높은 서브트리를 선택하여 셈한 값을 반환하여 높이 계산
	return height;
}

