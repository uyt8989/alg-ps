#include <stdio.h>

int N;
int A[1001] = { 0 , };
int res[1001] = { 0, };

int max(int a, int b) {
	return (a > b ? a : b);
}

int dp() {
	int sol = 1;

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < i; j++) 
			if (A[i] > A[j]) res[i] = max(res[i], res[j] + 1);
		sol = max(sol, res[i]);
	}

	return sol;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &A[i]);
		res[i] = 1;
	}

	printf("%d\n", dp());

	return 0;
}