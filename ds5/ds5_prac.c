#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int list[MAX_SIZE];
    int length;
}ArrayListType;

void init(ArrayListType* L) {
    L->length = 0;
}

int is_empty(ArrayListType* L) {
    return(L->length == 0);
}

int is_full(ArrayListType* L) {
    return(L->length == MAX_SIZE);
}

void addlist(ArrayListType* L, int data, int position) {
    if (!is_full(L) && position <= L->length) {
        for (int i = (L->length - 1); i >= position; i--) {
            L->list[i + 1] = L->list[i];
        }
        L->list[position] = data;
        L->length++;
    }
    else {
        printf("invalid");
        return;
    }
}

int deletelist(ArrayListType* L, int position) {
    if (!is_empty(L) && L->length >= position) {
        int item = L->list[position];
        for (int i = position; i < L->length; i++) {
            L->list[i] = L->list[i + 1];
        }
        L->length--;
        return item;
    }
    else {
        printf("invalid");
        return 0;
    }
}

int main()
{
    ArrayListType A = { {1,2,3,4,5},5 };
    int pos, data;
    printf("추가할 위치와 값을 쓰시오");
    scanf("%d %d", &pos, &data);
    addlist(&A, data, pos);
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.list[i]);
    }
    printf("\n");
    printf("삭제할 위치를 쓰시오");
    scanf("%d", &pos);
    int item = deletelist(&A, pos);
    printf("%d\n", item);
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.list[i]);
    }
    return 0;
}
