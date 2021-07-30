#include <stdio.h>

int n;
int tri[500][500];
int dp[500][500];

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &tri[i][j]);
	
	dp[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + tri[i][0];	
		for (int j = 1; j <= i -1; j++)
			dp[i][j] = MAX(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
		dp[i][i] = dp[i - 1][i - 1] + tri[i][i];
	}
	
	int max = dp[n - 1][0];
	for (int i = 1; i < n; i++)
		max = MAX(max, dp[n - 1][i]);
	printf("%d\n", max);

	return 0;
}
