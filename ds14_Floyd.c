//��� �������� �ִܰ�θ� ���ϴ� �˰���. � ���������� �ִ� �Ÿ��� ���� ������ ��ġ�� ���� ��ġ�� �ʴ� ���� ��������.
//���� 3�� �ݺ��� ���� �ش� ���������� �ִ� �Ÿ��� / �� ���� ������ ��ġ�� ���� ��ġ�� �ʴ� ����� ���� ���Ͽ� �ּڰ� ��ġ

#include<stdio.h>
#include<limits.h>
#define V 4 // ������ ����

void floyd(int graph[][V]) { // �ʱ� ���´� ���� ���, ������ ���ο� ���� �� ����
	int dist[V][V]; //�ִ� ��� ���� �迭
	for (int i = 0; i < V; i++) // �ʱ�ȭ
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
	printf("floyd �ִ� ��� �� : \n");
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