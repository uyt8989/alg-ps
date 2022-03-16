#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 11

using namespace std;

typedef struct _Tree {
	int age, x, y;
} Tree;

const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int N, M, K;
int field[MAX][MAX], A[MAX][MAX];
vector<int> trees[MAX][MAX];
queue<Tree> dead, five;

bool cmp(Tree a, Tree b) {
	return a.age < b.age;
}

void spring() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (trees[r][c].empty()) continue;

			vector<int> temp;
			int size = trees[r][c].size();

			sort(trees[r][c].begin(), trees[r][c].end());

			for (int i = 0; i < size; i++) {
				if (field[r][c] < trees[r][c][i]) {
					dead.push({ trees[r][c][i], r, c });
				}

				else {
					field[r][c] -= trees[r][c][i];
					temp.push_back(trees[r][c][i] + 1);
					if ((trees[r][c][i] + 1) % 5 == 0)
						five.push({ 0, r, c });
				}
			}

			trees[r][c] = temp;
		}
	}
}

void summer() {
	while (!dead.empty()) {
		Tree cur = dead.front(); dead.pop();

		field[cur.x][cur.y] += cur.age / 2;
	}
}

void fall() {
	while (!five.empty()) {
		Tree cur = five.front(); five.pop();

		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;

			trees[nx][ny].push_back(1);
		}
	}
}

void winter() {
	for (int r = 1; r <= N; r++) for (int c = 1; c <= N; c++)
		field[r][c] += A[r][c];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int r = 1; r <= N; r++) for (int c = 1; c <= N; c++) {
		cin >> A[r][c];
		field[r][c] = 5;
	}

	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	for (int y = 0; y < K; y++) {
		spring();
		summer();
		fall();
		winter();
	}

	int ans = 0;
	for (int r = 1; r <= N; r++) for (int c = 1; c <= N; c++) {
		ans += trees[r][c].size();
	}
	cout << ans << "\n";

	return 0;
}
