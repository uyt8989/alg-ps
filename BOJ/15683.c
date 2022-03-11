#include <stdio.h>

#define INF 1987654321;

int N, M;
int office[10][10];
int temp[10][10];
int cctv[9][3];
int cctv_num = 1;
int cctv_dir[9];
int min_space = INF;

int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };

void init() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			office[i][j] = 6;
}

void copy() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			temp[i][j] = office[i][j];
}

void cctv1(int cctv_number, int dir) {
	int x, y;

	x = cctv[cctv_number][0];
	y = cctv[cctv_number][1];

	while (1) {
		x = x + next_x[dir];
		y = y + next_y[dir];
		if (temp[x][y] == 6) break;
		if(temp[x][y] == 0) temp[x][y] = 7;
	}
}

void get_empty_space() {
	int space = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			if (temp[i][j] == 0)
				space++; 
	}
	if (space < min_space) min_space = space;
}

void empty_space(int i){
	if (i == cctv_num - 1) {
		copy(); 

		for (int k = 1; k < cctv_num; k++) {
			if (cctv[k][2] == 1)
				cctv1(k, cctv_dir[k]);
			else if (cctv[k][2] == 2) {
				cctv1(k, cctv_dir[k]);
				cctv1(k, (cctv_dir[k] + 2) % 4);
			}
			else if (cctv[k][2] == 3) {
				cctv1(k, cctv_dir[k]);
				cctv1(k, (cctv_dir[k] + 1) % 4);
			}
			else if (cctv[k][2] == 4) {
				cctv1(k, cctv_dir[k]);
				cctv1(k, (cctv_dir[k] + 1) % 4);
				cctv1(k, (cctv_dir[k] + 3) % 4);
			}
			else if (cctv[k][2] == 5) {
				for (int j = 0; j < 4; j++)
					cctv1(k, j);
			}
		}
		
		get_empty_space();

		return;
	}
	
	if (cctv[i+1][2] == 5) {
		cctv_dir[i + 1] = 0;
		empty_space(i + 1);
	}

	else {
		cctv_dir[i + 1] = 0;
		empty_space(i + 1);

		cctv_dir[i + 1] = 1;
		empty_space(i + 1);

		cctv_dir[i + 1] = 2;
		empty_space(i + 1);

		cctv_dir[i + 1] = 3;
		empty_space(i + 1);
	}
	return;
}


int main() {
	
	init();

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &office[i][j]);

			if (office[i][j] >= 1 && office[i][j] <= 5) {
				cctv[cctv_num][2] = office[i][j];
				cctv[cctv_num][0] = i; 
				cctv[cctv_num++][1] = j;
			}
		}
	}

	empty_space(0);

	printf("%d\n", min_space);
	return 0;
}
