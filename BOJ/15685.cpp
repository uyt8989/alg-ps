#include <iostream>
#include <cstring>

using namespace std;

const int dx[] = { 0, -1, 0, 1 };
const int dy[] = { 1, 0, -1, 0 };

int N;
int grid[101][101];
int temp[101][101];
int temp2[101][101];
int new_x, new_y;

void rotateGrid(int src[][101], int res[][101], int x, int y) {
	for (int i = 0; i <= 100; i++) for (int j = 0; j <= 100; j++) {
		if (src[i][j] == 1) {
			res[x + (j - y)][y + (x - i)] = 1;
		}
	}
}

void copyGrid(int from[][101], int to[][101]) {
	for (int i = 0; i <= 100; i++) for (int j = 0; j <= 100; j++)
		to[i][j] = to[i][j] | from[i][j];
}

void rotateCenter(int* cx, int* cy, int x, int y) {
	int temp_cx = *cx;
	int temp_cy = *cy;

	*cx = temp_cx + (y - temp_cy);
	*cy = temp_cy + (temp_cx - x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	int x, y, d, g;
	for (int n = 0; n < N; n++) {
		cin >> y >> x >> d >> g;

		memset(temp, 0, sizeof(temp));

		int cx = x + dx[d];
		int cy = y + dy[d];

		temp[x][y] = 1;
		temp[cx][cy] = 1;

		for (int _g = 0; _g < g; _g++) {
			memset(temp2, 0, sizeof(temp2));
			rotateGrid(temp, temp2, cx, cy);
			copyGrid(temp2, temp);
			rotateCenter(&cx, &cy, x, y);
		}
		copyGrid(temp, grid);
	}
	
	int ans = 0;
	for (int i = 0; i < 100; i++) for (int j = 0; j < 100; j++) {
		if (grid[i][j] && grid[i + 1][j]
			&& grid[i][j + 1] && grid[i + 1][j + 1])
			ans++;
	}

	cout << ans << "\n";

	return 0;
}
