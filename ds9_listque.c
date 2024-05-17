#include<stdio.h>
#define MAX_SIZE 100
typedef int element;

typedef struct QueueType {
	int queue[MAX_SIZE];
	int front;
	int rear;
}QueueType;

int is_empty(QueueType* q) {
	return (q->front == q->rear); // ������¿����� front�� rear�� ���� ���� ����Ŵ. 
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_SIZE == q->front);//rear�� front ���� ��ĭ �� �ڿ� �ִ��� Ȯ��. front�� �Ű����Ƿ� ������ ���� ���. 
}

void enqueue(QueueType* q, element item) { // �����Լ�
	if (is_full(q)) error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->queue[q->rear] = item; // ������ �׻� �� �ڿ�
}

void dequeue(QueueType* q) {
	if (is_empty(q)) error("ť�� ���� �����Դϴ�.");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->queue[q->front]; // ������ �׻� �� �տ�
}