#include<stdio.h> // 원형 연결 리스트. 마지막 노드의 링크가 다시 첫 노드를 가리키는 리스트. 순환하므로 한 노드에서 모든 노드로 접근이 가능. 
//일반적으로 헤드 포인터가 마지막 노드를 가리키도록 구성하면 리스트의 처음 및 마지막에 삽입하는 연산이 단순연결리스트보다 용이(가짓수가 줄어듬)
typedef struct {
	int data;
	ListNode* link;
}ListNode;
void insert_first(ListNode** phead, ListNode* node) { //원형연결리스트 처음삽입. 헤드포인터는 마지막 노드를 가리킴.
	if (*phead == NULL) { //공백 리스트 이므로 헤드는 삽입 노드를, 노드의 링크는 가리킬게 없지만 원형이므로 자기자신으로 다시 연결.
		*phead = node;
		node->link = NULL;
	}
	else {
		node->link = (*phead)->link; //맨처음이고 원형, 헤드는 맨 마지막이므로 헤드포인터가 가리키던 노드의 링크가 맨앞. 따라서 새로운 노드의 링크는 맨앞이었던 노드를 기리킴.
		(*phead)->link = node; //새로운 노드가 맨 앞이므로 맨 끝 노드의 링크 변경
	}
}

void insert_last(ListNode** phead, ListNode* node) {//원형연결리스트 끝에 삽입
	if (*phead == NULL){ // 마찬가지로 공백리스트면 앞과 동일.
		*phead = node;
		node->link = node; 
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node; // 맨앞이던 맨 뒤던 가리키던 링크 연결은 동일
		*phead = node; // 헤드포인터의 위치를 맨 뒤로 옮김.
	}
}

// 이중 연결 리스트. 단순연결리스트는 반드시 선행 노드가 있어야 찾을 수 있다는 단점이 있다(순차적 필요). 앞 뒤로 모두 링크를 가지도록 하면 이런 문제점을 해결할 수 있다.
//헤드노드 : 데이터는 없고 삽입/삭제를 편하게 하기 위해	존재하는 노드. 헤드포인터와는 다름. 공백상태에서는 이것만 존재.

typedef struct DlistNode{ // 이중 연결 리스트의 구조. rlink와 llink가 두개 존재한다. 
	int data;
	struct DlistNode* rlink;
	struct DlistNode* llink;
}DlistNode;

void dinsert_node(DlistNode* before, DlistNode* new_node) { // 이중연결리스트 삽입 함수
	new_node->llink = before; //새 노드의 왼쪽 링크는 이전 노드를 가리킴
	new_node->rlink = before->rlink; // 새노드의 오른쪽 링크는 이전 노드의 오른쪽 링크가 가르키던 다음 노드(before과 다음 노드 사이에 삽입되므로)
	before->rlink->llink = new_node; // 이전 노드의 오른쪽 링크가 가리키던 노드(즉, 이전 노드의 다음 노드)의 왼쪽 링크는 새로 삽입되는 노드를 가리킴.
	before->rlink = new_node; // 이전 노드의 오른쪽 링크는 새로운 노드를 가리킴.
}

void dremove_node(DlistNode* phead_node, DlistNode* removed) { // 아래처럼 삭제 연산에 다른 노드가 필요 없고 오직 자기자신의 앞 뒤 링크를 통해 삭제연산을 할 수 있다.
	if (removed == phead_node) return; //헤드노드는 삭제 불가(공백 상태에서도 자기자신을 가리키는 헤드노드는 필요)
	removed->llink->rlink = removed->rlink; // 삭제할 노드의 이전 노드의 오른쪽 링크는 삭제할 노드가 가리키던 오른쪽 노드로 연결
	removed->rlink->llink = removed->llink; // 마찬가지로 삭제할 노드의 다음 노드의 왼쪽 링크는 삭제할 노드의 이전 노드를 가리킴.
	free(removed);
}

