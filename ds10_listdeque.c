#include<stdio.h>
#define MAX_SIZE 100

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

void push_front(int data) {
	if ((front == 0 && rear == MAX_SIZE - 1) || front == rear + 1) {
		printf("Deque is full\n"); return;
	}
	if (front == -1) {
		front = 0;
		rear = 0;
	}
	else if (front == 0) {
		front = MAX_SIZE - 1;
	}
	else front--;
	deque[front] = data;
	printf("push_front : %d\n", data);
}

void push_back(int data) {
	if ((front == 0 && rear == MAX_SIZE - 1) || front == rear + 1) {
		printf("Deque is full\n"); return;
	}
	if (front == -1) {
		front = 0;
		rear = 0;
	}
	else if (rear == MAX_SIZE-1) {
		rear = 0;
	}
	else rear++;
	deque[rear] = data;
	printf("push_back : %d\n", data);
}

void pop_front() {
	if (front == -1) {
		printf("Deque is empty\n");
		return;
	}
	printf("pop_front : %d\n", deque[front]);
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == MAX_SIZE - 1) front = 0;
	else front++;
}

void pop_back() {
	if (front == -1) {
		printf("Deque is empty\n");
		return;
	}
	printf("pop_back : %d\n", deque[rear]);
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (rear==0) rear = MAX_SIZE-1;
	else rear--;
}