#include <stdio.h>

int N, K;
int dp[1001][1001] = { 0, };

int color_circle (int n, int k) {
	if (n == 1)
		return 1;
	else if (k == 1)
		return n;
	else if (n <= k)
		return 0;
	else
		return color_circle(n - 2, k - 1) + color_circle(n - 1, k);
}

int main() {
	scanf("%d", &N);
	scanf("%d", &K);

	//int ans;
	//ans = color_circle(N - 3, K - 1);
	//ans += color_circle(N - 1, K);

	for (int i = 1; i <= N; i++) {
		dp[i][1] = i;
		for (int j = 2; j <= i / 2; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
		}
	}

	printf("%d\n", dp[N][K]);

	return 0;
}
