#include <iostream>

using namespace std;

const int inf = 987654321;

int N, M, R, ans;
int map[101][101];
int items[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++) {
		cin >> items[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = inf;
		}
		map[i][i] = 0;
	}

	int s, e, l;
	for (int i = 0; i < R; i++) {
		cin >> s >> e >> l;
		if (map[s][e] <= l) continue;

		map[s][e] = l;
		map[e][s] = l;
	}

	//Floyd
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	
	for (int s = 1; s <= N; s++) {
		int temp = 0;
		for (int e = 1; e <= N; e++) {
			if (map[s][e] <= M) temp += items[e];
		}
		if (temp > ans) ans = temp;
	}

	cout << ans << "\n";

	return 0;
}
