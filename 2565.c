#include <stdio.h>

int A[501] = { 0, };
int dp[501] = { 0 , };
int N;

int max(int a, int b) {
	return (a > b ? a : b);
}

int main() {
	int a, b;
	int m = 0;
	int sol = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &a, &b);
		A[a] = b;
		m = max(m, a);
	}

	
	for (int i = 1; i <= m; i++) {
		if (A[i] == 0) continue;
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		sol = max(dp[i], sol);
	}

	//for (int i = 1; i <= m; i++)
	//	printf("%d : %d \n", i, dp[i]);
	//printf("\n%d\n", sol);



	printf("%d\n", N - sol);

	return 0;
}
