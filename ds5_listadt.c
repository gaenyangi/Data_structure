#include<stdio.h> //�迭����Ʈ ����. �ռ� �迭�� �̸��� �������ּҶ�� �����Ƿ� �Լ��� �����͸� ���� �� ���� &�� �Ⱥٿ��� �ǰ� �׳� �ٷ� �迭 �̸��� ����ϸ� ��.

#define MAX_SIZE 100
typedef int element; // �׸��� Ÿ���� element�� ����

typedef struct
{
	int list[MAX_SIZE]; //�迭
	int length; //�迭�� ����� �׸� ����
}ArrayListType;

void init(ArrayListType* L)
{
	L->length = 0;//�տ��� �ô� ������ ����ü ���. ����Ʈ �ʱ�ȭ L->length == (*L).length ; ����ü ������ L�� ����Ű�� ����ü�� ��� length�� ��.
}

int is_empty(ArrayListType* L)
{
	return (L->length == 0); //��� ������ 1, �ƴϸ� 0 ��ȯ. ������ �ٸ��� ���� ���ǹ�.
}

int is_full(ArrayListType* L)
{
	return (L->length == MAX_SIZE); //������������ 1 �ƴϸ� 0.
}

void add(ArrayListType* L, int position, element item) //  ���ϴ� position�� element item ����
{
	if (!is_full(L) && (position >= 0) && (position <= L->length)) // �迭�� ��ȭ����, ������ ��ġ�� ���ԵǴ��� �˻�
	{
		int i;
		for (i = (L->length - 1); i >= position; i--)
		{
			L->list[i + 1] = L->list[i]; //��ĭ�� �б�
		}
		L->list[position] = item; // ���ϴ� ���� ����
		L->length++; // ���� ����
	}
}

element delete(ArrayListType* L, int position)
{
	int i;
	element item;
	if (position < 0 || position >= L->length) //�����Ϸ��� ���� �������� Ȯ��
	{
		error("��ġ����");
	}
	item = L->list[position];
	for (i = position; i < (L->length - 1); i++) // item�� ��ġ���� �ަU���� ��ĭ�� �б�
	{
		L->list[i] = L->list[i + 1];
	}
	L->length--; //���� ���̰�
	return item; // ������ �׸� ��ȯ
}