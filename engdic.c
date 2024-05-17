#include<stdio.h>
#include<stdlib.h> // Ʈ�� ������ �̿��� ������� ���α׷�. Ʈ�� ������ ���԰� ���� ��� O(logn)���� ���Ḯ��Ʈ�� �迭�� ���� ȿ�����̱� ������ �̰����� ����. 

typedef struct Node {
	char key[50];
	char meaning[100];
	struct Node* left, * right;
}Node;

// ����Ž��Ʈ���� ���ο� ��带 �����ϴ� �Լ�
struct Node* insertNode(struct Node* node, char key[], char meaning[]) {
	// ��尡 NULL�̸� ���ο� ��� ����
	if (node == NULL) {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		strcpy(temp->key, key);
		strcpy(temp->meaning, meaning);
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	// Ű ���� �� ������ ���� �ڽ� ���� �̵�
	if (strcmp(key, node->key) < 0)
		node->left = insertNode(node->left, key, meaning);
	// Ű ���� �� ũ�� ������ �ڽ� ���� �̵�
	else if (strcmp(key, node->key) > 0)
		node->right = insertNode(node->right, key, meaning);
	return node;
}

// ����Ž��Ʈ������ ��带 �˻��ϴ� �Լ�
struct Node* searchNode(struct Node* node, char key[]) {
	// ��尡 NULL�̰ų� Ű ���� ��ġ�ϸ� �ش� ��� ��ȯ
	if (node == NULL || strcmp(node->key, key) == 0)
		return node;
	// Ű ���� �� ������ ���� �ڽ� ��忡�� �˻�
	if (strcmp(key, node->key) < 0)
		return searchNode(node->left, key);
	// Ű ���� �� ũ�� ������ �ڽ� ��忡�� �˻�
	else
		return searchNode(node->right, key);
}

int main() {
	struct Node* root = NULL; // ����Ž��Ʈ���� ��Ʈ ��� �ܾ �Է¹޾� ����Ž��Ʈ���� ����
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
	// �˻��� �ܾ �Է¹޾� ����Ž��Ʈ������ �˻�
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