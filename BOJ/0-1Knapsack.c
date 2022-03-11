#include <stdio.h>
#define MAX(a, b) a > b ? a : b

int w[4] = { 0, 5, 10, 20 };
int p[4] = { 0, 50, 60, 140 };

int knapsack(int i, int W) {
	int left, right;

	if (i <= 0 || W <= 0)
		return 0;
	if (w[i] > W)
		return knapsack(i - 1, W);
	else {
		left = knapsack(i - 1, W);
		right = knapsack(i - 1, W - w[i]);
		return MAX(left, p[i] + right);
	}
}

int main() {
	int W = 30;
	
	printf("%d\n", knapsack(3, W));

	return 0;
}
