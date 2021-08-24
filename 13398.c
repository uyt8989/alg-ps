#include <stdio.h>

#define INF -987654321;

int n;
int arr[100002];
int dp[100002][2] = { 0, };

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0][0] = dp[0][1] = arr[0] = INF;
	int max = arr[1];
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][1] = arr[i];
		dp[i][0] = MAX(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = MAX(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		max = MAX(max, MAX(dp[i][0], dp[i][1]));
	}

	printf("%d\n", max);

	return 0;
}
