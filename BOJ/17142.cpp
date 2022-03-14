#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef struct _Points {
	int x, y;
} Points;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int N, M;
int lab[50][50]; int visited[50][50];
vector<Points> startingPoints;
int targetBlankNum, curBlankNum, minTimes = 50 * 50 + 1, curTimes;
int selectedPoints;

void BFS() {
	memset(visited, -1, sizeof(visited));
	curTimes = 0; curBlankNum = 0;
	queue<Points> q;

	//시작점으로 고른 M개의 좌표를 큐에 넣어둠
	for (int i = 0; i < startingPoints.size(); i++) {
		if (selectedPoints & (1 << i)) {
			q.push({ startingPoints[i].x, startingPoints[i].y });
			visited[startingPoints[i].x][startingPoints[i].y] = 0;
		}
	}

	while (!q.empty()) {
		Points cur = q.front(); q.pop();
	
		if (curBlankNum == targetBlankNum) break;

		//현재 시간이 이미 구한 최단 시간보다 큰 경우엔 pruning
		if (curTimes > minTimes) return;

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir], ny = cur.y + dy[dir];

			//좌표가 범위 안에 들어오는지 확인
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			//아직 방문하지 않았으면서 벽도 아닌 좌표라면 방문
			if (visited[nx][ny] == -1 && lab[nx][ny] != 1) {
				if (lab[nx][ny] == 0) curBlankNum++;
				visited[nx][ny] = visited[cur.x][cur.y] + 1;
				if (visited[nx][ny] > curTimes) curTimes = visited[nx][ny];
				
				q.push({ nx, ny });
			}
		}
	}

	//모든 빈 공간을 감염시키고 최단 시간에 감염됐다면 정답 갱신
	if (curBlankNum == targetBlankNum && minTimes > curTimes) {
		minTimes = curTimes;
	}
}

void selectStartingPoints(int idx, int cnt) {
	if (cnt == M) {
		BFS();
		return;
	}
	if (idx == startingPoints.size()) return;

	selectedPoints = selectedPoints | (1 << idx);
	selectStartingPoints(idx + 1, cnt + 1);
	selectedPoints = selectedPoints & (~(1 << idx));
	selectStartingPoints(idx + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0) targetBlankNum++;
			else if (lab[i][j] == 2) startingPoints.push_back({ i, j });
		}
	}
	
	selectStartingPoints(0, 0);

	cout << (minTimes == 2501 ? -1 : minTimes) << "\n";

	return 0;
}
