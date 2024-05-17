#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enequeue(int data) { // 삽입
	node* new_node = (node*)malloc(sizeof(node)); // 데이터 삽입할 새노드 생성
	new_node->data = data;//데이터 삽입
	new_node->next = NULL; // 큐이므로 맨마지막 rear 에 삽입하므로 이 다음 노드는 없음.
	if (rear == NULL) { // 공백 큐일 경우 rear 가 NULL
		front = rear = new_node; // 공백이었으므로 front와 rear에 new_node 주소 삽입
	}
	else { //선행 데이터가 존재하는 경우
		rear->next = new_node; // rear가 가리키던 이전의 마지막 노드의 next를 new_node로 연결.
		rear = new_node; // rear는 항상 마지막 데이터를 가리키도록 옮겨줌.
	}
	printf("enqueue : %d\n", data);
	printf("front : %d, rear : %d\n", front->data, rear->data);
}
void dequeue() { // 삭제
	if (front == NULL) { //삭제는 큐의 맨 앞에서 되므로
		printf("Queue is empty\n");
		return;
	}
	node* temp = front;
	front = front->next; // 맨앞에꺼가 삭제되므로 front 포인터를 그 다음으로 옮김.
	if (front == NULL) { 
		rear = NULL;
	}
	printf("dequeue : %d\n", temp->data);
	printf("front : %d, rear : %d\n", front->data, rear->data);
	free(temp); //맨앞 메모리 해제
}