#include <stdio.h>

int N, M;
int arr[2001] = { 0, };
int dp[2001][2001] = { 0 , };
int S, E;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		dp[i][i] = 1;
		if (arr[i] == arr[i - 1]) dp[i][i - 1] = 1;
		else dp[i][i - 1] = 0;
	}

	int j;
	for (int d = 1; d <= N-1; d++) {
		for (int i = 1; i <= N - d; i++) {
			j = i + d;
			if (arr[i] == arr[j] && dp[i + 1][j - 1]) dp[i][j] = 1;
			else dp[i][j] = 0;
		}
	}

	scanf("%d", &M);
	for (int t = 1; t <= M; t++) {
		scanf("%d %d", &S, &E);
		printf("%d\n", dp[S][E]);
	}

	return 0;
}
