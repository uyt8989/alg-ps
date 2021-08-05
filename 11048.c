#include <stdio.h>

int N, M;
int maze[1001][1001] = { 0, };
int dp[1001][1001] = { 0 , };

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &maze[i][j]);

	dp[1][1] = maze[1][1];

	for (int i = 2; i <= N; i++)
		dp[i][1] = dp[i-1][1] + maze[i][1];
	for (int i = 2; i <= M; i++)
		dp[1][i] = dp[1][i-1] + maze[1][i];

	for (int i = 2; i <= N; i++)
		for (int j = 2; j <= M; j++)
			dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + maze[i][j];

	printf("%d\n", dp[N][M]);

	return 0;
}
