#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int N, M;
char map[1001][1001];
int visit[1001][1001];
int zone;
int next_x[4] = { -1, 1, 0, 0 };
int next_y[4] = { 0, 0, -1, 1 };

void DFS(int x, int y) {
	int dir;
	visit[x][y] = 1;

	switch (map[x][y]) {
	case 'U': dir = 0; break;
	case 'D': dir = 1; break;
	case 'L': dir = 2; break;
	case 'R': dir = 3; break;
	}

	int nx = x + next_x[dir];
	int ny = y + next_y[dir];

	if (visit[nx][ny] == 1) zone++;
	else if (visit[nx][ny] == 0) DFS(nx, ny);
	visit[x][y] = 2;

}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			scanf("%c", &map[i][j]);
		}
	}

	memset(visit, 0, sizeof(visit));

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++) {
 			if (visit[i][j] == 0) {
				DFS(i, j);
			}
		}
	}

	std::cout << zone;

	return 0;
}
