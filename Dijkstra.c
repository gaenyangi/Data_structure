//시작 정점부터 다른 모든 정점까지의 최단 경로를 찾아 매단계마다 최소 distance 정점을 추가.
// 매단계 자신으로부터 가장 짧은 거리에 있는 다음 정점으로 이동, 기존 거리와 비교를 반복.
//만약 기존에 더 짧은 경로로 갈 수 있었다면 해당 정점을 폐기하고 기존 경로의 변형을 선택.

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 6 // 정점의 개수

int minDistance(int dist[], bool sptset[]) { //최단 경로 서치 함수(현재 노드에서 가장 짧은 거리를 갖는 다음 노드)
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptset[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

void printsolution(int dist[]) { // 최단 경로 출력
	printf("vertex \t Distance from source\n");
	for (int i = 0; i < V; i++) printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int start) {
	int dist[V];//최단 거리 저장 배열
	bool sptset[V]; // 방문 노드 저장
	for (int i = 0; i < V; i++) { // dist배열 초기화
		dist[i] = INT_MAX;
		sptset[i] = false;
	}
	dist[start] = 0;//시작 노드의 최단거리 = 0
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptset);//현재 노드에서 가장 짧은 거리의 노드 u
		sptset[u] = true; //방문했다고 저장
		for (int v = 0; v < V; v++) //u에서 갈 수 있는 노드에 대해 
			if (!sptset[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v]; //전에 저장된 값보다 u까지 오는 거리와 u에서v 까지 가는 거리가 더 짧으면 교체.
	}
	printsolution(dist);
}

int main() {
	// 그래프의 인접 행렬
	int graph[V][V] = {
	{ 0, 4, 0, 0, 0, 0 },
	{ 4, 0, 8, 0, 0, 0 },
	{ 0, 8, 0, 7, 0, 4 },
	{ 0, 0, 7, 0, 9, 14 },
	{ 0, 0, 0, 9, 0, 10 },
	{ 0, 0, 4, 14, 10, 0 }
	};
	dijkstra(graph, 0);
	return 0;
}