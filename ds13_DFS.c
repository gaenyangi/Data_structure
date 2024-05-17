#include<stdio.h> // depth first search = 한 방향으로 계속 가다가 끝에 도달하면 가장 가까운 갈림길로 돌아와서 다른 방향으로 다시 탐색하는 방식.
#include<stdlib.h> // 갈림길로 되돌아 가야되므로 스택이 필요 : 순환 호출을 통해 묵시적인 스택 활용
#define MAX_VTXS 256 // 최대 정점 개수

typedef char VtxData; // 그래프 데이터 자료형
int adj[MAX_VTXS][MAX_VTXS]; // 인접행렬 - 데이터의 연결 방식(간선) 서술 : 간선 (i,j)가 존재하면 1 아니면 0 대입. 일반적으로 양방향 그래프를 사용하므로 (i,j)와 (j,i)는 동일 => symmetric
VtxData vdata[MAX_VTXS]; // 정점에 저장할 데이터 배열 - 순수 데이터 
int vsize; // 전체 정점 개수

void init_graph() { // 그래프 초기화
	vsize = 0; // 현재 정점 개수 0
	for (int i = 0; i < MAX_VTXS; i++) {
		for (int j = 0; j < MAX_VTXS; j++) {
			adj[i][j] = 0; //인접 행렬 돌면서 사이의 간선 모두 초기화
		}
	}
}

void insert_vertex(VtxData name) {
	if (vsize >= MAX_VTXS) {
		printf("error : 정점 개수 초과");
		exit(1);
	}
	vdata[vsize++] = name;
}

void insert_edge(int u, int v, int val) {
	adj[u][v] = val;
	adj[v][u] = val; // 인접 행렬은 당연하게도 diagonal을 따라 대칭이므로.
}

// 앞서와 동일하게 인접 배열 그래프 생성


visited[MAX_VTXS]; // 이미 방문한 노드를 저장
void reset_visited() { 
	for (int i = 0; i < vsize; i++) {
		visited[i] = 0;
	}
}

void DFS(int v) { //순환호출을 통해 v부터 DFS 탐색 시작.
	visited[v] = 1;
	printf("%c", vdata[v]);
	for (int i = 0; i < vsize; i++) {
		if (adj[v][i] != 0 && visited[i] == 0) DFS(i); //i가 증가함에 따라 끝까지 도달하고, 완료하면 순환호출을 하나씩 빠져나오면서 덜 완료한 나머지 for문을 돌리는 형식으로 전체 그래프 순회.
	}
}
