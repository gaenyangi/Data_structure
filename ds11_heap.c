#include<stdio.h> // 우선순위 큐를 만들 때 가장 효과적인 히프. - 히프는 반환값이 항상 키값이 가장 크거나 작은 값이므로 우선순위 큐를 구성하는데 적합하다.
#define MAX_SIZE 100

typedef struct{ //요소 구성 element
	int key;
}element;

typedef struct { // heap 구조체.
	element heap[MAX_SIZE]; //배열로 heap 구성
	int heap_size;
}HeapType;

void init(HeapType* h) { // 힙 초기화
	h->heap_size = 0;
}

HeapType* create() {
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	h->heap_size = 0;
	return h;
}

void insert_max_heap(HeapType*h, element item) { //max_heap 에 값 추가. 가장 아래에 추가한 뒤에 부모와 비교하여 더 크면 올라가고 아니면 멈춘다.
	int i;
	i = ++(h->heap_size); //heap_size 1 증가와 동시에 i에 전체 개수 삽입.
	while ((i != 1) && item.key > h->heap[i / 2].key) {//제일 위의 element가 아니면서 부모보다 자식의 key값이 더 클경우에
		h->heap[i] = h->heap[i / 2]; // 자식위치에 부모의 값을 대입.
		i /= 2; //한칸 올라갔으므로 i를 절반 나눠줌.(홀수라도 나머지 버리고 몫만 챙김)
	}
	h->heap[i] = item; //더이상 부모보다 크지 않거나, 맨위일 때 값 대입.
}

element delete_max_heap(HeapType* h) { // max_heap의 값 삭제. 가장 맨 위(우선순위가 가장 높은 element-item)를 반환하고, 맨 마지막에 있던 요소(temp)를 맨 위로 올린 뒤 부모자식간의 비교를 통해 위치교환.
	int parent, child;
	element item, temp;
	item = h->heap[1]; // 반환할 값=우선순위가 가장 높은 값.
	temp = h->heap[(h->heap_size)--]; // 맨 마지막 값을 temp에 넣고, 길이를 하나 줄임.
	parent = 1;
	child = 2;//비교할 두 노드의 인덱스
	while (child <= h->heap_size) {//자식의 인덱스가 전체 길이보다 작을 때
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) child++; // 자식노드 두개중 더 큰 것 찾아서 인덱스 변경.
		if (temp.key >= h->heap[child].key) break; // 맨 마지막에 있던 temp의 키 값이 heap의 성질 만족하도록 부모>=자식이면 멈춤
		h->heap[parent] = h->heap[child]; //만약 아니라면 부모자리에 자식 키값을 넣고
		parent = child; 
		child *= 2; //아래로 한칸 하강, 반복
	}
	h->heap[parent] = temp; //heap의 성질 만족한다=부모 자리에서 자식보다 크다. 따라서 위 멈춤 조건을 만족하므로 parent의 위치에 temp 삽입
	return item; // 삭제한 항목 반환.
}

void heap_sort(element a[], int n) { //히프정렬 - 가장 큰 값 몇개만 필요할 때 유용. 또한 전체 정렬 시간이 O(logn)으로 빠른편.
	int i;
	HeapType h;
	init(&h);
	for (i = 0; i < n; i++) {
		insert_max_heap(&h, a[i]); //정렬할 n개의 요소를 최대 히프에 삽입
	}
	for (i = (n - 1); i >= 0; i--) { // 순서대로 다시 배열에 삽입.
		a[i] = delete_max_heap(&h);
	}
}