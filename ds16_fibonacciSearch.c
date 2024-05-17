#include<stdio.h>

int min(int x, int y) { return (x <= y) ? x : y; }

int fibonaccisearch(int arr[], int x, int n) { // ã���� �ϴ� key==x, �迭 ũ�� n.
	
	int fibM2 = 0; // fib m-2 th ����
	int fibM1 = 1; // �Ǻ���ġ m-1th ����
	int fibM = fibM2 + fibM1;
	
	while (fibM < n) {
		fibM2 = fibM1;
		fibM1 = fibM;
		fibM = fibM2 + fibM1;//������ ���ڱ��� �Ǻ���ġ ����. ���� fibM�� ������ ���� n���� ū, ���� ���� �Ǻ���ġ ��.
	}

	int offset = -1;

	while (fibM > 1) {
		int i = min(offset + fibM2, n - 1); // �Ǻ���ġ ������� �迭 �߶� Ž��
		if (arr[i] < x) { // ���� ��
			fibM = fibM1;
			fibM1 = fibM2;
			fibM2 = fibM - fibM1;
			offset = i;
		}
		else if (arr[i] > x) { // Ŭ ��
			fibM = fibM2;
			fibM1 = fibM1 - fibM2;
			fibM2 = fibM - fibM1;
		}
		else return i; // �ش� �� �ִ� �ε���
	}

	if (fibM1 && arr[offset + 1] == x) return offset + 1; // x�� index = offset+1�� ��ȯ.
	return -1;
}