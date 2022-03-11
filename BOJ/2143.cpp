#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
int A[1001], B[1001];
vector<int> sumA, sumB;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	cin >> M;
	for (int i = 1; i <= M; i++)
		cin >> B[i];

	for (int i = 1; i <= N; i++) {
		int sum = A[i];
		sumA.push_back(sum);
		for (int j = i + 1; j <= N; j++) {
			sum += A[j];
			sumA.push_back(sum);
		}
	}

	for (int i = 1; i <= M; i++) {
		int sum = B[i];
		sumB.push_back(sum);
		for (int j = i + 1; j <= M; j++) {
			sum += B[j];
			sumB.push_back(sum);
		}
	}

	sort(sumB.begin(), sumB.end());
	
	long long ans = 0;

	for (auto item : sumA) {
		int diff = T - item;
		auto up = upper_bound(sumB.begin(), sumB.end(), diff);
		auto low = lower_bound(sumB.begin(), sumB.end(), diff);
		ans += (up - low);
	}

	cout << ans << '\n';

	return 0;
}
