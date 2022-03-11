#include <stdio.h>

int N;
char grid1[100][100];
char grid2[100][100];
char temp[101];
int visit[100][100];
int next_x[4] = { -1, 0, 1, 0};
int next_y[4] = { 0, 1, 0, -1};

int RGB = 0;

int in_boundary(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		return 1;
	return 0;
}

void init() {
	RGB = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;
	}
}

void DFS1(int x, int y) {
	int nx, ny;

	visit[x][y] = RGB + 1;

	for (int i = 0; i < 4; i++) {
		nx = x + next_x[i];
		ny = y + next_y[i];

		if (in_boundary(nx, ny)) {
			if ((!visit[nx][ny]) && (grid1[x][y] == grid1[nx][ny])) {
				DFS1(nx, ny);
			}
		}
	}


	return;
}

void DFS2(int x, int y) {
	int nx, ny;

	visit[x][y] = RGB + 1;

	for (int i = 0; i < 4; i++) {
		nx = x + next_x[i];
		ny = y + next_y[i];

		if (in_boundary(nx, ny)) {
			if ((!visit[nx][ny]) && (grid2[x][y] == grid2[nx][ny])) {
				DFS2(nx, ny);
			}
		}
	}


	return;
}


int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", temp);
		for (int j = 0; j < N; j++) {
			grid1[i][j] = temp[j];

			grid2[i][j] = temp[j];
			if (temp[j] == 'G')
				grid2[i][j] = 'R';
		}
	}

	init();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visit[i][j]) {
				DFS1(i, j);
				RGB++;
			}
	printf("%d ", RGB);

	
	init();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visit[i][j]) {
				DFS2(i, j);
				RGB++;
			}
	printf("%d\n", RGB);

	return 0;
}
