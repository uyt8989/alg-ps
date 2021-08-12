#include <stdio.h>

typedef struct Virus {
	int x, y;
}Virus;

typedef struct NonVirus {
	int x, y;
}NonVirus;

int N, M;
int lab[10][10] = { 0, };
int temp[10][10] = { 0, };
int next_x[4] = { 1, 0, -1, 0 };
int next_y[4] = { 0, 1, 0, -1 };
Virus virus[64];
NonVirus non[64];
int wall[65] = { 0, };
int virus_num = 0;
int non_num = 0;
int max = 0;

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

void init() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			lab[i][j] = 1;
}

void copy() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			temp[i][j] = lab[i][j];
}

void diffusion(int x, int y) {
	int nx, ny;

	temp[x][y] = 2;

	for (int i = 0; i < 4; i++) {
		nx = x + next_x[i];
		ny = y + next_y[i];

		if (temp[nx][ny] == 0)
			diffusion(nx, ny);
	}

	return;
}

void count() {
	int sum = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (temp[i][j] == 0)
				sum++;
		}
	}

	max = MAX(max, sum);
}

void make_wall(int i, int walls) {
	if (walls == 3) {
		copy();

		for (int w = 1; w <= non_num; w++)
			if (wall[w] == 1)
				temp[non[w - 1].x][non[w - 1].y] = 1;

		for (int d = 0; d < virus_num; d++)
			diffusion(virus[d].x, virus[d].y);
		count();
		return;
	}
	else if (i < non_num) {
		wall[i + 1] = 1;
		make_wall(i + 1, walls + 1);
		wall[i + 1] = 0;
		make_wall(i + 1, walls);
	}

	return ;
}

int main() {
	scanf("%d %d", &N, &M);

	init();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &lab[i][j]);
			if (lab[i][j] == 2) {
				virus[virus_num].x = i;
				virus[virus_num++].y = j;
			}
			else if (lab[i][j] == 0) {
				non[non_num].x = i;
				non[non_num++].y = j;
			}
		}
	}

	make_wall(0, 0);

	printf("%d", max);

	return 0;
}
