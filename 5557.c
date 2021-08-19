#include <stdio.h>

int N;
int num[101];
long long dp[101][21] = { 0, };
long long ans = 0;

int promising(int i, int sum) {
	if (i <= N - 1 && sum >= 0 && sum <= 20)
		return 1;
	return 0;
}

void DFS(int i, int sum) {
	if (promising(i, sum)) {
		if (i == N - 1) {
			if (sum == num[N]) {
				ans++;
			}
			return;
		}
		printf("%d\n", sum);
		DFS(i + 1, sum + num[i + 1]);
		DFS(i + 1, sum - num[i + 1]);
	}
	return;
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &num[i]);

	dp[1][num[1]]++;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + num[i] <= 20) dp[i][j + num[i]] += dp[i - 1][j];
				if (j - num[i] >= 0) dp[i][j - num[i]] += dp[i - 1][j];
			}
		}
	}

	printf("%lld\n", dp[N - 1][num[N]]);

	return 0;
}
