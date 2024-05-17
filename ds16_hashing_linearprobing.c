#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define hash_mod 13

//linear probing을 이용한 coilision 해결
//충돌이 일어나면 그 다음 자리에 저장. 또 일어나면 그다음 자리에 저장. 이하 반복.
// table size가 전체에 비해 매우 클 때 사용.


void insert(int table[], int key, int table_size) {
	int i = 0;
	int result = key % hash_mod;
	while (i < table_size) {
		if (table[result + i] == 0) {
			table[result + i] = key;
			break;
		}
		else i++;
	}
}

void search(int table[], int key, int table_size) {
	int i = 0;
	int result = key % hash_mod;
	while (1) {
		if (table[result + i] == key) {
			printf("\nhash table[%d] : %d", result + i, table[result + i]);
			break;
		}
		else i++;

		if (table[result + i] == NULL || i == table_size) {
			return -1;
			break;
		}
	}
}

