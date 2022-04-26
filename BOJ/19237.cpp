#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N 20
#define MAX_M MAX_N * MAX_N + 1
#define MAX_k 1000
#define NULL_VALUE 50000 

const int dx[] = { 0, -1, 1, 0, 0 };
const int dy[] = { 0, 0, 0, -1, 1 };

typedef struct _SHARK {
	int x, y, dir;
	int p[5][5];
	bool live;
} shark_t;

typedef struct _SMELL {
	int s_num, turn;
} smell_t;

int N, M, k;
int grid[MAX_N][MAX_N];
shark_t shark[MAX_M];
smell_t smell[MAX_N][MAX_N];
int remain, ans;

inline bool checkBound(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void input() {
	cin >> N >> M >> k;

	remain = M;

	for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) {
		cin >> grid[r][c];

		if (grid[r][c] != 0) {
			shark[grid[r][c]].x = r;
			shark[grid[r][c]].y = c;
			shark[grid[r][c]].live = true;
		}

		smell[r][c].s_num = NULL_VALUE;
		smell[r][c].turn = NULL_VALUE;
	}

	for (int m = 1; m <= M; m++) {
		cin >> shark[m].dir;
	}

	for (int m = 1; m <= M; m++) for (int dir = 1; dir <= 4; dir++) {
		for (int pri = 1; pri <= 4; pri++)
			cin >> shark[m].p[dir][pri];
	}

	ans = -1;
}

void makeSmell(int turn) {
	for (int m = 1; m <= M; m++) {
		if (!shark[m].live) continue;

		int x = shark[m].x;
		int y = shark[m].y;

		smell[x][y].s_num = m;
		smell[x][y].turn = turn;
	}
}

void moveShark() {
	memset(grid, 0, sizeof(grid));
	for (int m = 1; m <= M; m++) {
		if (!shark[m].live) continue;

		int cur_x = shark[m].x;
		int cur_y = shark[m].y;
		int cur_dir = shark[m].dir;
		int flag = false;
		int ndir, nx, ny;

		// 빈 공간
		for (int d = 1; d <= 4; d++) {
			ndir = shark[m].p[cur_dir][d];
			nx = cur_x + dx[ndir];
			ny = cur_y + dy[ndir];

			if (!checkBound(nx, ny)) continue;

			// 빈 공간 찾음
			if (smell[nx][ny].s_num == NULL_VALUE) {
				flag = true;
				break;
			}
		}

		// 빈 공간이 없다면 자신의 냄새가 나는 곳
		if (!flag) {
			for (int d = 1; d <= 4; d++) {
				ndir = shark[m].p[cur_dir][d];
				nx = cur_x + dx[ndir];
				ny = cur_y + dy[ndir];

				if (!checkBound(nx, ny)) continue;

				// 자신의 냄새가 나는 곳 찾음
				if (smell[nx][ny].s_num == m) {
					break;
				}
			}
		}

		// 이동한 곳에 이미 다른 상어가 있다면 번호가 작은 애는 죽음
		if (grid[nx][ny] != 0) {
			shark[m].live = false;
			remain--;
		}
		else {
			grid[nx][ny] = m;
			shark[m].x = nx;
			shark[m].y = ny;
			shark[m].dir = ndir;
		}
	}
}

void removeSmell(int turn) {
	for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) {
		if (turn - smell[r][c].turn >= k) {
			smell[r][c].s_num = NULL_VALUE;
			smell[r][c].turn = NULL_VALUE;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	makeSmell(0);

	for (int turn = 1; turn <= 1000; turn++) {
		moveShark();

		if (remain == 1) {
			ans = turn;
			break;
		}

		makeSmell(turn);
		removeSmell(turn);
	}

	cout << ans << "\n";

	return 0;
}
