#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MOD 1000000000

int N;
int dp[101][10][1<<10];

int main() {
	scanf("%d", &N);
    
	for (int i = 1; i <= 9; i++)
		dp[1][i][1 << i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < 1024; k++) {
				if (j == 0)
					dp[i][0][k | (1 << 0)] = 
                    (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % MOD;
				else if (j == 9)
					dp[i][9][k | (1 << 9)] = 
                    (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % MOD;
				else {
					dp[i][j][k | (1 << j)] = 
                    (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
					dp[i][j][k | (1 << j)] = 
                    (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
				}
			}
		}
	}

	int answer = 0;

	for (int i = 0; i <= 9; i++)
		answer = (answer + dp[N][i][1023]) % MOD;

	printf("%d", answer );

	return 0;
}
