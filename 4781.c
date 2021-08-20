#include <stdio.h>

int n, m;
double temp;
int c[5001];
int p[5001];
int dp[10001];

int MAX(int a, int b) {
	if (a > b)  return a;
	return b;
}

int main() {
	int max;
	int max_idx;

	while (1) {
		scanf("%d %lf", &n, &temp);
		m = (int)(temp * 100 + 0.5);

		if (n == 0 && temp == 0.00)
			break;

		for (int i = 1; i <= n; i++) {
			scanf("%d %lf", &c[i], &temp);
			p[i] = (int)(temp * 100 + 0.5);
		}

		for (int i = 0; i <= m; i++)
			dp[i] = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (j - p[i] >= 0) 
					dp[j] = MAX(dp[j], dp[j - p[i]] + c[i]);

					
		printf("%d\n", dp[m]);
	}
	return 0;
}
