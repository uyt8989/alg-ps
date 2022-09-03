#include <iostream>
#include <string>
#include <queue>

#define MAX 1000000000

using namespace std;

typedef struct _Point {
	int x, y;
	int cost;

	bool operator<(const _Point& p) const {
		return cost > p.cost;
	}
}Point;

int N;
int field[100][100];
int min_cost[100][100];
priority_queue<Point> pq;

int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };

bool check_bound(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
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
		pq = priority_queue<Point> ();

		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				min_cost[i][j] = MAX;
		
		string str;
		for (int i = 0; i < N; i++) {
			cin >> str;

			for (int j = 0; j < N; j++) {
				field[i][j] = str[j] - '0';
			}
		}

		min_cost[0][0] = 0;
		pq.push({ 0, 0, 0 });
		
		while (!pq.empty()) {
			Point cur = pq.top(); pq.pop();

			if (cur.cost > min_cost[cur.x][cur.y])
				continue;

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.x + next_x[dir];
				int ny = cur.y + next_y[dir];

				if (check_bound(nx, ny)){
					if (min_cost[nx][ny] > min_cost[cur.x][cur.y] + field[nx][ny]) {
						pq.push({ nx, ny, min_cost[cur.x][cur.y] + field[nx][ny] });
						min_cost[nx][ny] = min_cost[cur.x][cur.y] + field[nx][ny];
					}
				}
			}


			
		}

		cout << '#' << test_case << ' ' << min_cost[N-1][N-1] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
