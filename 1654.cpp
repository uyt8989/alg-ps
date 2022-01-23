#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>

using namespace std;

int N, K;
long long lan[10000];

bool check(long long x) {
	int count = 0;
	for (int i = 0; i < K; i++)
		count += lan[i] / x;

	return count >= N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> N;

	for (int i = 0; i < K; i++)
		cin >> lan[i];

	long long l = 1;
	long long r = LLONG_MAX - 1;
	long long answer = 0;

	while (l < r) {
		long long m = (l + r) / 2;

		if (check(m)) {
			l = m + 1;
			answer = m;
		}
		else r = m;
	}

	cout << answer << '\n';

	return 0;
}
