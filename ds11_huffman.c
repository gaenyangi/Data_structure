#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 100

typedef struct TreeNode {
	int weight;
	TreeNode* left_child;
	TreeNode* right_child;
}TreeNode;

typedef struct {
	TreeNode* ptree;
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node == NULL) {
		fprintf(stderr, "�޸𸮿���\n");
		exit(1);
	}
	node->left_child = left;
	node->right_child = right;
	return node;
}

void destroy_tree(TreeNode* root)
{
	if (root == NULL) return;
	destroy_tree(root->left_child);
	destroy_tree(root->right_child);
	free(root);
}

void huffman_tree(int freq[], int n)
{
	int i;
	TreeNode* node, * x;
	HeapType heap;
	element e, e1, e2;
	init(&heap);
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(&heap, e);
	}
	for (i = 1; i < n; i++) {
		// �ּҰ��� ������ �ΰ��� ��带 ����
		e1 = delete_min_heap(&heap);
		e2 = delete_min_heap(&heap);
		// �ΰ��� ��带 ��ģ��
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		insert_min_heap(&heap, e);
	}
	e = delete_min_heap(&heap); // ���� Ʈ��
	destroy_tree(e.ptree);
}