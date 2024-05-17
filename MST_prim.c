#include<stdio.h> // prim's method to construct minimum cost spanning tree. 시작 정점에서 주위의 정점 중, 가장 작은 가중치의 간선을 갖는 정점을 연결(트리 구성). 그리고 그 정점에서 또 최소의 연결 가중치를 갖는 정점을 선택.  이후 모든 정점이 연결되도록 반복.
#define MAX_NODES 7 // n개의 정점이 있을 때, edge가 n-1개를 가질 때 까지 반복. 
#define MAX_INT 99999
#define NOTDEF -1
#define OUTOFQ -1

int graph[MAX_NODES][MAX_NODES] = { // 양방향 연결 그래프 배열 표현.
	{ 0, 7, 0, 5, 0, 0, 0},// A in
	{ 7, 0, 8, 9, 7, 0, 0},// B in
	{ 0, 8, 0, 0, 5, 0, 0},// C in
	{ 5, 9, 0, 0,15, 6, 0},// D in
	{ 0, 7, 5,15, 0, 8, 9},// E in
	{ 0, 0, 0, 6, 8, 0,11},// F in
	{ 0, 0, 0, 0, 9,11, 0}// G in
};

int cost[MAX_NODES]; //각 간선의 가중치
int parent[MAX_NODES];// 다음 정점을 찾을 때, 해당 정점의 정보.
int Q[MAX_NODES];
int Qcount;

void PQinit() {
	Qcount = 0;
}

void PQinsert(int a) {
	Q[a] = 0;
	Qcount++;
}

int PQdelmin() {
	int i;
	int min = MAX_INT;
	int saveindex = -1;
	for (i = 0; i < MAX_NODES; i++) {
		if (Q[i] == OUTOFQ) continue;
		if (cost[i] < min) {
			saveindex = i;
			min = cost[i];
		}
	}
	if (saveindex == -1) return OUTOFQ;
	Q[saveindex] = OUTOFQ;
	Qcount--;
	return saveindex;
}

int PQisempty() {
	if (Qcount == 0) return 1;
	return 0;
}

void PQdeckey(int w, int newkey) {
	cost[w] = newkey;
}

void prim(int start) {
	int i, v, w;
	PQinit();
	for (i = 0; i < MAX_NODES; i++) {
		cost[i] = MAX_INT;
		parent[i] = NOTDEF;
		PQinsert(i);
	}
	cost[start] = 0;
	for (; !PQisempty();) {
		v = PQdelmin();
		printf("%d %c\n", v, v + 'A');
		for (w = 0; w < MAX_NODES; w++) {
			if ((graph[v][w] != 0) && (cost[w] > graph[v][w])) {
				PQdeckey(w, graph[v][w]);
				parent[w] = v;
			}
		}
	}
}

int main() {
	prim(3);
	return 0;
}