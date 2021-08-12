#include <stdio.h>

int n;
int bamboo[502][502] = { 0 , };
int dp[502][502] = { 0, };

int max_idx = 0;

int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int in_boundary(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= n)
		return 1;
	return 0;
}


int DFS(int x, int y) {
	int flag = 0;
	int nx, ny;

	for (int i = 0; i < 4; i++) {
		nx = x + next_x[i];
		ny = y + next_y[i];

		if(in_boundary(nx, ny))
			if (bamboo[x][y] < bamboo[nx][ny])
				flag = 1;
	}
	
	//더 이상 갈 곳이 없을 때
	if (!flag) {
		return 1;
	}

	else if (dp[x][y] == -1) {
		dp[x][y] = 0;

		for (int i = 0; i < 4; i++) {
			nx = x + next_x[i];
			ny = y + next_y[i];

			if (in_boundary(nx, ny))
				if (bamboo[x][y] < bamboo[nx][ny])
					dp[x][y] = MAX(dp[x][y], DFS(nx, ny) + 1);
		}
	}

	return dp[x][y];
}


int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &bamboo[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = -1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			max_idx = MAX(max_idx, DFS(i, j));


	printf("%d", max_idx);

	return 0;
}
