#include <iostream>

using namespace std;

int G, P, ans = 0;
int gate[100001] = { 0, };
int root[100001];

int find(int x) {
	if (root[x] == x) return x;
	return root[x] = find(root[x]);
}

void union_set(int a, int b) {
	root[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> G >> P;

	for (int i = 0; i < P; i++)
		cin >> gate[i];

	for (int i = 0; i <= G; i++)
		root[i] = i;
	
	for (int i = 0; i < P; i++) {
		int docking = find(gate[i]);

		if (docking != 0) {
			union_set(docking - 1, docking);
			ans++;
		}

		else break;
	}



	cout << ans << endl;

	return 0;
}
