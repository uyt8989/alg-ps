#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> prime;
vector<bool> check;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	check.resize(N + 1, true);
	for (int i = 2; i * i <= N; i++){
		if (!check[i]) continue;
		for (int j = i * i; j <= N; j += i){
			check[j] = false;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (check[i]) prime.push_back(i);
	}

	int ans = 0; int sum = 0;
	int left = 0; int right = 0;
	int size = prime.size();

	while (1) {
		if (sum >= N) {
			sum -= prime[left++];
		}
		else if (right == size) break;
		else {
			sum += prime[right++];
		}

		if (sum == N) {
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
