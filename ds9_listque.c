#include<stdio.h>
#define MAX_SIZE 100
typedef int element;

typedef struct QueueType {
	int queue[MAX_SIZE];
	int front;
	int rear;
}QueueType;

int is_empty(QueueType* q) {
	return (q->front == q->rear); // 공백상태에서는 front와 rear가 같은 곳을 가리킴. 
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_SIZE == q->front);//rear가 front 보다 한칸 더 뒤에 있는지 확인. front가 옮겨지므로 나머지 연산 사용. 
}

void enqueue(QueueType* q, element item) { // 삽입함수
	if (is_full(q)) error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->queue[q->rear] = item; // 삽입은 항상 맨 뒤에
}

void dequeue(QueueType* q) {
	if (is_empty(q)) error("큐가 공백 상태입니다.");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->queue[q->front]; // 삭제는 항상 맨 앞에
}