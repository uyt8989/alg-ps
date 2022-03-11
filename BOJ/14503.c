#include <stdio.h>

enum direction { N, W, S, E };
int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, -1, 0, 1 };
int back_x[4] = { 1, 0, -1, 0 };
int back_y[4] = { 0, 1, 0, -1 };

int n, m, r,c, d;
int mat[50][50];
int count = 0;


void clean(int i, int j, int d) {
	int nx, ny, bx, by;
	
	if (!mat[i][j]) {
		count++;
		mat[i][j] = 2;
	}
	
	for (int k = 0; k < 4; k++) {
		d = (d + 1) % 4;
		nx = i + next_x[d]; ny = j + next_y[d];
		if (!mat[nx][ny]) {
			clean(nx, ny, d);
			return;
		}
	}
	
	bx = i + back_x[d]; by = j + back_y[d];
	if (mat[bx][by] == 1) return;

	clean(bx, by, d);
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &mat[i][j]);
	
	if (d == W) d = E;
	else if (d == E) d = W;

	clean(r, c, d);

	printf("%d\n", count);

	return 0;
}
