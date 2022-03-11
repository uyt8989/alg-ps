#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define gw 1
#define mw 0

int T, N;
int cards[1001];
int dp[2][1001][1001];

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int MIN(int a, int b) {
	if (a < b) return a;
	return b;
}

int dfs(int turn, int left, int right) {
	if (left > right) return 0;

	if (dp[turn][left][right] != -1) return dp[turn][left][right];
	
	if (turn == gw)
		dp[turn][left][right] = MAX(dfs(!turn, left + 1, right) + cards[left],
			dfs(!turn, left, right - 1) + cards[right]);
	if (turn == mw)
		dp[turn][left][right] = MIN(dfs(!turn, left + 1, right),
			dfs(!turn, left, right - 1));

	return dp[turn][left][right];
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &cards[i]);
		
		memset(dp, -1, sizeof(dp));

		printf("%d\n", dfs(gw, 1, N));
	}

	return 0;
}
