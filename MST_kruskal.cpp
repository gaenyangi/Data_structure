#define _CRT_SECURE_NO_WARNINGS // 그래프의 모든 간선을 오름차순으로 정렬하여 작은 간선 부터 하나씩 선택하는 방법. 해당 간선이 사이클을 이루지 않으면 신장트리에 구성, 아니면 다음 최소 가중치를 갖는 간선으로 이동. 마찬가지로 n개의 정점이 있을 때 n-1개의 간선이 생길 때까지 반복.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> p;
int v = 6, parent[7];
vector<p> edges;
int find_root(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find_root(parent[x]); //경로 압
	축
}
void union_root(int x, int y) {
	x = find_root(x);
	y = find_root(y);
	if (x != y) parent[y] = x;
}
vector<p> kruskal() {
	vector<p> mst;
	for (int i = 0; i < edges.size(); i++) {
		p cur_edge = edges[i];
		//현재 간선이 잇는 두 정점
		int f = cur_edge.second.first;
		int s = cur_edge.second.second;
		//Union-Find로 사이클이 발생하는지 확인
		if (find_root(f) == find_root(s)) continue;
		//사이클이 발생한다면 선택하지 않음
		//사이클이 발생하지 않는다면 mst에 현재 간선을 추가
		mst.push_back(cur_edge);
		//Parent 관계 갱신
		union_root(f, s);
		//만약 정점 개수 v에 대해 v - 1개의 간선을 찾았다면 종료
		if (mst.size() == v - 1) return mst;
	}
}

void init() {
	edges.push_back({ 1, {1, 5} });
	edges.push_back({ 4, {1, 3} });
	edges.push_back({ 3, {1, 4} });
	edges.push_back({ 9, {1, 2} });
	edges.push_back({ 4, {2, 4} });
	edges.push_back({ 5, {2, 5} });
	edges.push_back({ 6, {3, 6} });
	edges.push_back({ 2, {4, 5} });
	edges.push_back({ 8, {4, 6} });
	//간선들을 가중치 기준 오름차순 정렬
	sort(edges.begin(), edges.end());
	//Union-Find Setting
	for (int i = 1; i <= 6; i++) parent[i] = i;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	init();
	vector<p> mst = kruskal();
	printf("[MST]\n");
	for (int i = 0; i < mst.size(); i++) {
		printf("%d - %d : 비용 %d\n", mst[i].second.first,
			mst[i].second.second, mst[i].first);
	}
	return 0;
}