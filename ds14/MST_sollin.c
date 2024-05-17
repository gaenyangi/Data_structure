//각 단계에서 연결되지 않은 정점이 가지고 있는 최소 가중치의 간선을 선택. 이렇게 몇개의 그룹을 만들고, 각 그룹을 연결하여 중복되는 edge 제거. 
//하나의 트리만 남거나(그룹들이 모두 합쳐졌을 때) 추가할 간선이 없을 경우 종료
//kruskal은 모든 간선들을 하나씩 확인, sollin은 각 정점별로 최소 가중치 간선을 선택하고 신장트리를 구성.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_NODES 7
#define MAX_INT 99999
#define NOTDEF -1

int graph[MAX_NODES][MAX_NODES] = {
	{ 0, 7, 0, 5, 0, 0, 0},// A in
	{ 7, 0, 8, 9, 7, 0, 0},// B in
	{ 0, 8, 0, 0, 5, 0, 0},// C in
	{ 5, 9, 0, 0,15, 6, 0},// D in
	{ 0, 7, 5,15, 0, 8, 9},// E in
	{ 0, 0, 0, 6, 8, 0,11},// F in
	{ 0, 0, 0, 0, 9,11, 0},// G in
};

int pred[MAX_NODES];

int find(int subset[], int i) {
	if (subset[i] == NOTDEF) return i;
	return find(subset, subset[i]);
}

void union_subset(int subset[], int x, int y) {
	int xroot = find(subset, x);
	int yroot = find(subset, y);
	subset[xroot] = yroot;
}

void sollin() {
	int subset[MAX_NODES];
	int i, j, u, v;
	int min_index;
	int min;
	bool found;
	for (i = 0; i < MAX_NODES; i++) {
		subset[i] = NOTDEF;
		pred[i] = NOTDEF;
	}

	found = true;
	while (found) {
		found = false;
		for (i = 0; i < MAX_NODES; i++) {
			if (find(subset, i) != find(subset, j) && graph[i][j] < min) {
				min_index = j;
				min = graph[i][j];
			}
		
			if (min_index != NOTDEF) {
				u = find(subset, i);
				v = find(subset, min_index);
				if (u != v) {
					union_subset(subset, u, v);
					pred[min_index] = i;
					found = true;
				}
			}
		}
	}
}

int main() {
	sollin();
	for (int i = 0; i < MAX_NODES; i++) printf("%c - %c\n", pred[i] + 'A', i + 'A');
	return 0;
}
