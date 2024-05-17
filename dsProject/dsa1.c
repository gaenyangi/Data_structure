#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
	int num;
	char name[20];
	int kor, math, eng, com;
}element; // 학생의 정보를 담는 구조체를 element로 선언. 내부에는 학번, 이름 그리고 4과목의 성적이 포함.

typedef struct DListNode {
	struct DListNode* llink;
	element data;
	struct DListNode* rlink;
}DListNode; //이중 연결리스트의 연결구조 생성(앞서 선언한 학생구조체 element를 구조체로 갖고, 자기참조로 다음 노드와 이전노드의 링크를 가지는 자기참조구조체)

void init(DListNode* phead); // 초기화 함수
DListNode* dinsert_node(DListNode* before, DListNode* new_node); // insert node
void remove_node(DListNode* phead, DListNode* removed);
void search(DListNode* head, element data); // 원하는 학번 학생의 성적 데이터 출력
void sort_dinsert(DListNode* head); // 학번 순으로 정렬
void display(DListNode* phead); // 연결리스트 전체 출력
void free_node(DListNode* phead); // 동적할당 메모리 반환

void init(DListNode* phead) { 
	printf("[Init Doubly List]\n");
	phead->llink = phead;
	phead->rlink = phead; // 이중 연결 리스트의 헤드노드는 초기 상태에서 두 링크 모두 자기자신을 가리킨다.
}

DListNode* dinsert_node(DListNode* before, DListNode* new_node) { // before는 넣고자 하는 위치의 이전 노드, newnode는 새로 삽입되는 노드.
	new_node->llink = before;
	new_node->rlink = before->rlink; //삽입된 새노드의 양 링크 생성
	before->rlink->llink = new_node; // 이후 노드의 llink를 생성한 노드를 가리키게 만듬.
	before->rlink = new_node; // 이전 노드의 rlink를 생성한 노드를 가리키게 만듬.
	printf("\n\n new_node 성공적 \n\n");
}

void remove_node(DListNode* head, element data) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink){
		if (strcmp(p->data.name,data.name)==0) // 이름을 이용하여 비교하라하였으므로 문자열 비교 함수 strcmp를 이용해 비교.
		{
			if (p == head)
			{
				printf("삭제 오류");
				return;
			}
			p->llink->rlink = p->rlink; //removed를 가리키던 이전 노드의 rlink는 remove가 사라지고 그 다음 노드(remove의 rlink가 가리키던 노드)를 가리킴.
			p->rlink->llink = p->llink; // 마찬가지로 removed 다음 노드는 removed의 llink가 가리키던 곳을 llink로 가리킴.
			printf("%s 학생 삭제 성공", data.name);
			free(p);
			return;
		}
	}
	printf("%s 학생 삭제 실패", data.name);
}

void search(DListNode* head, element data) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) { // 헤드포인트가 가르키는 곳 부터 시작해서 다시 헤드로 돌아올  까지 오른쪽 링크가 가리키는 곳으로 계속 이동.
		if (p->data.num == data.num) // 탐색하는 노드의 data가 원하는 data와 동일할 때까지 반복.
		{
			printf("%6d %10s %6d %6d %6d %6d\n",p->data.num,p->data.name,p->data.kor,p->data.math,p->data.eng,p->data.com);
			return; //탐색성공하면 끝
		}
	}
	printf("%d 번 학생의 번호 검색 실패\n\n", data.num); // 실패할 경우 출력.
}

void sort_dinsert(DListNode* head) {
	DListNode* p, * q;
	element tmp;
	for (p = head->rlink; p->rlink != head; p = p->rlink){
		for (q = p->rlink; q != head; q = q->rlink){
			if (q->data.num < p->data.num) 
			{
				tmp = p->data;
				p->data = q -> data;
				q->data = tmp; // 일반적으로 하는 순서 비교와 동일. 리스트에서 p,q 항목의 값 비교해서 자리바꾸기.
			}
		}
	}
}

void display(DListNode* phead) {
	printf("================================================\n");
	printf("| 번 호 | 이 름 | 언어 | 수리 | 영어 | 컴퓨터 |\n");
	printf("================================================\n");
	for (DListNode* p = phead->rlink; p != phead; p = p->rlink) {
		printf("| %3d | %5s | %4d | %4d | %4d | %5d |\n", p->data.num, p->data.name, p->data.kor, p->data.math, p->data.eng, p->data.com);
	}
	printf("================================================\n");
}

void free_node(DListNode* phead) {
	DListNode* p = phead->rlink, * next;
	while (p != phead) {
		next = p;
		free(p);
		p = p->rlink; // 하나씩 움직이며 전부 메모리 해제.
	}
}

int main()
{
	FILE* fp;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode)); //head 노드 생성. 
	DListNode* tmp; // 임시로 데이터 입력 받는 노드
	element dat; // 임시로 데이터 입력 받는 구조체
	int flag; // 입력받는 메뉴

	init(head); // 헤드 초기화
	
	fp = fopen("data.txt", "rt"); // 파일 열기
	if (fp == NULL) {
		printf("file not found\n");
		return 0;
	}

	while (!feof(fp)) { // 파일에서 데이터를 입력 받아 tmp에 삽입.
		fscanf(fp, "%d %s %d %d %d %d", &dat.num, dat.name, &dat.kor, &dat.math, &dat.eng, &dat.com);
		printf("%6d %10s %6d %6d %6d %6d\n", dat.num, dat.name, dat.kor, dat.math, dat.eng, dat.com);
		tmp = (DListNode*)malloc(sizeof(DListNode));
		tmp->data = dat;
		dinsert_node(head, tmp);
	}

	while (1)
	{
		printf("\n종료(0) 학생 데이터 입력(1) 학생 검색(2) 학생 삭제(3) 목록 보기(4) \n");
		printf("메뉴 입력 : ");
		scanf("%d", &flag);

		switch (flag)
		{
			case 0:
				exit(1);
				break;
			case 1:
				tmp = (DListNode*)malloc(sizeof(DListNode));
				printf("추가할 학생 번호 : "); scanf("%d", &dat.num);
				printf("이름 : "); scanf("%s", &dat.name);
				printf("국어 : "); scanf("%d", &dat.kor);
				printf("수학 : "); scanf("%d", &dat.math);
				printf("영어 : "); scanf("%d", &dat.eng);
				printf("컴퓨터 : "); scanf("%d", &dat.com);
				tmp->data = dat;
				dinsert_node(head, tmp);
				break;
			case 2:
				printf("검색할 학생 번호 : ");
				scanf("%d", &dat.num);
				search(head, dat);
				break;
			case 3:
				printf("삭제할 학생 이름 : "); scanf("%s", dat.name);
				remove_node(head, dat);
				break;
			case 4:
				printf("\n<정렬된 목록 보기>\n\n");
				sort_dinsert(head);
				display(head);
				break;

			default:break;
		}
	}
	free_node(head);
	fclose(fp);
}
