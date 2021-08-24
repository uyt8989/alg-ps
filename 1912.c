#include <stdio.h>

#define INF -1987654321;

int n;
int arr[100001];
int dp[100001];
int max = INF;

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = MAX(dp[i - 1] + arr[i], dp[i]);
		max = MAX(max, dp[i]);
	}
	printf("%d\n", max);

	return 0;
}
