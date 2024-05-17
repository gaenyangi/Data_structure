#include<stdio.h> // �׷��� ǥ�� ��� 1 : ������� ���
#include<stdlib.h>
#define MAX_VTXS 256 // �ִ� ���� ����

typedef char VtxData; // �׷��� ������ �ڷ���
int adj[MAX_VTXS][MAX_VTXS]; // ������� - �������� ���� ���(����) ���� : ���� (i,j)�� �����ϸ� 1 �ƴϸ� 0 ����. �Ϲ������� ����� �׷����� ����ϹǷ� (i,j)�� (j,i)�� ���� => symmetric
VtxData vdata[MAX_VTXS]; // ������ ������ ������ �迭 - ���� ������ 
int vsize; // ��ü ���� ����

void init_graph() { // �׷��� �ʱ�ȭ
	vsize = 0; // ���� ���� ���� 0
	for (int i = 0; i < MAX_VTXS; i++) {
		for (int j = 0; j < MAX_VTXS; j++) {
			adj[i][j] = 0; //���� ��� ���鼭 ��� 0
		}
	}
}

void insert_vertex(VtxData name) {
	if (vsize >= MAX_VTXS){
		printf("error : ���� ���� �ʰ�");
		exit(1);
	}
	vdata[vsize++] = name;
}

void insert_edge(int u, int v, int val) {
	adj[u][v] = val;
	adj[v][u] = val; // ���� ����� �翬�ϰԵ� diagonal�� ���� ��Ī�̹Ƿ�.
}

