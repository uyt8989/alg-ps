#include <iostream>
#include <algorithm>
#include <string.h>

#define MAX 1000

using namespace std;

bool input[10][10]; bool state[10][10]; bool check[10][10];
int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };
int ans = MAX;

bool checkBound(int x, int y) {
	return x >= 0 && x < 10 && y >= 0 && y < 10;
}

void Click(int x, int y) {
	state[x][y] = !state[x][y];
	
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + next_x[dir];
		int ny = y + next_y[dir];

		if (checkBound(nx, ny)) {
			state[nx][ny] = !state[nx][ny];
		}
	}
}

int simulation() {
	int cnt = 0;

	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (state[i - 1][j]) {
				cnt++;
				Click(i, j);
			}
		}
	}
	
	if(!memcmp(state, check, sizeof(state))) 
		return cnt;
	
	return MAX;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char c;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> c;
			if (c == 'O') 
				input[i][j] = true;
		}
	}


	for (int s = 0; s < (1 << 10); s++) {
		memcpy(state, input, sizeof(input));
	
		int cnt = 0;

		for (int i = 0; i < 10; i++) {
			if (s & (1 << i)) {
				cnt++;
				Click(0, i);
			}
		}
		cnt += simulation();

		ans = min(ans, cnt);
	}

	if (ans >= MAX) cout << "-1\n";
	else cout << ans << '\n';

	return 0;
}
