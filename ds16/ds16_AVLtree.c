#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	struct BTreeNode* right;
	struct BTreeNode* left;
}BTreeNode;

//자체균형 BST를 유지하는(좌우 서브트리 높이 차이는 2 미만) AVL 트리


//루트의 왼쪽 및 오른쪽 서브트리 변경
void changeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	main->left = sub;
}

void changeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	main->right = sub;
}

BTreeNode* getLeftSubTree(BTreeNode* bst) {
	return bst->left;
}

BTreeNode* getRightSubTree(BTreeNode* bst) {
	return bst->right;
}

BTreeNode* RotateLL(BTreeNode* bst) {
	BTreeNode* pNode;//parent
	BTreeNode* cNode;//child
	pNode = bst;
	cNode = getLeftSubTree(pNode);

	changeLeftSubTree(pNode, getRightSubTree(cNode)); //왼쪽 높이가 2 차이나므로 첫번째 왼쪽(cnode)을 잡고 들어올리면 됨.
	changeRightSubTree(cNode, pNode); // LL회전 수행

	return cNode; //LL회전 후 cNode가 루트.
}

BTreeNode* RotateRR(BTreeNode* bst) {
	BTreeNode* pNode;//parent
	BTreeNode* cNode;//child
	pNode = bst;
	cNode = getRightSubTree(pNode);

	changeRightSubTree(pNode, getLeftSubTree(cNode));
	changeLeftSubTree(cNode, pNode); // RR회전 수행

	return cNode; //RR회전 후 cNode가 루트.
}

BTreeNode* RotateLR(BTreeNode* bst) {// AVL 트리 LR회전 수행

	BTreeNode* pNode;//parent
	BTreeNode* cNode;//child
	pNode = bst;
	cNode = getLeftSubTree(pNode);

	//LR회전 수행
	changeLeftSubTree(pNode, RoatateRR(cNode)); // 부분적 RR회전
	return RotateLL(pNode); // LL회전 결과값 리턴
}

BTreeNode* RotateRL(BTreeNode* bst) {// AVL 트리 RL회전 수행

	BTreeNode* pNode;//parent
	BTreeNode* cNode;//child
	pNode = bst;
	cNode = getRightSubTree(pNode);

	//RL회전 수행
	changeRightSubTree(pNode, RoatateLL(cNode)); // 부분적 LL회전
	return RotateRR(pNode); // RR회전 결과값 리턴
}

int getHeightDiff(BTreeNode* p);

//상위 함수를 모두 모아 매 삽입/삭제마다 높이 차이를 검사하여 리밸런싱하는 함수
BTreeNode* rebalance(BTreeNode** proot) {// 메인의 리밸런싱 후에 루트가 변경되는 경우도 있으므로 이중 포인터를 받음

	int hDiff = getHeightDiff(*proot);//균형인수
	//균형인수가 2이상이면 LL/LR 상태
	if (hDiff > 1) {//+2 이상이면 왼쪽 서브트리 방향으로 높이가 2이상 큰 경우(hDiff=leftsubheight-rightsubheigt)
		if (getHeightDiff(getLeftSubTree(*proot)) > 0) *proot = RotateLL(*proot);
		else *proot = RotateLR(*proot);
	}
	if (hDiff < -1) { // -2이하이면 오른쪽 서브트리 방향으로 높이가 2이상 큰 경우.
		if (getHeightDiff(getRightSubTree(*proot)) < 0) *proot = RotateRR(*proot);
		else *proot = RotateRL(*proot);
	}
	return *proot;
}
