#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
	int x, y;

	Node(int i, int j): x(i), y(j) {}
};

int N;
int plain;
char field[300][300];
int mines[300][300];
bool check[300][300];
queue<Node> q;

int x_next[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int y_next[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void init() {
	N = 0;
	plain = 0; 
	memset(field, 0, sizeof(field));
	memset(mines, 0, sizeof(mines));
	memset(check, false, sizeof(check));
}

bool in_boundary(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

int count_mine(int x, int y) {
	int cnt = 0;
	int nx, ny;

	for (int dir = 0; dir < 8; dir++) {
		nx = x + x_next[dir];
		ny = y + y_next[dir];
		if (in_boundary(nx, ny)) {
			if (field[nx][ny] == '*')
				cnt++;
		}
	}

	return cnt;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> field[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] == '.') {
					mines[i][j] = count_mine(i, j);
				}
				else {
					mines[i][j] = -1;
				}
			}
		}

		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mines[i][j] == 0 && check[i][j] != true) {
					ans++;
					
					q.push({ i, j });
					while (!q.empty()) {
						Node cur = q.front(); q.pop();
						if (check[cur.x][cur.y] != true) {
							check[cur.x][cur.y] = true;

							int nx, ny;
							for (int dir = 0; dir < 8; dir++) {
								nx = cur.x + x_next[dir];
								ny = cur.y + y_next[dir];
								if (in_boundary(nx, ny)) {
									if (mines[nx][ny] == 0)
										q.push({ nx, ny });
									else check[nx][ny] = true;
								}
							}
						}
					}
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] != '*' && check[i][j] != true)
					ans++;
			}
		}

		cout << "#" << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.

}
