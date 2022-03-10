#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

typedef struct _Shark {
	bool alive;
	int x, y;
	int s, d, z;
} Shark;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

int R, C, M;
int board[101][101], finished[101][101];
Shark shark[100 * 100 + 1];
int ans;

int getShark(int pos) {
	int ret = 0;
	for (int i = 1; i <= R; i++) {
		if (board[i][pos] != 0) {
			ret = shark[board[i][pos]].z;
			shark[board[i][pos]].alive = false;
			board[i][pos] = 0;
			return ret;
		}
	}
	return ret;
}

void moveShark() {
	memset(finished, 0, sizeof(finished));

	for (int i = 1; i <= M; i++) { 
		Shark cur = shark[i];
		if (cur.alive == false) continue;
		
		int nx = cur.x; int ny = cur.y;

		//수직 이동
		if (cur.d < 2) {
			int mod = (R - 1) * 2;
			cur.s = cur.s % mod;

			for (int t = 0; t < cur.s; t++) {
				nx += dx[cur.d]; ny += dy[cur.d];

				if (nx < 1) {
					cur.d = 1; nx += 2;
				}
				else if (nx > R) {
					cur.d = 0; nx -= 2;
				}
			}
		}
		//수평 이동
		else {
			int mod = (C - 1) * 2;
			cur.s = cur.s % mod;

			for (int t = 0; t < cur.s; t++) {
				nx += dx[cur.d]; ny += dy[cur.d];

				if (ny < 1) {
					cur.d = 2; ny += 2;
				}
				else if (ny > C) {
					cur.d = 3; ny -= 2;
				}
			}
		}

		shark[i].x = nx; shark[i].y = ny; shark[i].d = cur.d;

		//더 큰 상어만 생존
		if (finished[nx][ny] != 0) {
			if (shark[i].z > shark[finished[nx][ny]].z) {
				shark[finished[nx][ny]].alive = false;
				finished[nx][ny] = i;
			}
			else shark[i].alive = false;
			
		}
		else {
			finished[nx][ny] = i;
		}
	}

	memcpy(board, finished, sizeof(board));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> M;

	memset(board, 0, sizeof(board));

	int r, c, s, d, z;
	for (int i = 1; i <= M; i++) {
		cin >> r >> c >> s >> d >> z;
		shark[i] = { true, r, c , s, d - 1, z };
		board[r][c] = i;
	}

	for (int i = 1; i <= C; i++) {
		ans += getShark(i);
		moveShark();
	}

	cout << ans << "\n";

	return 0;
}
