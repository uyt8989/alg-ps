#include <stdio.h>

int N;
int RGB[1001][3] = { 0, };
int result[1001][3] = { 0, };

int min(int a, int b) {
	return (a < b ? a : b);
}

void dp() {
	for (int i = 1; i < N + 1; i++) {
		result[i][0] = min(result[i - 1][1], result[i - 1][2]) + RGB[i][0];
		result[i][1] = min(result[i - 1][0], result[i - 1][2]) + RGB[i][1];
		result[i][2] = min(result[i - 1][1], result[i - 1][0]) + RGB[i][2];
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i < N+1; i++)
		scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
	
	dp();

	printf("%d\n", min(min(result[N][0], result[N][1]), result[N][2]));

	return 0;
}