#include <stdio.h>

#define INF 999

int M[7][7];
int P[7][7];
int d[7] = { 5, 2, 3, 4, 6, 7, 8 };



void minimum(int *minValue, int *minK, int i, int j) {
	int value;

	*minValue = INF;
	*minK = 0;

	for (int k = i; k < j; k++) {
		value = M[i][k] + M[k + 1][j];
		value += d[i - 1] * d[k] * d[j];
		if (*minValue > value) {
			*minValue = value;
			*minK = k;
		}
	}
}

void minmult() {
	int j;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			M[i][j] = -1;
			P[i][j] = -1;
		}
	}
	for (int i = 1; i < 7; i++)
		M[i][i] = 0;
	for (int diagonal= 1; diagonal < 6; diagonal++) {
		for (int i = 1; i < 7 - diagonal + 1; i++) {
			j = i + diagonal;
			minimum(&M[i][j], &P[i][j], i, j);
		}
	}
}

void order(int i, int j) {
	int k;

	if (i == j)
		printf("A%d", i);
	else {
		k = P[i][j];
		printf("(");
		order(i, k);
		order(k + 1, j);
		printf(")");
	}
}

int main() {
	
	minmult();
	printf("M = \n");
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++)
			printf("%d\t", M[i][j]);
		printf("\n");
	}
	printf("P = \n");
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++)
			printf("%d\t", P[i][j]);
		printf("\n");
	}

	printf("\nminimum order: ");
	order(1, 6);

	return 0;
}
