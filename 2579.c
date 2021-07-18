#include <stdio.h>

int N;
int S[301] = { 0, };
int dp[301] = { 0, };

int max(int a, int b) {
	return (a > b ? a : b);
}

int calc(int n) {
	if (dp[n] == 0) {
		dp[n] = max(calc(n - 2), calc(n - 3) + S[n - 1]) + S[n];
	}
	return dp[n];
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i < N+1; i++)
		scanf("%d", &S[i]);

	dp[0] = S[0] = 0;
	dp[1] = S[1];

	if (N >= 2)
		dp[2] = S[1] + S[2];
	if (N >= 3)
		dp[3] = max(S[1] + S[3], S[2] + S[3]);

	printf("%d\n", calc(N));

	return 0;
}
