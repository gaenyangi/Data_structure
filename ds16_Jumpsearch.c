#include<stdio.h>

int jumpsearch(int arr[], int n, int key) { // n�� ��Ҽ�

	int m = sqrt(n); // �����ϱ� ���� ��� ũ�� ->��Ʈ n�� ����.
	int prev = 0;
	while (arr[min(m, n) - 1] < key){
		prev = m;
		m += m; // ��� ũ�⸸ŭ ����
		if (prev >= n) return -1; // ��ü ��Ͽ��� �˻� ����
	}

	while (arr[prev] < key) { //key�� ���Ե� ��� ����
		prev++;
		if (prev == min(m, n)) return -1; //�ش� ��� ������ �˻� ����
	}

	if (arr[prev] == key) return prev; //�˻��� ��ȯ

	return -1;//��������
}

