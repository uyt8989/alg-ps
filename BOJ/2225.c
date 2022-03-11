#include <stdio.h>

int N, K;
long long dp[201][201] = { 0, };

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++)
		dp[1][i]++;
	
	for (int i = 2; i <= K; i++) {//더한 횟수
		for (int j = 0; j <= N; j++) {//만든 값
			//dp[i][j] => i번 더해서 j를 만들 수 있는 경우의 수
			for (int k = 0; k <= N; k++) {//새로 더하는 값
				if (j + k <= N) dp[i][j + k] += dp[i - 1][j] % 1000000000;
			}
		}
	}

	printf("%lld\n", dp[K][N] % 1000000000);

	return 0;
}
