#include <iostream>

#define MAX 1000000

int N, M, K;
long long numbers[MAX];
long long tree[4 * MAX + 1];

long long init(int start, int end, int node) {
	if (start == end) return tree[node] = numbers[start];

	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long dif) {
	if (index < start || index > end) return;

	tree[node] += dif;

	if (start == end) {
		numbers[index] += dif;
		return;
	}

	int mid = (start + end) / 2;

	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
	std::cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		std::cin >> numbers[i];

	init(0, N - 1, 1);

	int a, b;
	long long c;
	for (int i = 0; i < M + K; i++) {
		std::cin >> a >> b >> c;

		if (a == 1) {
			update(0, N - 1, 1, b - 1, c - numbers[b - 1]);
		}

		else {
			std::cout << sum(0, N - 1, 1, b - 1, (int)c - 1) << "\n";
		}
	}

	return 0;
}
