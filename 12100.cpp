#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int N, ans;

struct Board {
	int board[20][20];

	void rotateBoard() {
		int temp[20][20];

		memset(temp, 0, sizeof(temp));

		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
			temp[i][j] = board[N - 1 - j][i];

		memcpy(board, temp, sizeof(board));
	}

	void moveBoard() {

		queue<int> q;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] != 0) q.push(board[i][j]);
				board[i][j] = 0;
			}

			int j = 0;

			while (!q.empty()) {
				int cur = q.front(); q.pop();
				if (board[i][j] == 0) board[i][j] = cur;
				else if (board[i][j] == cur) board[i][j++] *= 2;
				else board[i][++j] = cur;
			}
		}
	}

	void maxValue() {
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
			if (ans < board[i][j]) ans = board[i][j];
	}
};

void DFS(Board b, int cnt) {
	if (cnt == 5) {
		b.maxValue();
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		Board nb = b;
		//보드 이동
		nb.moveBoard();
		//다음번 보드 이동
		DFS(nb, cnt + 1);
		//보드 돌려서 방향 바꿈
		b.rotateBoard();
	}
}

Board b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		cin >> b.board[i][j];

	DFS(b, 0);

	cout << ans << "\n";

	return 0;
}
