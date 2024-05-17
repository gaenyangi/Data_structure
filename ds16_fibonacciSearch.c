#include<stdio.h>

int min(int x, int y) { return (x <= y) ? x : y; }

int fibonaccisearch(int arr[], int x, int n) { // 찾고자 하는 key==x, 배열 크기 n.
	
	int fibM2 = 0; // fib m-2 th 숫자
	int fibM1 = 1; // 피보나치 m-1th 숫자
	int fibM = fibM2 + fibM1;
	
	while (fibM < n) {
		fibM2 = fibM1;
		fibM1 = fibM;
		fibM = fibM2 + fibM1;//대입한 숫자까지 피보나치 진행. 따라서 fibM은 대입한 숫자 n보다 큰, 가장 작은 피보나치 수.
	}

	int offset = -1;

	while (fibM > 1) {
		int i = min(offset + fibM2, n - 1); // 피보나치 수열대로 배열 잘라서 탐색
		if (arr[i] < x) { // 작을 때
			fibM = fibM1;
			fibM1 = fibM2;
			fibM2 = fibM - fibM1;
			offset = i;
		}
		else if (arr[i] > x) { // 클 때
			fibM = fibM2;
			fibM1 = fibM1 - fibM2;
			fibM2 = fibM - fibM1;
		}
		else return i; // 해당 값 있는 인덱스
	}

	if (fibM1 && arr[offset + 1] == x) return offset + 1; // x의 index = offset+1을 반환.
	return -1;
}