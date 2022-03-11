#include <stdio.h>

int R, C;
char mat[21][21] = { 0, };
int visited[26] = { 0, };
int max = 0;

int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int promising(int i, int x, int y) {
	if (x >= 1 && x <= R && y >= 1 && y <= C) {
		if (!visited[mat[x][y] - 'A'])
			return 1;
	}
	return 0;
}

void find_sol(int i, int x, int y) {
	if (promising(i, x, y)) {
		visited[mat[x][y] - 'A'] = 1;

		max = MAX(max, i);
		for (int k = 0; k < 4; k++) {
			int nx = x + next_x[k], ny = y + next_y[k];
			find_sol(i + 1, nx, ny);
		}
		visited[mat[x][y] - 'A'] = 0;
	}
}

int main() {
	scanf("%d %d\n", &R, &C);

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf(" %c", &mat[i][j]);
		}
	}

	find_sol(1, 1, 1);

	printf("%d\n", max);

	return 0;
}
