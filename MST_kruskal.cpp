#define _CRT_SECURE_NO_WARNINGS // �׷����� ��� ������ ������������ �����Ͽ� ���� ���� ���� �ϳ��� �����ϴ� ���. �ش� ������ ����Ŭ�� �̷��� ������ ����Ʈ���� ����, �ƴϸ� ���� �ּ� ����ġ�� ���� �������� �̵�. ���������� n���� ������ ���� �� n-1���� ������ ���� ������ �ݺ�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> p;
int v = 6, parent[7];
vector<p> edges;
int find_root(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find_root(parent[x]); //��� ��
	��
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
		//���� ������ �մ� �� ����
		int f = cur_edge.second.first;
		int s = cur_edge.second.second;
		//Union-Find�� ����Ŭ�� �߻��ϴ��� Ȯ��
		if (find_root(f) == find_root(s)) continue;
		//����Ŭ�� �߻��Ѵٸ� �������� ����
		//����Ŭ�� �߻����� �ʴ´ٸ� mst�� ���� ������ �߰�
		mst.push_back(cur_edge);
		//Parent ���� ����
		union_root(f, s);
		//���� ���� ���� v�� ���� v - 1���� ������ ã�Ҵٸ� ����
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
	//�������� ����ġ ���� �������� ����
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
		printf("%d - %d : ��� %d\n", mst[i].second.first,
			mst[i].second.second, mst[i].first);
	}
	return 0;
}