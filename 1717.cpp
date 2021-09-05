#include <iostream>

using namespace std;

int root[1000001];

int find(int x) {
	if (root[x] == x)
		return x;
	return root[x] = find(root[x]);
}

void union_set(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	root[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		root[i] = i;

	int o, a, b;
	for (int i = 0; i < m; i++) {
		cin >> o >> a >> b;

		if (a == b) {
			if (o == 1)
				cout << "YES\n";
		}

		else if (o == 0)
			union_set(a, b);
		else {
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
