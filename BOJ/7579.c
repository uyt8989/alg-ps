#include <stdio.h>

int N, M;
int m[101];
int c[101];
int dp[10000001];
int sum1 = 0, sum2 = 0;

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &m[i]);
		sum1 += m[i];
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &c[i]);
		sum2 += c[i];
	}

	M = sum1 - M;
	for (int i = 1; i <= N; i++) {
		for (int j = M; j > 0; j--) {
			if (j - m[i] >= 0)
				dp[j] = MAX(dp[j], dp[j - m[i]] + c[i]);
		}
	}
	
	printf("%d\n", sum2 - dp[M]);

	return 0;
}
