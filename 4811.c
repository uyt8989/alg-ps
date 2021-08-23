#include <stdio.h>

int N;
long long int dp[35][35] = { 0, };

int main() {
	for (int i = 1; i <= 30; i++)
		dp[i][1] = i;

	for (int i = 1; i <= 30; i++) {
		for (int j = 2; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	while (1) {
		scanf("%d", &N);
		if (N == 0)
			break;

		printf("%lld\n", dp[N][N]);
	}


	return 0;
}
