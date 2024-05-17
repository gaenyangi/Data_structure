#include<stdio.h> // 단순연결리스트
#include<stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data; //노드의 데이터
	struct ListNode* link; // 자기자신을 가르키는 포인터로 다음노드를 가르킴 = 링크
}ListNode;

void insert_node(ListNode **phead,ListNode*p,ListNode*new_node) // 첫 노드에 삽입될 경우 헤드포인터가 변경되므로 헤드포인터의 포인터 필요. 리스트의 처음, 중간, 끝에 삽입되는 경우 세가지가 있다.
//new_node는 삽입되는 노드, p는 선행 노드, phead는 리스트의 헤드포인터의 포인터(더블포인터)
{
	if (*phead == NULL) // 공백리스트 인경우
	{
		new_node->link = NULL; //새로운 리스트가 만들어지니까 가리킬건 없고
		*phead = new_node; // 헤드포인터를 새로운 노드로 연결해줌.
	}
	else if (p == NULL) // 이미 있는 리스트의 맨앞에 삽입. 위와는 달리 가리킬 후속 노드가 존재
	{
		new_node->link = *phead; // 헤드노드가 가리키던 링크를 새로운 노드가 가리킴(맨앞이니까)
		*phead = new_node; // 마찬가지로 맨앞에 새로운 노드를 넣으므로 헤드포인터는 새로운 노드를 가리킴.
	}
	else//리스트 사이에 삽입하는 경우
	{
		new_node->link = p->link; //선행노드가 가르키던 노드(링크)를 새로운 노드에 할당(왜냐하면 사이에 끼어 들어가니까)
		p->link = new_node; // 그리고 선행 노드의 링크는 새로운 노드를 가르키도록 만듬. 
	}
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed) // 맨앞 노드 혹은 중간 노드가 삭제되는 경우 두가지. 맨 끝은 어짜피 가리키는게 없으므로.
{//마찬가지로 p는 삭제될 노드의 선행 노드, removed는 삭제될 노드
	if (p = NULL) *phead = (*phead)->link; //첫 노드 삭제
	else p->link = removed->link; //중간 혹은 이후 삭제
	free(removed);
}

void display(ListNode* head) // 반복을 이용한 출력함수
{
	ListNode* p = head; // 연결리스트의 포인터 = 커서처럼 하나씩 옮겨가는 것. 처음부터 해야되니까 이 커서에 헤드의 주소값을 넣어 처음부터 시작. 
	while (p != NULL) //링크가 NULL, 즉 후속노드가 없는 마지막까지
	{
		printf("%d->", p->data); //data를 출력
		p = p->link; //다음 노드가 가르키는 링크를 이전 링크에 대입 = 다음 노드 출력(커서를 옮김)
	}
	printf("\n");
}

void display2(ListNode* head) // 재귀를 이용한 출력함수
{
	ListNode* p = head;
	if (p != NULL)
	{
		printf("%d->", p->link);
		display2(p->link);
	}
}

ListNode* search(ListNode* head, int x) // 값 x를 저장하고 있는 노드 p를 찾는 탐색 연산. 함수의 타입은 함수의 return 값에 따라 정해진다. 구조체 ListNode를 return 하면 선언도 ListNode 타입으로 한다.
{
	ListNode* p;
	p = head;
	while (p != NULL)
	{
		if (p->data == x) return p;//탐색성공할 경우
		p = p->link;
	}
	return p; //if 문 실행되지 않고 NULL 까지오면 탐색 실패 = NULL 반환.
}

ListNode* concat(ListNode* head1, ListNode* head2) // 합병연산
{
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1; //둘 중 하나의 리스트가 공백 리스트일경우 그냥 단순연결
	else
	{
		p = head1;
		while (p->link != NULL) 
		{
			p = p->link;
		}
		p->link = head2; //p를 NULL일 때까지, 즉 head1의 리스트까 끝날 때까지 온 다음, 아무것도 가리키는게 없던 마지막 링크를 다음 리스트의 헤드로 연결해줌.
		return head1; // 두 리스트 연결 후 헤드포인터 반환.
	}
}

ListNode* reverse(ListNode* head) { // 리스트의 노드를 역순으로 만드는 연산.
	ListNode* p, * q, * r;
	p = head; // 처음 시작점
	q = NULL; // 역순의 시작점.
	while (p != NULL) {
		r = q; // 맨 앞 노드는 맨뒤가 되므로 가리키는 것이 NULL이 됨.
		q = p;
		p = p->link; //다음 노드로 이동
		q->link = r; //뒤 노드를 가리키던 링크를 앞 노드를 가리키도록 변환.
	}
	return q; //역순화된 리스트의 헤드포인터
}

int main()
{
	ListNode* p1; //첫 노드, p1의 주소가 헤드 포인터
	p1 = (ListNode*)malloc(sizeof(ListNode)); //동적할당 후 앞서 만들어 놓은 포인터 변수에 주소값을 대입.

	p1->data = 10; //데이터 삽입
	p1->link = NULL; //처음에는 가르킬 것 없음

	ListNode* p2; //다음노드
	p2 = (ListNode*)malloc(sizeof(ListNode));

	p2->data = 20;
	p2->link = NULL;
	p1->link = p2; // 첫노드의 링크가 다음 노드를 가리킴
}