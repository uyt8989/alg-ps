#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_N 21
#define MAX_M MAX_N * MAX_N
#define INF 987654321

typedef struct _PERSON {
	int sx, sy, dx, dy;
} person_t;

typedef struct _POINT {
	int x, y, d;
} point_t;

const int next_x[] = { -1, 0, 0, 1 };
const int next_y[] = { 0, -1, 1, 0 };

int N, M, fuel, car_x, car_y;
int map[MAX_N][MAX_N];
person_t person[MAX_M];

int getDistance(int sx, int sy, int dx, int dy) {	
	queue<point_t> q;
	bool visit[MAX_N][MAX_N];

	memset(visit, false, sizeof(visit));

	q.push({ sx, sy, 0});
	visit[sx][sy] = true;

	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cur_dist = q.front().d;
		q.pop();
		
		if (cur_x == dx && cur_y == dy)
			return cur_dist;

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur_x + next_x[dir];
			int ny = cur_y + next_y[dir];

			// 유효한 좌표인지 검사
			if (0 < nx && nx <= N && 0 < ny && ny <= N) {
				// 벽이거나 이미 방문했다면 방문하지 않음
				if (map[nx][ny] == -1 || visit[nx][ny]) continue;

				q.push({ nx, ny, cur_dist + 1 });
				visit[nx][ny] = true;
			}
		}
	}

	return INF;
}

int getNearestPassenger(int sx, int sy, int *dist) {
	queue<point_t> q;
	bool visit[MAX_N][MAX_N];
	int p_num = -1;
	int min_dist = INF;

	memset(visit, false, sizeof(visit));

	q.push({ sx, sy, 0 });
	visit[sx][sy] = true;

	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cur_dist = q.front().d;
		q.pop();

		// 아직 택시를 탑승하지 않은 승객이 있는 좌표
		if (map[cur_x][cur_y] > 0) {
			if (min_dist > cur_dist) {
				p_num = map[cur_x][cur_y];
				min_dist = cur_dist;
			}

			else if (min_dist == cur_dist) {
				int min_x = person[p_num].sx;
				int min_y = person[p_num].sy;

				// 행이 작은 승객부터
				if (min_x > cur_x) {
					p_num = map[cur_x][cur_y];
				}

				// 행도 같다면 열이 작은 승객부터
				else if (min_x == cur_x && min_y > cur_y) {
					p_num = map[cur_x][cur_y];
				}
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur_x + next_x[dir];
			int ny = cur_y + next_y[dir];

			// 유효한 좌표인지 검사
			if (0 < nx && nx <= N && 0 < ny && ny <= N) {
				// 벽이거나 이미 방문했다면 방문하지 않음
				if (map[nx][ny] == -1 || visit[nx][ny]) continue;

				q.push({ nx, ny, cur_dist + 1 });
				visit[nx][ny] = true;
			}
		}
	}

	*dist = min_dist;

	return p_num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> fuel;

	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		cin >> map[i][j];
		if (map[i][j] == 1) map[i][j] = -1;
	}

	cin >> car_x >> car_y;
	
	int sx, sy, dx, dy;

	for (int i = 1; i <= M; i++) {
		cin >> sx >> sy >> dx >> dy;
		map[sx][sy] = i;
		person[i] = { sx, sy, dx, dy};
	}

	bool flag = true;

	for(int i = 1; i <= M; i++) {
		int c2s_dist, s2e_dist;
		int p_num = getNearestPassenger(car_x, car_y, &c2s_dist);
		
		// 태울 수 있는 승객이 없는 경우
		if (p_num == -1) {
			flag = false;
			break;
		}

		sx = person[p_num].sx; sy = person[p_num].sy;
		dx = person[p_num].dx; dy = person[p_num].dy;

		// 승객의 시작점과 도착점 사이의 거리
		s2e_dist = getDistance(sx, sy, dx, dy);
		
		fuel = fuel - c2s_dist - s2e_dist;
		
		// 택시 운행에 필요한 연료가 부족한 경우
		if (fuel < 0) { 
			flag = false;
			break;
		}

		// 승객의 도착점으로 택시의 좌표 변경
		car_x = person[p_num].dx; car_y = person[p_num].dy;
		// 지도에서 승객 삭제
		map[person[p_num].sx][person[p_num].sy] = 0;
		// 연료 충전
		fuel = fuel + s2e_dist * 2;
	}

	if (!flag) 
		fuel = -1;
	cout << fuel << "\n";

	return 0;
}
