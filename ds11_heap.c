#include<stdio.h> // �켱���� ť�� ���� �� ���� ȿ������ ����. - ������ ��ȯ���� �׻� Ű���� ���� ũ�ų� ���� ���̹Ƿ� �켱���� ť�� �����ϴµ� �����ϴ�.
#define MAX_SIZE 100

typedef struct{ //��� ���� element
	int key;
}element;

typedef struct { // heap ����ü.
	element heap[MAX_SIZE]; //�迭�� heap ����
	int heap_size;
}HeapType;

void init(HeapType* h) { // �� �ʱ�ȭ
	h->heap_size = 0;
}

HeapType* create() {
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	h->heap_size = 0;
	return h;
}

void insert_max_heap(HeapType*h, element item) { //max_heap �� �� �߰�. ���� �Ʒ��� �߰��� �ڿ� �θ�� ���Ͽ� �� ũ�� �ö󰡰� �ƴϸ� �����.
	int i;
	i = ++(h->heap_size); //heap_size 1 ������ ���ÿ� i�� ��ü ���� ����.
	while ((i != 1) && item.key > h->heap[i / 2].key) {//���� ���� element�� �ƴϸ鼭 �θ𺸴� �ڽ��� key���� �� Ŭ��쿡
		h->heap[i] = h->heap[i / 2]; // �ڽ���ġ�� �θ��� ���� ����.
		i /= 2; //��ĭ �ö����Ƿ� i�� ���� ������.(Ȧ���� ������ ������ �� ì��)
	}
	h->heap[i] = item; //���̻� �θ𺸴� ũ�� �ʰų�, ������ �� �� ����.
}

element delete_max_heap(HeapType* h) { // max_heap�� �� ����. ���� �� ��(�켱������ ���� ���� element-item)�� ��ȯ�ϰ�, �� �������� �ִ� ���(temp)�� �� ���� �ø� �� �θ��ڽİ��� �񱳸� ���� ��ġ��ȯ.
	int parent, child;
	element item, temp;
	item = h->heap[1]; // ��ȯ�� ��=�켱������ ���� ���� ��.
	temp = h->heap[(h->heap_size)--]; // �� ������ ���� temp�� �ְ�, ���̸� �ϳ� ����.
	parent = 1;
	child = 2;//���� �� ����� �ε���
	while (child <= h->heap_size) {//�ڽ��� �ε����� ��ü ���̺��� ���� ��
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) child++; // �ڽĳ�� �ΰ��� �� ū �� ã�Ƽ� �ε��� ����.
		if (temp.key >= h->heap[child].key) break; // �� �������� �ִ� temp�� Ű ���� heap�� ���� �����ϵ��� �θ�>=�ڽ��̸� ����
		h->heap[parent] = h->heap[child]; //���� �ƴ϶�� �θ��ڸ��� �ڽ� Ű���� �ְ�
		parent = child; 
		child *= 2; //�Ʒ��� ��ĭ �ϰ�, �ݺ�
	}
	h->heap[parent] = temp; //heap�� ���� �����Ѵ�=�θ� �ڸ����� �ڽĺ��� ũ��. ���� �� ���� ������ �����ϹǷ� parent�� ��ġ�� temp ����
	return item; // ������ �׸� ��ȯ.
}

void heap_sort(element a[], int n) { //�������� - ���� ū �� ��� �ʿ��� �� ����. ���� ��ü ���� �ð��� O(logn)���� ������.
	int i;
	HeapType h;
	init(&h);
	for (i = 0; i < n; i++) {
		insert_max_heap(&h, a[i]); //������ n���� ��Ҹ� �ִ� ������ ����
	}
	for (i = (n - 1); i >= 0; i--) { // ������� �ٽ� �迭�� ����.
		a[i] = delete_max_heap(&h);
	}
}