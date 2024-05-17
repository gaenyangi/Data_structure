#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode {
	int key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* searchBST(treeNode* root, int x) { // 이진 트리의 탐색 연산(left<self<right의 inorder traversal 트리 구조 일 때)
	treeNode* p = root;  // 루트 노드부터 시작
	while (p != NULL) { //리프노드에 갈 때까지
		if (x < p->key) p = p->left; // 만약 찾고자하는 키 값이 p의 키 값보다 작다면 왼쪽 서브트리로 이동
		else if (x == p->key) return p; // 만약 같다면 반환
		else p = p->right; // 위와 반대로 찾고자하는 키값이 자신의 키값보다 크다면 오른쪽 서브트리로 이동
	}
	printf(" 찾는 키가 없습니다 ! "); // p가 NULL임에도 찾는 키 못찾았을 경우.
	return p;
}

treeNode* insertNode(treeNode* p, int x) { // 키 값에 따라 맞는 위치에 삽입하는 함수
	treeNode* new;
	if (p == NULL) { // 탐색 실패(p==NULL)인 자리가 새 노드의 삽입 자리. 즉 새로운 노드가 삽입될 자리에서 새 노드 생성. 
		new = (treeNode*)malloc(sizeof(treeNode));
		new->key = x;
		new->right = NULL;
		new->left = NULL;
		return new;
	}
	// 넣고자 하는 위치를 찾기 위해 아래 재귀적 구현. 
	else if (x < p->key) p->left = insertNode(p->left, x); // 넣고자 하는 키값 x가 p의 키값보다 작으면 왼쪽 서브트리로 내려감. 재귀적 구현
	else if (x > p->key)p->right = insertNode(p->right, x); // 마찬가지로 넣고자하는 키값 x가 p의 키값 보다 크면 오른쪽 서브트리로 내려감. 
	else printf("같은 키값 존재"); // 이진트리는 같은 키값을 가지는 노드가 있으면 안되므로 오류 반환
	return p;
}

void deleteNode(treeNode* root, int key) { // 삭제할 때는 노드가 단말 노드일 때, 왼/오 서브 트리 중 한개를 가질 때, 두 개 다 가질 때, 총 3 가지 경우로 나누어진다.
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {//먼저 삭제할 노드를 찾기 위해 트리에서 키를 탐색하는 함수.
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	if (p == NULL) {
		printf("키가 이진 트리에 없음");
		return;
	}

	//case 1 삭제할 노드가 단말 노드 인 경우 : 단말 노드와 부모노드의 연결을 끊으면 된다.
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL; //왼쪽 단말노드일 경우
			else parent->right = NULL; // 오른쪽 단말노드
		}
		else root = NULL; // Node가 한 개일 경우.
	}

	//case 2 삭제하려는 노드가 하나의 서브트리를 가지는 경우 : 해당 노드는 삭제, 서브트리는 해당 노드의 부모 노드에 결합
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left; // 삭제하려는 노드의 서브트리(자식 노드) = child
		else child = p->right;
		if (parent != NULL) {
			if (parent->left == p) parent->left = child; //부모 노드의 왼쪽이 삭제하려는 노드일 경우 자식 노드를 왼쪽에 결합
			else parent->right = child; // 마찬가지로 오른쪽에 결합
		}
		else root = child; //마찬가지로 트리에 노드가 한개 뿐 일 경우.
	}

	//case 3 삭제하려는 노드가 두 개의 서브트리를 다 가지는 경우 : 해당 노드를 삭제한 후에 그 자리를 대체할 successor를 찾아야 한다.
	//마찬가지로, successor도 자식 노드를 가질 수 있고, 트리의 규칙을 지키기 위해 successor의 부모노드도 교체할 필요가 있다.(왼<중<오 순으로 키 값이 커야 하므로)
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) { // successor는 삭제하려는 노드보다 작고, 나머지보단 커야된다. 즉 왼쪽 서브트리에서 가장 큰 노드여야 한다.(혹은 오른쪽에서 가장 작은 노드도 가능)
			succ_parent = succ;
			succ = succ->right; // 따라서 맨 처음에는 왼쪽 서브트리를 선택하고, 이후에는 오른쪽으로 계속 이동(왼<중<오)
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left; //successor는 가장 오른쪽이므로 항상 왼쪽 자식 밖에 없다.(오른쪽이 있으면 자신보다 크므로)
		else succ_parent->right = succ->left; // 따라서 successor가 왼쪽 서브트리냐 오른쪽 서브트리냐에 따라 successor의 부모에 successor의 자식을 연결해준다. 
		p->key = succ->key; // 삭제하려는 위치 p에 succ을 바로 대입
		p = succ; // 주솟값도 옮김으로써 해당 노드 삭제, succ으로 대체됨.
	}
}

