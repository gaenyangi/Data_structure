#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	struct BTreeNode* right;
	struct BTreeNode* left;
}BTreeNode;

//��ü���� BST�� �����ϴ�(�¿� ����Ʈ�� ���� ���̴� 2 �̸�) AVL Ʈ��


//��Ʈ�� ���� �� ������ ����Ʈ�� ����
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

	changeLeftSubTree(pNode, getRightSubTree(cNode)); //���� ���̰� 2 ���̳��Ƿ� ù��° ����(cnode)�� ��� ���ø��� ��.
	changeRightSubTree(cNode, pNode); // LLȸ�� ����

	return cNode; //LLȸ�� �� cNode�� ��Ʈ.
}

BTreeNode* RotateRR(BTreeNode* bst) {
	BTreeNode* pNode;//parent
	BTreeNode* cNode;//child
	pNode = bst;
	cNode = getRightSubTree(pNode);

	changeRightSubTree(pNode, getLeftSubTree(cNode));
	changeLeftSubTree(cNode, pNode); // RRȸ�� ����

	return cNode; //RRȸ�� �� cNode�� ��Ʈ.
}

BTreeNode* RotateLR(BTreeNode* bst) {// AVL Ʈ�� LRȸ�� ����

	BTreeNode* pNode;//parent
	BTreeNode* cNode;//child
	pNode = bst;
	cNode = getLeftSubTree(pNode);

	//LRȸ�� ����
	changeLeftSubTree(pNode, RoatateRR(cNode)); // �κ��� RRȸ��
	return RotateLL(pNode); // LLȸ�� ����� ����
}

BTreeNode* RotateRL(BTreeNode* bst) {// AVL Ʈ�� RLȸ�� ����

	BTreeNode* pNode;//parent
	BTreeNode* cNode;//child
	pNode = bst;
	cNode = getRightSubTree(pNode);

	//RLȸ�� ����
	changeRightSubTree(pNode, RoatateLL(cNode)); // �κ��� LLȸ��
	return RotateRR(pNode); // RRȸ�� ����� ����
}

int getHeightDiff(BTreeNode* p);

//���� �Լ��� ��� ��� �� ����/�������� ���� ���̸� �˻��Ͽ� ���뷱���ϴ� �Լ�
BTreeNode* rebalance(BTreeNode** proot) {// ������ ���뷱�� �Ŀ� ��Ʈ�� ����Ǵ� ��쵵 �����Ƿ� ���� �����͸� ����

	int hDiff = getHeightDiff(*proot);//�����μ�
	//�����μ��� 2�̻��̸� LL/LR ����
	if (hDiff > 1) {//+2 �̻��̸� ���� ����Ʈ�� �������� ���̰� 2�̻� ū ���(hDiff=leftsubheight-rightsubheigt)
		if (getHeightDiff(getLeftSubTree(*proot)) > 0) *proot = RotateLL(*proot);
		else *proot = RotateLR(*proot);
	}
	if (hDiff < -1) { // -2�����̸� ������ ����Ʈ�� �������� ���̰� 2�̻� ū ���.
		if (getHeightDiff(getRightSubTree(*proot)) < 0) *proot = RotateRR(*proot);
		else *proot = RotateRL(*proot);
	}
	return *proot;
}