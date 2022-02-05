#include <iostream>

using namespace std;

#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
#define UP 0
#define DOWN 5

int N, M, x, y, K;
int map[20][20];

//주사위 초기 상태 0
int dice[6] = { 0, };
//동 서 북 남
int next_x[4] = { 0, 0, -1, 1 };
int next_y[4] = { 1, -1, 0, 0 };

bool check_bound(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

void rollDice(int dir) {
	int temp = dice[UP];

	switch (dir) {
	case EAST:
		dice[UP] = dice[WEST];
		dice[WEST] = dice[DOWN];
		dice[DOWN] = dice[EAST];
		dice[EAST] = temp;
		break;
	case WEST:
		dice[UP] = dice[EAST];
		dice[EAST] = dice[DOWN];
		dice[DOWN] = dice[WEST];
		dice[WEST] = temp;
		break;
	case NORTH:
		dice[UP] = dice[SOUTH];
		dice[SOUTH] = dice[DOWN];
		dice[DOWN] = dice[NORTH];
		dice[NORTH] = temp;
		break;
	case SOUTH:
		dice[UP] = dice[NORTH];
		dice[NORTH] = dice[DOWN];
		dice[DOWN] = dice[SOUTH];
		dice[SOUTH] = temp;
		break;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int dir;

	for (int k = 0; k < K; k++) {
		cin >> dir;
		
 		int nx = x + next_x[dir - 1];
		int ny = y + next_y[dir - 1];

		if (check_bound(nx, ny)) {
			rollDice(dir);

			if (map[nx][ny] == 0)
				map[nx][ny] = dice[DOWN];
			else {
				dice[DOWN] = map[nx][ny];
				map[nx][ny] = 0;
			} 

			cout << dice[UP] << '\n';

			x = nx;
			y = ny;
		}
	}

	return 0;
}
