#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

#define INF 1000000001

int N, M;

void init(vector<pair<int, int>> &tree, vector<int>& numbers, int start, int end, int node) {
	if (start == end) {
		tree[node].first = tree[node].second = numbers[start];
		return ;
	}

	int mid = (start + end) / 2;

	init(tree, numbers, start, mid, 2 * node);
	init(tree, numbers, mid + 1, end, 2 * node + 1);

	tree[node].first = max(tree[2 * node].first, tree[2 * node + 1].first);
	tree[node].second = min(tree[2 * node].second, tree[2 * node + 1].second);
}

pair<int, int> find(vector<pair<int, int>>& tree, int start, int end, int node, int left, int right) {
	if (left > end || right < start) return make_pair(0, INF);
	if (left <= start && end <= right) return tree[node];
	
	pair<int, int> lpair, rpair;
	int mid = (start + end) / 2;

	lpair = find(tree, start, mid, 2 * node, left, right);
	rpair = find(tree, mid + 1, end, 2 * node + 1, left, right);

	return make_pair(max(lpair.first, rpair.first), min(lpair.second, rpair.second));
}

int main() {
	scanf("%d %d", &N, &M);

	vector<int> numbers(N);

	for (int i = 0; i < N; i++)
		scanf("%d", &numbers[i]);

	int h = ceil(log2(N));
	h = (1 << (h + 1));

	vector<pair<int, int>> tree(h);

	init(tree, numbers, 0, N - 1, 1);

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);

		pair<int, int> res = find(tree, 0, N - 1, 1, a - 1, b - 1);

		printf("%d %d\n", res.second, res.first);
	}

	return 0;
}
