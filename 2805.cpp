#include <iostream>

#define MAX_TREES 1000000

using namespace std;

int N, M;
long long tree[MAX_TREES];

bool check(long long x) {
	long long ans = 0;

	for (int i = 0; i < N; i++) {
		if(tree[i] > x)
			ans += tree[i] - x;
		if (ans >= M) return true;
	}

	return ans >= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	long long max_height = 0;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		if (tree[i] > max_height)
			max_height = tree[i];
	}

	long long left = 0;
	long long right = max_height;
	long long ans = -1;

	while (left < right) {
		long long mid = (left + right) / 2;

		if (check(mid)) {
			left = mid + 1;
			ans = mid;
		}
		else {
			right = mid;
		}
	}

	cout << ans << '\n';

	return 0;
}
