#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
char arr[10000][10000];

void star(int size, int srow, int scol) {
	if (size == 3) {
		arr[srow + 1][scol + 1] = ' ';
		return ;
	}

	int mrow1 = srow + size / 3;
	int mcol1 = scol + size / 3;
	int mrow2 = mrow1 + size / 3;
	int mcol2 = mcol1 + size / 3;

	star(size / 3, srow, scol);
	star(size / 3, srow, mcol1);
	star(size / 3, srow, mcol2);

	star(size / 3, mrow1, scol);
	for (int i = mrow1; i < mrow2; i++)
		for (int j = mcol1; j < mcol2; j++)
			arr[i][j] = ' ';
	star(size / 3, mrow1, mcol2);

	
	star(size / 3, mrow2, scol);
	star(size / 3, mrow2, mcol1);
	star(size / 3, mrow2, mcol2);
}


int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = '*';


	star(N, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}

	return 0;
}
