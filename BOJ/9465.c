#include <stdio.h>

int T;
int n;
int sticker[2][100001] = { 0, };
int dp[2][100001] = { 0, };

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &sticker[i][j]);

		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];

		for (int i = 2; i <= n; i++) {
			dp[0][i] = sticker[0][i] + MAX(dp[1][i - 2], dp[1][i - 1]);
			dp[1][i] = sticker[1][i] + MAX(dp[0][i - 2], dp[0][i - 1]);
		}

		printf("%d\n", MAX(dp[0][n], dp[1][n]));
	}
}
