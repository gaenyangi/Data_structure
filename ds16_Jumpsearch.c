#include<stdio.h>

int jumpsearch(int arr[], int n, int key) { // n은 요소수

	int m = sqrt(n); // 점프하기 위한 블록 크기 ->루트 n이 최적.
	int prev = 0;
	while (arr[min(m, n) - 1] < key){
		prev = m;
		m += m; // 블록 크기만큼 점프
		if (prev >= n) return -1; // 전체 블록에서 검색 실패
	}

	while (arr[prev] < key) { //key가 포함된 블록 내부
		prev++;
		if (prev == min(m, n)) return -1; //해당 블록 내에서 검색 실패
	}

	if (arr[prev] == key) return prev; //검색값 반환

	return -1;//오류방지
}

