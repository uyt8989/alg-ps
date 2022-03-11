#include <stdio.h>

#define N  5
#define TARGET 21

int n = N;
int W = TARGET;
int w[N + 1] = { 0, 5, 6, 10, 11, 16 };
int include[N + 1] = { 0, };
int total = 0;

int promising(int i, int weight, int total) {
	if ((weight + total >= W) && (weight == W || weight + w[i + 1] <= W)) {
		return 1;
	}
	return 0;
}

void sum_of_subsets(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (weight == W) {
			for (int j = 1; j < n + 1; j++)
				printf("%d ", include[j]);
			printf("\n");
		}
		else {
			include[i + 1] = 1;
			sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
			include[i + 1] = 0;
			sum_of_subsets(i + 1, weight, total - w[i + 1]);
		}
	}
}

int main() {
	for (int i = 1; i < n + 1; i++)
		total += w[i];
	printf("%d\n", total);

	sum_of_subsets(0, 0, total);

	return 0;
}
