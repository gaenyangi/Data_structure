#include<stdio.h> // depth first search = �� �������� ��� ���ٰ� ���� �����ϸ� ���� ����� ������� ���ƿͼ� �ٸ� �������� �ٽ� Ž���ϴ� ���.
#include<stdlib.h> // ������� �ǵ��� ���ߵǹǷ� ������ �ʿ� : ��ȯ ȣ���� ���� �������� ���� Ȱ��
#define MAX_VTXS 256 // �ִ� ���� ����

typedef char VtxData; // �׷��� ������ �ڷ���
int adj[MAX_VTXS][MAX_VTXS]; // ������� - �������� ���� ���(����) ���� : ���� (i,j)�� �����ϸ� 1 �ƴϸ� 0 ����. �Ϲ������� ����� �׷����� ����ϹǷ� (i,j)�� (j,i)�� ���� => symmetric
VtxData vdata[MAX_VTXS]; // ������ ������ ������ �迭 - ���� ������ 
int vsize; // ��ü ���� ����

void init_graph() { // �׷��� �ʱ�ȭ
	vsize = 0; // ���� ���� ���� 0
	for (int i = 0; i < MAX_VTXS; i++) {
		for (int j = 0; j < MAX_VTXS; j++) {
			adj[i][j] = 0; //���� ��� ���鼭 ������ ���� ��� �ʱ�ȭ
		}
	}
}

void insert_vertex(VtxData name) {
	if (vsize >= MAX_VTXS) {
		printf("error : ���� ���� �ʰ�");
		exit(1);
	}
	vdata[vsize++] = name;
}

void insert_edge(int u, int v, int val) {
	adj[u][v] = val;
	adj[v][u] = val; // ���� ����� �翬�ϰԵ� diagonal�� ���� ��Ī�̹Ƿ�.
}

// �ռ��� �����ϰ� ���� �迭 �׷��� ����


visited[MAX_VTXS]; // �̹� �湮�� ��带 ����
void reset_visited() { 
	for (int i = 0; i < vsize; i++) {
		visited[i] = 0;
	}
}

void DFS(int v) { //��ȯȣ���� ���� v���� DFS Ž�� ����.
	visited[v] = 1;
	printf("%c", vdata[v]);
	for (int i = 0; i < vsize; i++) {
		if (adj[v][i] != 0 && visited[i] == 0) DFS(i); //i�� �����Կ� ���� ������ �����ϰ�, �Ϸ��ϸ� ��ȯȣ���� �ϳ��� ���������鼭 �� �Ϸ��� ������ for���� ������ �������� ��ü �׷��� ��ȸ.
	}
}
