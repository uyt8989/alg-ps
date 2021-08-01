#include <stdio.h>

int N, M;
int mat[502][502] = { 0, };
int visited[502][502] = { 0, };
int start_x, start_y;
int max = 0;
int maxxx[19];

int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int in_boundary(int i, int j) {
	if (i > 0 && i <= N && j > 0 && j <= M)
		return 1;
	return 0;
}

void get_max(int i, int x, int y, int sum) {
	int nx, ny;
	if (i == 4) {
		visited[x][y] = i;
		max = MAX(max, sum + mat[x][y]);
	}
	
	else{
		visited[x][y] = i;
		for (int k = 0; k < 4; k++) {
			nx = x + next_x[k]; ny = y + next_y[k];
			if (in_boundary(nx, ny) && !visited[nx][ny]) {
				get_max(i + 1, nx, ny, sum + mat[x][y]);
			}
		}
	}
	visited[x][y] = 0;
}

void fuckyou(int i, int j) {
	int sum = 0;
	int nx, ny;

	sum = mat[i][j] + mat[i - 1][j] + mat[i][j + 1] + mat[i + 1][j] + mat[i][j - 1];

	for (int k = 0; k < 4; k++) {
		nx = i + next_x[k]; ny = j + next_y[k];
		max = MAX(max, sum - mat[nx][ny]);
	}
}
 
int main() {
	scanf("%d %d", &N, &M);

	max = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &mat[i][j]);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			get_max(1, i, j, 0);
			fuckyou(i, j);
		}

	printf("%d\n", max);

	return 0;
}
