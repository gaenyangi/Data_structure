//���� �������� �ٸ� ��� ���������� �ִ� ��θ� ã�� �Ŵܰ踶�� �ּ� distance ������ �߰�.
// �Ŵܰ� �ڽ����κ��� ���� ª�� �Ÿ��� �ִ� ���� �������� �̵�, ���� �Ÿ��� �񱳸� �ݺ�.
//���� ������ �� ª�� ��η� �� �� �־��ٸ� �ش� ������ ����ϰ� ���� ����� ������ ����.

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 6 // ������ ����

int minDistance(int dist[], bool sptset[]) { //�ִ� ��� ��ġ �Լ�(���� ��忡�� ���� ª�� �Ÿ��� ���� ���� ���)
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptset[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

void printsolution(int dist[]) { // �ִ� ��� ���
	printf("vertex \t Distance from source\n");
	for (int i = 0; i < V; i++) printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int start) {
	int dist[V];//�ִ� �Ÿ� ���� �迭
	bool sptset[V]; // �湮 ��� ����
	for (int i = 0; i < V; i++) { // dist�迭 �ʱ�ȭ
		dist[i] = INT_MAX;
		sptset[i] = false;
	}
	dist[start] = 0;//���� ����� �ִܰŸ� = 0
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptset);//���� ��忡�� ���� ª�� �Ÿ��� ��� u
		sptset[u] = true; //�湮�ߴٰ� ����
		for (int v = 0; v < V; v++) //u���� �� �� �ִ� ��忡 ���� 
			if (!sptset[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v]; //���� ����� ������ u���� ���� �Ÿ��� u����v ���� ���� �Ÿ��� �� ª���� ��ü.
	}
	printsolution(dist);
}

int main() {
	// �׷����� ���� ���
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