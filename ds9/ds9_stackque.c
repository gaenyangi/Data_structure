#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int front = 0;
int rear = 0;
void push(int data) {
	if ((rear + 1) % MAX_SIZE == front) {
		printf("stack overflow\n"); return;
	}
	stack[rear] = data;
	rear = (rear + 1) % MAX_SIZE;
}

int pop() {
	if (front == rear) {
		printf("stack underflow\n"); return -1;
	}
	int data = stack[front];
	front = (front + 1) % MAX_SIZE;
	return data;
}

int main() {
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);

	printf("%d", pop());
	printf("%d", pop());
	printf("%d", pop());
	printf("%d", pop());
	printf("%d", pop());
	return 0;
}
