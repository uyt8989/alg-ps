#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
char map[51][51];

queue<pair<int, int>> land;

int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };

int max_ans = -1;

void bfs(int start_x, int start_y) {
	queue<pair<int, int>> q;
	int visit[51][51] = { 0, };

	q.push(make_pair(start_x, start_y));
	visit[start_x][start_y] = 1;

	int x, y, d;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + next_x[dir];
			int ny = y + next_y[dir];

			if (nx > 0 && nx <= n && ny > 0 && ny <= m && visit[nx][ny] == 0 && map[nx][ny] == 'L') {
				visit[nx][ny] = visit[x][y] + 1;
				q.push(make_pair(nx, ny));
				if (max_ans < visit[nx][ny]) max_ans = visit[nx][ny];
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L')
				land.push(make_pair(i, j));
		}
	}

	while (!land.empty()) {
		bfs(land.front().first, land.front().second);
		land.pop();
	}

	cout << max_ans - 1 << endl;

	return 0;
}
