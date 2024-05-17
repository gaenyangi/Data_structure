#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enequeue(int data) { // ����
	node* new_node = (node*)malloc(sizeof(node)); // ������ ������ ����� ����
	new_node->data = data;//������ ����
	new_node->next = NULL; // ť�̹Ƿ� �Ǹ����� rear �� �����ϹǷ� �� ���� ���� ����.
	if (rear == NULL) { // ���� ť�� ��� rear �� NULL
		front = rear = new_node; // �����̾����Ƿ� front�� rear�� new_node �ּ� ����
	}
	else { //���� �����Ͱ� �����ϴ� ���
		rear->next = new_node; // rear�� ����Ű�� ������ ������ ����� next�� new_node�� ����.
		rear = new_node; // rear�� �׻� ������ �����͸� ����Ű���� �Ű���.
	}
	printf("enqueue : %d\n", data);
	printf("front : %d, rear : %d\n", front->data, rear->data);
}
void dequeue() { // ����
	if (front == NULL) { //������ ť�� �� �տ��� �ǹǷ�
		printf("Queue is empty\n");
		return;
	}
	node* temp = front;
	front = front->next; // �Ǿտ����� �����ǹǷ� front �����͸� �� �������� �ű�.
	if (front == NULL) { 
		rear = NULL;
	}
	printf("dequeue : %d\n", temp->data);
	printf("front : %d, rear : %d\n", front->data, rear->data);
	free(temp); //�Ǿ� �޸� ����
}