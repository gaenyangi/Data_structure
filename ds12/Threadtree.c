#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>//bool쓰기 위한 헤더.
//낭비되는 단말노드의 NULL 포인터 공간을 활용해 다음 노드를 가리키는 트리. 재귀호출을 사용하지 않아도 순환호출이 가능하여 낭비되는 공간도 줄이고, 연산시간도 단축되는 효과가 있다. 

typedef struct threadNode {
	int data;
	struct threadNode* left, * right;
	bool is_leftThread, is_rightThread; // 일반 부모노드라면 자식 노드의 위치가 포인터 left,right에 있지만 단말 노드의 경우에는 다음 노드를 가리키는 포인터가 left,right에 들어가있다. 
}threadNode;							// 이를 구분하기 위해 스레드 노드인지 아닌지를 표시하는 bool 사용. (왜냐하면 이전에는 단말노드일 때 다음 가리키는 자식이 없으므로 순회가 불가능했기 때문).

threadNode* find_successor(threadNode* p) { // 스레드 이진트리 순회하기 위해 주어진 노드 p가 갈 다음 노드를 찾는 함수, inorder이므로 왼쪽, 자기자신 ,오른쪽 서브트리 순. 
	threadNode* q = p->right; // 입력이 v이므로 오른쪽 서브트리 확인
	if (q == NULL || p->is_rightThread == true) return q; // q가 NULL이거나 rightthread가 트루라면 트리의 마지막 노드 혹은 다음으로 갈 노드를 가리키는 단말노드이므로 q를 반환. (즉, q가 다음으로 갈 노드 가리키므로)
	while (q->left != NULL) q = p->left; // 아니라면 inorder 순서대로 왼쪽 서브트리가 남아있으면 먼저가야하므로 왼쪽으로 먼저 이동. 
	return q;
}

void thread_inorder(threadNode* t) { //inorder 순서로 트리 순회
	threadNode* q = t;
	while (q->left) q = q->left; //맨왼쪽 아래 먼저 찾기
	do {
		printf("%d", q->data); 
		q = find_successor(q); // 위에서 정의한 다음 노드로 갈 노드 찾는 함수 사용해서 재귀함수 안쓰고 다음 경로 이동.
	} while (q); //스레드 트리를 사용하면 맨 오른쪽아래 마지막 단말노드를 제외하고는 항상 가리키는 노드가 있으므로 q가 NULL 이 아님(마찬가지로 마지막 노드일 경우에는 return q를 하도록 위에서 정의)
}
