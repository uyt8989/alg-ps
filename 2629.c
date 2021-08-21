#include <stdio.h>
#include <stdlib.h>

int wn, mn;
int w[31], m[8];
int dp[31][15001] = { 0, };
int sum = 0;

void knapsack(int i, int r) {
	if (i > wn) return;
	if (dp[i][r] == 1) return;
	if (r > 15000) return;

	dp[i][r] = 1;

	knapsack(i + 1, r + w[i]);
	knapsack(i + 1, r);
	knapsack(i + 1, abs(r - w[i]));
}

int main() {
	scanf("%d", &wn);
	for (int i = 0; i < wn; i++)
		scanf("%d", &w[i]);

	knapsack(0, 0);

	scanf("%d", &mn);
	for (int i = 1; i <= mn; i++) 
		scanf("%d", &m[i]);


	for (int i = 1; i <= mn; i++) {
		if (m[i] > 15000) printf("N ");
		else if (dp[wn][m[i]] == 1) printf("Y ");
		else printf("N ");
	}

	return 0;
}
