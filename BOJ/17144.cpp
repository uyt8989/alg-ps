#include <iostream>
#include <cstring>

using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int R, C, T;
int room[51][51];
int up_cleaner, down_cleaner;

void diffuseDust() {
	int temp[51][51];
	memset(temp, 0, sizeof(temp));
	temp[up_cleaner][1] = -1;
	temp[down_cleaner][1] = -1;

	for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++) {
		//5 미만이면 어차피 확산안되는듯
		if (room[r][c] <= 0) continue;

		int cnt = 0;
		int spread = room[r][c] / 5;

		for (int dir = 0; dir < 4; dir++) {
			int nr = r + dx[dir], nc = c + dy[dir];
			if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
			if (room[nr][nc] == -1) continue;

			temp[nr][nc] += spread;
			cnt++;
		}

		temp[r][c] += room[r][c] - spread * cnt;
	}

	memcpy(room, temp, sizeof(temp));
}

void activateCleaner() {
	//위쪽
	for (int r = up_cleaner - 1; r > 1; r--)
		room[r][1] = room[r - 1][1];
	for (int c = 1; c < C; c++)
		room[1][c] = room[1][c + 1];
	for (int r = 1; r < up_cleaner; r++)
		room[r][C] = room[r + 1][C];
	for (int c = C; c > 2; c--)
		room[up_cleaner][c] = room[up_cleaner][c - 1];
	room[up_cleaner][2] = 0;

	//아래쪽
	for (int r = down_cleaner + 1; r < R; r++)
		room[r][1] = room[r + 1][1];
	for (int c = 1; c < C; c++)
		room[R][c] = room[R][c + 1];
	for (int r = R; r > down_cleaner; r--)
		room[r][C] = room[r - 1][C];
	for (int c = C; c > 2; c--)
		room[down_cleaner][c] = room[down_cleaner][c - 1];
	room[down_cleaner][2] = 0;
}

int sumDust() {
	int ret = 0;
	for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++)
		ret += room[r][c];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;

	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cin >> room[r][c];
			if (room[r][c] == -1) {
				if (!up_cleaner) up_cleaner = r;
				else down_cleaner = r;
			}
		}
	}

	while (T--) {
		diffuseDust();
		activateCleaner();
	}

	cout << sumDust() + 2 << "\n";

	return 0;
}
