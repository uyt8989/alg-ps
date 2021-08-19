#include <stdio.h>

int T, N, M;
int coins[21] = { 0, };
int dp[10001] = { 0, };

int main() {
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &coins[i]);
		scanf("%d", &M);

		for (int i = 0; i <= M; i++)
			dp[i] = 0;

		for (int i = 1; i <= N; i++) { 
			dp[coins[i]] += 1;
			for (int j = coins[i] + 1; j <= M; j++)
				dp[j] += dp[j - coins[i]];
		}
		printf("%d\n", dp[M]);
	}

	return 0;
}
