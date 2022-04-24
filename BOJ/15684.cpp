#include <iostream>

using namespace std;

int N, H, M;
int ladder[31][11];
int ans = -1;

void copyLadder(int from[][11], int to[][11]) {
	for (int i = 1; i <= H; i++) for (int j = 1; j <= N - 1; j++)
		to[i][j] = from[i][j];
}

bool checkLadder(int ld[][11]) {
	for (int v = 1; v <= N - 1; v++) {
		int cur_v = v;

		for (int h = 1; h <= H; h++) {
			if (ld[h][cur_v - 1] == 1) {
				cur_v--;
			}
			else if (ld[h][cur_v] == 1) {
				cur_v++;
			}
		}

		if (v != cur_v) return false;
	}

	return true;
}

void DFS(int dpt, int ld[][11], int _h, int _v) {
	if (dpt > 3) {
		return;
	}

	if (checkLadder(ld)) {
		if (ans == -1)
			ans = dpt;
		else if (ans > dpt) ans = dpt;
		return ;
	}

	for (int h = _h; h <= _h; h++) for (int v = _v; v <= N - 1; v++) {
		if (ld[h][v] == 0) {
			if (ld[h][v + 1] == 0 && ld[h][v - 1] == 0) {
				ld[h][v] = 1;
				DFS(dpt + 1, ld, h, v);
				ld[h][v] = 0;
			}
		}
	}

	for (int h = _h + 1; h <= H; h++) for (int v = 1; v <= N - 1; v++) {
		if (ld[h][v] == 0) {
			if (ld[h][v + 1] == 0 && ld[h][v - 1] == 0) {
				ld[h][v] = 1;
				DFS(dpt + 1, ld, h, v);
				ld[h][v] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;

	int a, b;
	for (int m = 0; m < M; m++) {
		cin >> a >> b;

		ladder[a][b] = 1;
	}

	DFS(0, ladder, 1, 1);

	cout << ans << "\n";

	return 0;
}
