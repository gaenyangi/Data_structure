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

int hash_function(int key) {// 나머지 해싱함수
	return key % TABLE_SIZE;
}

// hash의 collsion 해결법으로 chain을 사용. 배열을 놓고, 충돌하면 연결리스트로 이어서 계속 삽입.


void hash_chain_add(element item, struct list* ht[]) { // chain에 이어 삽입 함수
	int hash_value = hash_function(item.key);
	struct list* ptr;
	struct list* node_before = NULL;
	struct list* node = ht[hash_value];
	for (; node; node_before = node, node = node->link) { // 같은 키값 가지고 있는지 해당 해시주소의 연결리스트 순회
		if (node->item.key == item.key) {
			fprintf(stderr, "이미 탐색키 삽입됨");
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before) node_before->link = ptr; //만약 해당 해시주소에 값이 있으면 연결리스트로 연결
	else ht[hash_value] = ptr; // 없으면 해당 칸에 바로 대입
}

void hash_chain_search(element item, struct list* ht[]) { //연결리스트 서칭 함수
	struct list* node;
	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {
		if (node->item.key == item.key) {
			fprintf(stderr, "탐색 %d 성공 \n", item.key);
			return;
		}
	}
	printf("키를 찾지 못함\n");
}





