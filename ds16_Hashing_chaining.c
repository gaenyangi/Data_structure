#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TABLE_SIZE 7

typedef struct {
	int key;
}element;

struct list {
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE];

int hash_function(int key) {// ������ �ؽ��Լ�
	return key % TABLE_SIZE;
}

// hash�� collsion �ذ������ chain�� ���. �迭�� ����, �浹�ϸ� ���Ḯ��Ʈ�� �̾ ��� ����.


void hash_chain_add(element item, struct list* ht[]) { // chain�� �̾� ���� �Լ�
	int hash_value = hash_function(item.key);
	struct list* ptr;
	struct list* node_before = NULL;
	struct list* node = ht[hash_value];
	for (; node; node_before = node, node = node->link) { // ���� Ű�� ������ �ִ��� �ش� �ؽ��ּ��� ���Ḯ��Ʈ ��ȸ
		if (node->item.key == item.key) {
			fprintf(stderr, "�̹� Ž��Ű ���Ե�");
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before) node_before->link = ptr; //���� �ش� �ؽ��ּҿ� ���� ������ ���Ḯ��Ʈ�� ����
	else ht[hash_value] = ptr; // ������ �ش� ĭ�� �ٷ� ����
}

void hash_chain_search(element item, struct list* ht[]) { //���Ḯ��Ʈ ��Ī �Լ�
	struct list* node;
	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {
		if (node->item.key == item.key) {
			fprintf(stderr, "Ž�� %d ���� \n", item.key);
			return;
		}
	}
	printf("Ű�� ã�� ����\n");
}





