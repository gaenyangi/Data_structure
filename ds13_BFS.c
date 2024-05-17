#include<stdio.h>// ���� �������κ��� ���� ����� ������ ���� �湮, �հ��� ���߿� �湮 - > ť�� �̿��Ͽ� ����
#include<stdlib.h>

#define MAX_NODES 7
int graph[MAX_NODES][MAX_NODES] = {
	// A, B, C, D, E, F, G out
	{ 0, 1, 1, 0, 0, 0, 0},// A in
	{ 1, 0, 0, 1, 1, 0, 0},// B in
	{ 1, 0, 0, 0, 1, 1, 0},// C in
	{ 0, 1, 0, 0, 0, 1, 0},// D in
	{ 0, 1, 1, 0, 0, 1, 1},// E in
	{ 0, 0, 1, 1, 1, 0, 1},// F in
	{ 0, 0, 0, 0, 1, 1, 0},// G in
};
void BFS(int start)
{
	int queue[MAX_NODES]; // ť ����
	int visited[MAX_NODES] = { 0 }; // �湮 ���θ� �����ϴ� �迭 �ʱ�ȭ

	int front = -1, rear = -1; // ť�� front�� rear�� �ʱ�ȭ
	visited[start] = 1; // ���� ��带 �湮�� ������ ǥ��
	queue[++rear] = start; // ť�� ���� ��� �߰�
	while (front != rear) { // ť�� ������� ���� ��� �ݺ�
		int cur = queue[++front]; // ť���� ��� �ϳ��� ������
		printf("%c ", cur + 'A'); // ���� ��� �湮 ���
		for (int i = 0; i < MAX_NODES; i++) {
			// cur ���� ������ ��带 ť�� �߰�
			if (graph[cur][i] == 1 && visited[i] == 0) {
				queue[++rear] = i;
				visited[i] = 1; // ���� ��带 �湮�� ������ ǥ��
			}
		}
	}
}
int main()
{
	int start = 0; // A ��带 ���� ���� ����
	BFS(start);
	return 0;
}