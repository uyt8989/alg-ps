#include <stdio.h>
#include <stdlib.h>

int N, L, R;
int nation[51][51];
int visit[51][51];
int union_num;
int days = 0;

int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };

int sum[2500] = { 0, };
int n[2500] = { 0, };

void init() {
	union_num = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			visit[i][j] = -1;
}

void make_union(int x, int y, int num) {
	int nx, ny;
	
	visit[x][y] = num;
	sum[num] += nation[x][y];
	n[num]++;

	for (int i = 0; i < 4; i++) {
		nx = x + next_x[i];
		ny = y + next_y[i];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
			if (abs(nation[x][y] - nation[nx][ny]) >= L
				&& abs(nation[x][y] - nation[nx][ny]) <= R && visit[nx][ny] == -1) {
				make_union(nx, ny, num);
			}
		}
	}

	return;
}

int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &nation[i][j]);

	while (1) {
		init();
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visit[i][j] == -1) {
					sum[union_num] = 0;
					n[union_num] = 0;
					make_union(i, j, union_num++);
				}
			}
		}

		if (union_num == N * N)
			break;

		else {
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					nation[i][j] = sum[visit[i][j]] / n[visit[i][j]];

			/*
			for (int u = 0; u < union_num; u++) {
				int sum = 0;
				int n = 0;
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						if (visit[i][j] == u) {
							sum += nation[i][j]; 
							n++;
						}
					}
				} => 시간초과로 DFS 돌면서 sum과 n을 계산하도록 함
			*/


			/*
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						if (visit[i][j] == u)
							nation[i][j] = sum[u] / n[u];
					}
				} => 3중 for문 시간초과
			}
			*/
			days++;
		}
	}

	printf("%d\n", days);
	return 0;
}
