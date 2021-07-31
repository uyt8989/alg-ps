#include <stdio.h>

int N;
int A[1000] = { 0, };
int dp1[1000] = { 0, };
int dp2[1000] = { 0, };

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < N; i++)
		dp1[i] = dp2[i] = 1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			if (A[i] > A[j]) dp1[i] = MAX(dp1[i], dp1[j] + 1);

	for (int i = N-1; i >= 0; i--)
		for (int j = N-1; j > i; j--)
			if (A[i] > A[j]) dp2[i] = MAX(dp2[i], dp2[j] + 1);

	int max = dp1[0] + dp2[0];
	for (int i = 0; i < N; i++) {
		if (max < dp1[i] + dp2[i]) {
			max = dp1[i] + dp2[i];
		}
	}

	printf("%d", max - 1);


	return 0;
}
