#include<stdio.h> // prim's method to construct minimum cost spanning tree. ���� �������� ������ ���� ��, ���� ���� ����ġ�� ������ ���� ������ ����(Ʈ�� ����). �׸��� �� �������� �� �ּ��� ���� ����ġ�� ���� ������ ����.  ���� ��� ������ ����ǵ��� �ݺ�.
#define MAX_NODES 7 // n���� ������ ���� ��, edge�� n-1���� ���� �� ���� �ݺ�. 
#define MAX_INT 99999
#define NOTDEF -1
#define OUTOFQ -1

int graph[MAX_NODES][MAX_NODES] = { // ����� ���� �׷��� �迭 ǥ��.
	{ 0, 7, 0, 5, 0, 0, 0},// A in
	{ 7, 0, 8, 9, 7, 0, 0},// B in
	{ 0, 8, 0, 0, 5, 0, 0},// C in
	{ 5, 9, 0, 0,15, 6, 0},// D in
	{ 0, 7, 5,15, 0, 8, 9},// E in
	{ 0, 0, 0, 6, 8, 0,11},// F in
	{ 0, 0, 0, 0, 9,11, 0}// G in
};

int cost[MAX_NODES]; //�� ������ ����ġ
int parent[MAX_NODES];// ���� ������ ã�� ��, �ش� ������ ����.
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