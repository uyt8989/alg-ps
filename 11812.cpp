#include <iostream>
#include <algorithm>

using namespace std;

long long N;
int K, Q;

long long get_depth(long long x) {
	long long depth;
	long long left, right;

	if (K == 1) {
		return x;
	}

	if (x == 0) return 0;

	depth = 1;
	left = 1; right = K;

	while (!(left <= x && x <= right)) {
		depth++;
		left = left * K + 1;
		right = right * K + K;
	}

	return depth;
}

long long get_parent(long long x) {
	return (x - 1) / K;
}

long long get_distance(long long u, long long v) {
	long long depth_u = get_depth(u);
	long long depth_v = get_depth(v);
	long long ret = 0;

	if (depth_u < depth_v) {
		swap(depth_u, depth_v);
		swap(u, v);
	}

	if (K == 1) {
		return depth_u - depth_v;
	}

	long long diff = depth_u - depth_v;
	ret += diff;
	for (long long i = 0; i < diff; i++) {
		u = get_parent(u);
	}

	while (u != v) {
		u = get_parent(u);
		v = get_parent(v);
		ret += 2;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> Q;

	long long u, v;
	for (int i = 0; i < Q; i++) {
		cin >> u >> v;
		
		cout << get_distance(u - 1, v - 1) << '\n';
	}

	return 0;
}
