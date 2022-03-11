#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define MAX 4000001

int N, M, K;
int cards[MAX], parent[MAX];

int find(int a) {
	if (a == parent[a]) {
		return parent[a];
	}
	return parent[a] = find(parent[a]);
}

void makeUnion(int a, int b) {
	parent[find(a)] = parent[find(b)];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	int temp;
	for (int i = 0; i < M; i++) {
		cin >> cards[i];
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	sort(cards, cards + M);

	for (int i = 0; i < K; i++) {
		cin >> temp;
		
		int idx = find(upper_bound(cards, cards + M, temp) - cards);

		cout << cards[idx] << '\n';

		makeUnion(idx, idx + 1);
	}

	return 0;
}
