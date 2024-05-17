//모든 정점쌍의 최단경로를 구하는 알고리즘. 어떤 정점까지의 최단 거리는 그전 정점을 거치는 경우와 거치지 않는 경우로 나누어짐.
//따라서 3중 반복을 통해 해당 정점까지의 최단 거리와 / 그 직전 정점을 거치는 경우와 거치지 않는 경우의 합을 비교하여 최솟값 서치

#include<stdio.h>
#include<limits.h>
#define V 4 // 정점의 개수

void floyd(int graph[][V]) { // 초기 상태는 인접 행렬, 간선의 여부에 따라 값 변경
	int dist[V][V]; //최단 경로 저장 배열
	for (int i = 0; i < V; i++) // 초기화
		for (int j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	printf("floyd 최단 경로 값 : \n");
	for (int i = 0; i< V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INT_MAX) printf("INF ");
			else printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int graph[V][V] = { {0, 5, INT_MAX, 10},
	{INT_MAX, 0, 3, INT_MAX},
	{INT_MAX, INT_MAX, 0, 1},
	{INT_MAX, INT_MAX, INT_MAX, 0}
	};
	floyd(graph);
	return 0;
}