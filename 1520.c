#include <stdio.h>

int N, M;
int map[502][502] = { 0, };
int dp[502][502] = { 0, };

int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };

int in_boundary(int x, int y) {
	if (x >= 1 && x <= N && y >= 1 && y <= M)
		return 1;
	return 0;
}

int find_path(int x, int y) {
	if (x == N && y == M) {
		return 1;
	}

	else if (dp[x][y] == -1) {
		dp[x][y] = 0;
		for (int k = 0; k < 4; k++) {
			int nx, ny;
			nx = x + next_x[k];
			ny = y + next_y[k];
			if (in_boundary(nx, ny))
				if (map[nx][ny] < map[x][y])
					dp[x][y] += find_path(nx, ny);
		}
	}

	return dp[x][y];
}


int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &map[i][j]);


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			dp[i][j] = -1;

	printf("%d\n", find_path(1, 1));

	return 0;
}
