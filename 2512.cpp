#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int budget[10000];
int max_budget;

int check(int x) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		if (budget[i] > x) temp += x;
		else temp += budget[i];
	}

	return temp <= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> budget[i];
		max_budget = max(max_budget, budget[i]);
	}

	cin >> M;

	int l = 1;
	int r = max_budget;

	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m)) {
			l = m + 1;
			max_budget = m;
		}
		else r = m - 1;
	}

	cout << max_budget;

	return 0;
}
