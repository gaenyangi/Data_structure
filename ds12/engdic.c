#include<stdio.h>
#include<stdlib.h> // 트리 구조를 이용한 영어사전 프로그램. 트리 구조는 삽입과 삭제 모두 O(logn)으로 연결리스트나 배열에 비해 효율적이기 때문에 이것으로 구현. 

typedef struct Node {
	char key[50];
	char meaning[100];
	struct Node* left, * right;
}Node;

// 이진탐색트리에 새로운 노드를 삽입하는 함수
struct Node* insertNode(struct Node* node, char key[], char meaning[]) {
	// 노드가 NULL이면 새로운 노드 생성
	if (node == NULL) {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		strcpy(temp->key, key);
		strcpy(temp->meaning, meaning);
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	// 키 값이 더 작으면 왼쪽 자식 노드로 이동
	if (strcmp(key, node->key) < 0)
		node->left = insertNode(node->left, key, meaning);
	// 키 값이 더 크면 오른쪽 자식 노드로 이동
	else if (strcmp(key, node->key) > 0)
		node->right = insertNode(node->right, key, meaning);
	return node;
}

// 이진탐색트리에서 노드를 검색하는 함수
struct Node* searchNode(struct Node* node, char key[]) {
	// 노드가 NULL이거나 키 값과 일치하면 해당 노드 반환
	if (node == NULL || strcmp(node->key, key) == 0)
		return node;
	// 키 값이 더 작으면 왼쪽 자식 노드에서 검색
	if (strcmp(key, node->key) < 0)
		return searchNode(node->left, key);
	// 키 값이 더 크면 오른쪽 자식 노드에서 검색
	else
		return searchNode(node->right, key);
}

int main() {
	struct Node* root = NULL; // 이진탐색트리의 루트 노드 단어를 입력받아 이진탐색트리에 삽입
	char word[50];
	char meaning[100];
	while (1) {
		printf("Enter word (type exit to stop): ");
		scanf("%s", word);
		if (strcmp(word, "exit") == 0)
			break;
		printf("Enter meaning: ");
		getchar();
		fgets(meaning, 100, stdin);
		root = insertNode(root, word, meaning);
	}
	// 검색할 단어를 입력받아 이진탐색트리에서 검색
	while (1) {
		printf("Enter word to search (type exit to stop): ");
		scanf("%s", word);
		if (strcmp(word, "exit") == 0)
			break;
		struct Node* result = searchNode(root, word);
		if (result == NULL)
			printf("Word not found\n");
		else
			printf("%s", result->meaning);
	}
	return 0;
}
