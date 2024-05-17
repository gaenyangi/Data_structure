#include<stdio.h> // ���� ����Ʈ�� �̿��� �׷��� ǥ��
#include<stdlib.h> // �� ������ ���Ḯ��Ʈ�� ���� ������ �������� ���Ḯ��Ʈ�� ǥ��.
#define MAX_VTXS 256

void error(char str[]) { // ���� ó�� �� ���� �޽��� ����ϱ� ���� �Լ�(����)
	printf("%s\n", str);
	exit(1);
}

typedef struct GraphNode {
	int id;
	struct GraphNode* link;
}GNode;

typedef char VtxData; // ���������� ���� ������ �ڷ��� ����
GNode* adj[MAX_VTXS]; // �� ������ ��������Ʈ(�׷��� ����)
int vsize; // ������ ����
VtxData vdata[MAX_VTXS]; // ������ ������ ������

int is_empty_graph() {
	return (vsize == 0);
}

int is_full_graph() {
	return (vsize >= MAX_VTXS);
}

void init_graph() { // graph init
	vsize = 0;
	for (int i = 0; i < MAX_VTXS; i++) adj[i] = NULL;
}

void reset_graph() { // �����Ͱ� ����־��� �׷����� �ʱ�ȭ�� ���Ḯ��Ʈ �� ����� �޸𸮸� �����ؾ� �ϹǷ� ��� �����͸� ���⺸�ٴ� �̷��� for�� ������ ���� ����.
	GNode* n;
	for (int i = 0; i < vsize; i++) {
		while (adj[i] != NULL) {
			n = adj[i];
			adj[i] = n->link;
			free(n);
		}
	}
	vsize = 0;
}

void insert_vertex(VtxData name) { // ������ �迭�� �� ����
	if (is_full_graph()) error("error : �׷��� ���� ���� �ʰ�\n");
	else vdata[vsize++] = name;
}

void insert_edge(int u, int v) { //��������Ʈ�� u�� v �����׷��� ���� ���� ����.(���� ����)
	GNode* n = (GNode*)malloc(sizeof(GNode));
	n->link = adj[u]; // �߰��Ǵ� ������ ����Ű�� ���Ḯ��Ʈ�� �� �տ� ���Ե�!! ���� ���� ������ �� ���� ����Ű�� ���� ���ο� ���Ḯ��Ʈ ��尡 ����Ű�� �ϰ�
	n->id = v; // ������ id.
	adj[u] = n; // �� �ڿ� �ش� ������ �迭 �����Ͱ� ���� ���� ��带 ����Ű�� ��.
}