#include <stdio.h>


int arr[1025][1025];
int x1, y1, x2, y2;
int result;
int N, M;
int sum[1025][1025] = { 0, };


void calc(int x1, int y1, int x2, int y2) {
	result = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
	printf("%d\n", result);
}

void make_sum() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
		}
	}
}

int main() {
	scanf("%d %d ", &N, &M);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			scanf("%d", &arr[i][j]);
	make_sum();

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		calc(x1, y1, x2, y2);
	}

	return 0;
}
