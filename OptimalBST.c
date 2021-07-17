#include <stdio.h>
#define INF 999

int keys[6] = { 0, 10, 20, 30, 40, 50 };
int p[6] = { 0, 35, 12, 22, 8, 15 };

int A[7][7], R[7][7];

void minimum(int* minValue, int* minK, int i, int j) {
	int value;

	*minValue = INF;
	*minK = 0;
	for (int k = i; k < j+1; k++) {
		value = A[i][k - 1] + A[k + 1][j];
		for (int m = i; m < j + 1; m++)
			value += p[m];
		if (*minValue > value) {
			*minValue = value;
			*minK = k;
		}
	}
}

void optsearchtree() {
	int j;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			A[i][j] = -1;
			R[i][j] = -1;
		}
	}

	for (int i = 1; i < 6; i++) {
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		R[i][i - 1] = 0;
		R[i][i] = i;
	}
	A[6][5] = 0;
	R[6][5] = 0;

	for (int diagonal = 1; diagonal < 5; diagonal++) {
		for (int i = 1; i < 5 - diagonal + 1; i++) {
			j = i + diagonal;
			minimum(&A[i][j], &R[i][j], i, j);
		}
	}
}

int main() {
	optsearchtree();

	printf("A = \n");
	for (int i = 1; i < 7; i++) {
		for (int j = 0; j < 6; j++)
			printf("%d\t", A[i][j]);
		printf("\n");
	}
	printf("R = \n");
	for (int i = 1; i < 7; i++) {
		for (int j = 0; j < 6; j++)
			printf("%d\t", R[i][j]);
		printf("\n");
	}
	return 0;
}
