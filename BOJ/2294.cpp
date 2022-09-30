#include <iostream>

using namespace std;

#define INF 987654321

int n, k;
int coins[101];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	for (int i = 1; i <= 10000; i++) {
		dp[i] = INF;
	}

	for (int i = 1; i <= k; i++) {
		for (int c = 0; c < n; c++) {
			if (coins[c] <= i) {
				if (dp[i - coins[c]] + 1 < dp[i]) {
					dp[i] = dp[i - coins[c]] + 1;
				}
			}
		}
	}

	if (dp[k] == INF) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}

	return 0;
}