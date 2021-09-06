#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
int group_num = 0;
int include[500000];
int map[1001][1001];
int group[1001][1001];
vector<pair<int, int>> wall;
vector<pair<int, int>> not_wall;
vector<int> group_size;

int next_x[] = { -1, 0, 1, 0 };
int next_y[] = { 0, 1, 0, -1 };

int check(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= M;
}

int get_zero(int x, int y) {
	int cnt = 1;

	group[x][y] = group_num;

	for (int d = 0; d < 4; d++) {
		int nx = x + next_x[d];
		int ny = y + next_y[d];
		if (check(nx, ny) && map[nx][ny] == 0 && group[nx][ny] == -1)
			cnt += get_zero(nx, ny);
	}

	return cnt;
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
			group[i][j] = -1;
			if (map[i][j] == 0) not_wall.push_back(make_pair(i, j));
			else wall.push_back(make_pair(i, j));
		}
	}

	while (!not_wall.empty()) {
		int i = not_wall.back().first;
		int j = not_wall.back().second;
		not_wall.pop_back();

		if (group[i][j] == -1) {
			int cnt = get_zero(i, j);
			group_size.push_back(cnt);
			group_num++;
		}
	}

	while (!wall.empty()) {
		int x = wall.back().first;
		int y = wall.back().second;
		wall.pop_back();

		set<int> include;

		for (int d = 0; d < 4; d++) {
			int nx = x + next_x[d];
			int ny = y + next_y[d];

			if (check(nx, ny) && group[nx][ny] > -1 && !include.count(group[nx][ny])) {
				map[x][y] += group_size[group[nx][ny]];
				include.insert(group[nx][ny]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			printf("%d", map[i][j] % 10);
		printf("\n");
	}
	
	return 0;
}
