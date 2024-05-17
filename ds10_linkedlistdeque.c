#include<stdio.h> // deque: 전단과 후단에서 모두 삽입 삭제가 가능한 큐. (double ended queue)
#include<stdlib.h>//양쪽에서 삽입 삭제가 가능해야 하므로 일반적으로 이중연결 리스트 사용.

typedef int element; // 요소의 타입 정의

typedef struct DlistNode { //노드의 타입 정의
	element data;
	struct DlistNode* rlink;
	struct DlistNode* llink;
}DlistNode;

typedef struct DequeType { //덱의 타입 정의
	DlistNode* head; // ==front 
	DlistNode* tail; // == rear
}DequeType;

void init(DequeType* dq) { // head,tail 포인터 초기화
	dq->head = NULL;
	dq->tail = NULL;
}

int is_empty(DequeType* dq) { // 하나 있는 경우에는 head==tail이고, 두개 이상이면 항상 head 가 있으므로 반환 결과로 비었는지 판별가능.
	return (dq->head == NULL);
}

DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) { // 새로운 노드 생성(포인터로)
	DlistNode* node = (DlistNode*)malloc(sizeof(DlistNode));
	if (node == NULL) error("메모리할당오류");
	node->llink = llink;
	node->data = item;
	node->rlink = rlink;
	return node; // 생성한 노드의 주솟값 반환
}

void add_front(DequeType* dq, element item) { // 덱 전단 삽입 함수
	DlistNode* new_node = create_node(NULL, item, dq->head); // 전단에 삽입 하므로 새노드를 생성해서 이전 링크는 없고, 후단 링크는 이전의 헤드로 연결
	if (is_empty(dq)) dq->tail = new_node; // 만약 공백리스트이면 front==rear이므로 dq->tail도 새 노드로 연결해줌.
	else dq->head->llink = new_node; //이전의 맨 앞에 있던 노드의 llink를 새로운 노드로 연결
	dq->head = new_node; //head 포인터를 맨 앞으로 옮겨줌
}

void add_rear(DequeType* dq, element item) { // 덱 후단 삽입 함수
	DlistNode* new_node = create_node(dq->tail, item, NULL); // 앞서와 마찬가지로 새노드 생성. 이번에는 llink가 tail, rlink가 없음
	if (is_empty(dq)) dq->head = new_node; // 만약 비었으면 앞서와 마찬가지로 head==rear
	else dq->tail->rlink = new_node; // 이전의 마지막 노드의 rlink를 새로 삽입되는 노드로 연결
	dq->tail = new_node; //tail 포인터를 맨 뒤로 옮겨줌

}

element delete_front(DequeType* dq) {// 덱의 맨 앞에서 삭제
	element item;
	DlistNode* removed_node;
	if (is_empty(dq)) error("공백 덱에서 삭제");
	else {
		removed_node = dq->head; // 맨앞 주솟값 전달
		item = removed_node->data;
		dq->head = dq->head->rlink; //헤드포인터를 맨 앞에서 그다음 노드로 옮김
		free(removed_node); //메모리 할당 해제 
		if (dq->head == NULL) dq->tail = NULL; //삭제한 노드가 리스트의 마지막 노드일 경우 head=tail==NULL
		else dq->head->llink = NULL; // 그게 아니라면 맨 앞 노드의 llink는 NULL.
	}
	return item;//삭제한 항목 반환.
}

element delete_rear(DequeType* dq) { // 덱의 맨 뒤에서 삭제
	element item;
	DlistNode* removed_node;
	if (is_empty(dq)) error("공백 덱에서 삭제");
	else {
		removed_node = dq->tail; //맨 마지막 주솟값 반환
		item = removed_node->data; // 맨 마지막 데이터 반환
		dq->tail = dq->tail->llink; // 삭제한 노드의 바로 이전 노드 주솟값으로 tail 옮김.
		free(removed_node); // 삭제한 값 메모리 해제
		if (dq->tail == NULL)dq->head = NULL; // 앞서와 동일하게 삭제하고 나면 공백리스트가 되는 경우
		else dq->tail->rlink = NULL; // 그게 아니면 맨 마지막 노드의 rlink는 NULL
	}
	return item;
}

