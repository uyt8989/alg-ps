#include <iostream>
#include <cstring>
#include <queue>

#define MAX_N 102
#define MAX_STR 26

typedef struct _Point {
	int x, y;
} Point;

using namespace std;

const int next_x[4] = { -1, 0, 1, 0 };
const int next_y[4] = { 0, 1, 0, -1 };

int T, h, w, ans;
char map[MAX_N][MAX_N], firstKey[MAX_STR + 1];
bool visited[MAX_N][MAX_N], key[MAX_STR];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		memset(map, 0, sizeof(map));
		memset(key, false, sizeof(key));
		memset(visited, false, sizeof(visited));
		ans = 0;

		cin >> h >> w;

		for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++)
			cin >> map[i][j];

		cin >> firstKey;
		if (firstKey[0] != '0') {
			for (int i = 0; firstKey[i] != '\0'; i++)
				key[firstKey[i] - 'a'] = true;
		}

		queue<Point> q;
		queue<Point> door[MAX_STR];

		q.push({ 0 , 0 });
		visited[0][0] = true;

		while (!q.empty()) {
			Point cur = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.x + next_x[dir], ny = cur.y + next_y[dir];
				if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;

				char c = map[nx][ny];
				if (visited[nx][ny] || c == '*') continue;

				visited[nx][ny] = true;

				if ('A' <= c && c <= 'Z') {
					if (key[c - 'A']) q.push({ nx, ny });
					else door[c - 'A'].push({ nx, ny });
				}

				else if ('a' <= c && c <= 'z') {
					q.push({ nx, ny });

					if (!key[c - 'a']) {
						key[c - 'a'] = true;

						while (!door[c - 'a'].empty()) {
							q.push(door[c - 'a'].front());
							door[c - 'a'].pop();
						}
					}
				}
				else {
					q.push({ nx, ny });
					if (c == '$') ans++;
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
