#include <iostream>
#include <queue>

#define WALL 1
#define GOAL 2

typedef struct _Ball {
	int rx, ry, bx, by;
	int cnt;
} Ball ;

using namespace std;

int N, M;
int board[10][10];
pair<int, int> _red, _blue;
int next_x[4] = { 1, 0, -1, 0 };
int next_y[4] = { 0, 1, 0, -1 };
int ans = -1;
bool visited[10][10][10][10];

void moveBall(int& x, int& y, int d) {
	while (1) {
		x += next_x[d]; y += next_y[d];
		if (board[x][y] == WALL) {
			x -= next_x[d]; y -= next_y[d];
			break;
		}
		else if (board[x][y] == GOAL)
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	char c;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		cin >> c;

		board[i][j] = 0;
		if (c == '#') board[i][j] = WALL;
		else if (c == 'O') board[i][j] = GOAL;
		else if (c == 'R') {
			_red.first = i; _red.second = j;
		}
		else if (c == 'B') {
			_blue.first = i; _blue.second = j;
		}

	}

	queue<Ball> q;
	q.push({ _red.first, _red.second, _blue.first, _blue.second, 0 });
	visited[_red.first][_red.second][_blue.first][_blue.second] = true;

	while (!q.empty()) {
		Ball cur = q.front(); q.pop();

		if (cur.cnt > 10) break;
		if (board[cur.rx][cur.ry] == GOAL) {
			ans = cur.cnt; 
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			int rx = cur.rx; int ry = cur.ry;
			int bx = cur.bx; int by = cur.by;

			//빨간 공
			moveBall(rx, ry, dir); 
			//파란 공
			moveBall(bx, by, dir);

			//파란 공이 구멍에 들어간 경우 이 방향은 실패임
			if (board[bx][by] == GOAL) continue;

			//두 공이 같은 위치에 있는 경우
			if (rx == bx && ry == by) {
				switch (dir) {
				case 0:
					cur.rx < cur.bx ? rx-- : bx--; break;
				case 2:
					cur.rx < cur.bx ? bx++ : rx++; break;
				case 1:
					cur.ry < cur.by ? ry-- : by--; break;
				case 3:
					cur.ry < cur.by ? by++ : ry++; break;
				}
			}

			//아직 이 상태를 해본 적이 없는 경우
			if (!visited[rx][ry][bx][by]) {
				q.push({ rx, ry, bx, by, cur.cnt + 1 });
				visited[rx][ry][bx][by] = true;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
