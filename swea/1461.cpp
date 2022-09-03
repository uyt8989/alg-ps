#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 12

int x_next[4] = { -1, 0, 1, 0 };
int y_next[4] = { 0, 1, 0 ,-1 };

int N;
int processor[MAX][MAX];
pair<int, int> core[MAX];
pair<int, int> answer;

bool in_boundary(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

int check(int x, int y, int dir) {
	int cost = 0;

	x += x_next[dir];
	y += y_next[dir];

	while (in_boundary(x, y)) {
		if (processor[x][y] == 1) {
			cost = -1;
			break;
		}

		x += x_next[dir];
		y += y_next[dir];
		cost++;
	} 

	return cost;
}

void update(int x, int y, int dir, int value) {
	x += x_next[dir];
	y += y_next[dir];
	
	while (in_boundary(x, y)) {
		processor[x][y] = value;

		x += x_next[dir];
		y += y_next[dir];
	}
}

void DFS(int cur, int cnt, int cost){
	int x, y, res;
	if (N - cur + cnt < answer.first)
		return;

	if (cur == N) {
		if (cnt > answer.first) {
			answer.first = cnt;
			answer.second = cost;
		}
		else if (cnt == answer.first)
			answer.second = min(answer.second, cost);
		return;
	}

	for (int d = 0; d < 4; d++) {
		x = core[cur].first;
		y = core[cur].second;

		res = check(x, y, d);
		if (res != -1) {
			update(x, y, d, 1);
			DFS(cur + 1, cnt + 1, cost + res);
			update(x, y, d, 0);
		}
		else {
			DFS(cur + 1, cnt, cost);
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(processor, 0, sizeof(processor));
		answer.first = 0;
		answer.second = 200;

		cin >> N;

		int n = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> processor[i][j];
				if (processor[i][j]) {
					core[n].first = i;
					core[n++].second = j;
				}
			}
		}

		DFS(0, 0, 0);

		cout << "#" << test_case << ' ' << answer.second << '\n';
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}