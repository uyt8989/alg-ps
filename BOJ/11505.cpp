#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000001
#define MOD 1000000007

using namespace std;

int N, M, K;
int h, size;
long long input[MAX];
vector<long long> tree;

long long init(int cur, int start, int end) {
	if (start == end) 
		return tree[cur] = input[start];
	
	int mid = (start + end) / 2;

	return tree[cur] = (init(2 * cur, start, mid) * 
		init(2 * cur + 1, mid + 1, end)) % MOD;
}

long long update(int cur, int idx, int start, int end, long long num) {
	if (idx < start || end < idx) return tree[cur];
	if (start == end) return tree[cur] = num;

	int mid = (start + end) / 2;

	return tree[cur] = (update(2 * cur, idx, start, mid, num) * 
		update(2 * cur + 1, idx, mid + 1, end, num)) % MOD;
}

long long multiple(int cur, int start, int end, int left, int right) {
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return tree[cur];

	int mid = (start + end) / 2;

	return (multiple(2 * cur, start, mid, left, right) * 
		multiple(2 * cur + 1, mid + 1, end, left, right)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> input[i];

	h = ceil(log2(N));
	tree.resize(1 << (h + 1));

	init(1, 0, N - 1);
	
	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			input[b - 1] = c;
			update(1, b - 1, 0, N - 1, c);
		}
		else {
			int left = b < c ? b : c; 
			int right = b < c ? c : b;

			cout << multiple(1, 0, N - 1, left - 1, right - 1) << '\n';
		}
	}

	return 0;
}
