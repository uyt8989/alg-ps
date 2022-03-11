#include <stdio.h>
#include <stdlib.h>

#define N 4
#define ABS(a, b) a < b ? ((b)-(a)) : ((a)-(b))

int col[N+1] = { 0, };
int n = N;

void n_queens(int i) {
	if (promising(i)) {
		if (i == n) {
			for (int j = 1; j < n + 1; j++)
				printf("%d ", col[j]);
			printf("\n");
		}
		else {
			for (int j = 1; j < n + 1; j++) {
				col[i + 1] = j;
				n_queens(i + 1);
			}
		}
	}
}

int promising(int i) {
	int k = 1;
	int flag = 1;

	while (k < i && flag) {
		if (col[i] == col[k] || (ABS(col[i], col[k])) == (i - k))
			flag = 0;
		k += 1;
	}
	return flag;
}

int main() {
	n_queens(0);

	return 0;
}
