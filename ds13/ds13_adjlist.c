#include<stdio.h> // 그래프 표현 방식 1 : 인접행렬 사용
#include<stdlib.h>
#define MAX_VTXS 256 // 최대 정점 개수

typedef char VtxData; // 그래프 데이터 자료형
int adj[MAX_VTXS][MAX_VTXS]; // 인접행렬 - 데이터의 연결 방식(간선) 서술 : 간선 (i,j)가 존재하면 1 아니면 0 대입. 일반적으로 양방향 그래프를 사용하므로 (i,j)와 (j,i)는 동일 => symmetric
VtxData vdata[MAX_VTXS]; // 정점에 저장할 데이터 배열 - 순수 데이터 
int vsize; // 전체 정점 개수

void init_graph() { // 그래프 초기화
	vsize = 0; // 현재 정점 개수 0
	for (int i = 0; i < MAX_VTXS; i++) {
		for (int j = 0; j < MAX_VTXS; j++) {
			adj[i][j] = 0; //인접 행렬 돌면서 모두 0
		}
	}
}

void insert_vertex(VtxData name) {
	if (vsize >= MAX_VTXS){
		printf("error : 정점 개수 초과");
		exit(1);
	}
	vdata[vsize++] = name;
}

void insert_edge(int u, int v, int val) {
	adj[u][v] = val;
	adj[v][u] = val; // 인접 행렬은 당연하게도 diagonal을 따라 대칭이므로.
}

