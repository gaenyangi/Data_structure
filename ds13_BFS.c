#include<stdio.h>// 시작 정점으로부터 가장 가까운 정점을 먼저 방문, 먼곳을 나중에 방문 - > 큐를 이용하여 구현
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
	int queue[MAX_NODES]; // 큐 선언
	int visited[MAX_NODES] = { 0 }; // 방문 여부를 저장하는 배열 초기화

	int front = -1, rear = -1; // 큐의 front와 rear를 초기화
	visited[start] = 1; // 시작 노드를 방문한 것으로 표시
	queue[++rear] = start; // 큐에 시작 노드 추가
	while (front != rear) { // 큐가 비어있지 않은 경우 반복
		int cur = queue[++front]; // 큐에서 노드 하나를 꺼내옴
		printf("%c ", cur + 'A'); // 현재 노드 방문 출력
		for (int i = 0; i < MAX_NODES; i++) {
			// cur 노드와 인접한 노드를 큐에 추가
			if (graph[cur][i] == 1 && visited[i] == 0) {
				queue[++rear] = i;
				visited[i] = 1; // 인접 노드를 방문한 것으로 표시
			}
		}
	}
}
int main()
{
	int start = 0; // A 노드를 시작 노드로 설정
	BFS(start);
	return 0;
}