#include <iostream>
#include <vector>

using namespace std;


int n, m, a, b;
int root[500000];
vector<pair<int, int>> include;

int find(int x) {
	if (root[x] == x) return x;
	return root[x] = find(root[x]);
}

void union_set(int x, int y) {
	if (x > y) root[x] = y;
	else root[y] = x;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		root[i] = i;


	int ans = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		int rootA = find(a);
		int rootB = find(b);

		if (rootA != rootB)
			union_set(rootA, rootB);
		else {
			ans = i + 1;
			break;
		}
	}

	printf("%d\n", ans);

	return 0;
}
