#include<stdio.h> // 인접 리스트를 이용한 그래프 표현
#include<stdlib.h> // 각 정점이 연결리스트를 가져 인접한 정점들을 연결리스트로 표현.
#define MAX_VTXS 256

void error(char str[]) { // 예외 처리 및 오류 메시지 출력하기 위한 함수(공통)
	printf("%s\n", str);
	exit(1);
}

typedef struct GraphNode {
	int id;
	struct GraphNode* link;
}GNode;

typedef char VtxData; // 마찬가지로 저장 데이터 자료형 정의
GNode* adj[MAX_VTXS]; // 각 정점의 인접리스트(그래프 구성)
int vsize; // 정점의 개수
VtxData vdata[MAX_VTXS]; // 정점에 저장할 데이터

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

void reset_graph() { // 데이터가 들어있었던 그래프의 초기화는 연결리스트 각 노드의 메모리를 해제해야 하므로 헤드 포인터만 끊기보다는 이렇게 for문 돌리는 것이 좋음.
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

void insert_vertex(VtxData name) { // 데이터 배열에 값 삽입
	if (is_full_graph()) error("error : 그래프 정점 개수 초과\n");
	else vdata[vsize++] = name;
}

void insert_edge(int u, int v) { //인접리스트에 u와 v 간에그래프 간의 관계 구축.(간선 삽입)
	GNode* n = (GNode*)malloc(sizeof(GNode));
	n->link = adj[u]; // 추가되는 간선을 가리키는 연결리스트는 맨 앞에 삽입됨!! 따라서 먼저 기존의 맨 앞을 가리키던 것을 새로운 연결리스트 노드가 가리키게 하고
	n->id = v; // 간선의 id.
	adj[u] = n; // 그 뒤에 해당 정점의 배열 포인터가 새로 만든 노드를 가리키게 함.
}