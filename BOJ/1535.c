#include <stdio.h>

int N;
int L[21];
int J[21];
int dp[101] = { 0, };

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &L[i]);

	for (int i = 1; i <= N; i++)
		scanf("%d", &J[i]);

	for (int i = 1; i <= N; i++) {
		for (int j = 100; j >= 1; j--) {
			if (j - L[i] > 0) dp[j] = MAX(dp[j], dp[j - L[i]] + J[i]);
		}
	}

	printf("%d\n", dp[100]);

	return 0;
}
