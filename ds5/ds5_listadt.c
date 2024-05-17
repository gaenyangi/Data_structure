#include<stdio.h> //배열리스트 구현. 앞서 배열의 이름은 포인터주소라고 했으므로 함수의 포인터를 받을 때 굳이 &를 안붙여도 되고 그냥 바로 배열 이름을 사용하면 됨.

#define MAX_SIZE 100
typedef int element; // 항목의 타입을 element로 정의

typedef struct
{
	int list[MAX_SIZE]; //배열
	int length; //배열에 저장된 항목 갯수
}ArrayListType;

void init(ArrayListType* L)
{
	L->length = 0;//앞에서 봤던 포인터 구조체 사용. 리스트 초기화 L->length == (*L).length ; 구조체 포인터 L이 가리키는 구조체의 멤버 length의 값.
}

int is_empty(ArrayListType* L)
{
	return (L->length == 0); //비어 있으면 1, 아니면 0 반환. 같은지 다른지 묻는 조건문.
}

int is_full(ArrayListType* L)
{
	return (L->length == MAX_SIZE); //가득차있으면 1 아니면 0.
}

void add(ArrayListType* L, int position, element item) //  원하는 position에 element item 대입
{
	if (!is_full(L) && (position >= 0) && (position <= L->length)) // 배열이 포화인지, 적합한 위치에 삽입되는지 검사
	{
		int i;
		for (i = (L->length - 1); i >= position; i--)
		{
			L->list[i + 1] = L->list[i]; //한칸씩 밀기
		}
		L->list[position] = item; // 원하는 곳에 대입
		L->length++; // 길이 증가
	}
}

element delete(ArrayListType* L, int position)
{
	int i;
	element item;
	if (position < 0 || position >= L->length) //삭제하려는 것이 적합한지 확인
	{
		error("위치오류");
	}
	item = L->list[position];
	for (i = position; i < (L->length - 1); i++) // item의 위치에서 왼U으로 한칸씩 밀기
	{
		L->list[i] = L->list[i + 1];
	}
	L->length--; //길이 줄이고
	return item; // 삭제된 항목 반환
}
