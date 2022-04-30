#include <iostream>
#include <stack>

using namespace std;

#define MAX_N 14
#define MAX_K 11
#define WHITE 0
#define RED 1
#define BLUE 2

typedef struct _TOKEN {
	int x, y, dir;
} token_t;

const int dx[] = { 0, 0, 0, -1, 1 };
const int dy[] = { 0, 1, -1, 0, 0 };

int N, K;

int color[MAX_N][MAX_N];
int board[MAX_N][MAX_N][MAX_K];
int length[MAX_N][MAX_N];
token_t token[MAX_K];

inline bool checkBound(int x, int y) {
	return 0 < x && x <= N && 0 < y && y <= N;
}

int findIdx(int x, int y, int target) {
	for (int i = 0; i < MAX_K; i++)
		if (board[x][y][i] == target) return i;
	return -1;
}

void reverseToken(int x, int y, int start) {
	stack<int> s;

	int len = length[x][y];
	for (int i = start; i < len; i++)
		s.push(board[x][y][i]);

	int idx = start;
	while (!s.empty()) {
		int temp = s.top();
		s.pop();
		board[x][y][idx++] = temp;
	}
}

bool moveToken() {
	for (int k = 1; k <= K; k++) {
		int x = token[k].x; int y = token[k].y; int dir = token[k].dir;
		int nx = x + dx[dir]; int ny = y + dy[dir];

		// 파란색이거나 영역 밖으로 움직이는 경우
		if (!checkBound(nx, ny) || color[nx][ny] == BLUE) {
			switch (dir) {
			case 1: dir = 2; break;
			case 2: dir = 1; break;
			case 3: dir = 4; break;
			case 4: dir = 3; break;
			}

			token[k].dir = dir;
			nx = x + dx[dir]; ny = y + dy[dir];

			// 방향을 바꿨는데도 여전히 파란색이거나 영역 밖인 경우
			// 움직이지 않는다
			if (!checkBound(nx, ny) || color[nx][ny] == BLUE)
				continue;
		}

		// (nx, ny)로 말을 움직인다.

		// 현재 좌표에서 움직일 말의 순서를 찾는다.
		int idx = findIdx(x, y, k);
		if (idx == -1) cout << "Index Error\n";
		
		// 현재 좌표의 말 개수와 움직일 좌표의 말 개수를 찾는다.
		int fromEnd = length[x][y];
		int toEnd = length[nx][ny];

		// 현재 좌표 : 움직일 말의 순서부터 끝까지 움직인다.
		// 움직일 좌표 : 가장 뒷 순서로 말을 추가한다.
		for (int i = idx; i < fromEnd; i++) {
			// 움직일 말의 번호
			int temp = board[x][y][i];			
			// 현재 좌표에서 지움
			board[x][y][i] = 0;
			// 새로운 좌표에 추가
			board[nx][ny][toEnd++] = temp;
			// 움직인 좌표를 반영한다
			token[temp].x = nx; token[temp].y = ny;
		}

		if (toEnd >= 4) return false;
		
		length[x][y] = idx;
		length[nx][ny] = toEnd;

		// 빨간색으로 움직인 경우
		if(color[nx][ny] == RED)
			reverseToken(nx, ny, toEnd - (fromEnd - idx));
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> N >> K;

	for (int r = 1; r <= N; r++) for (int c = 1; c <= N; c++)
		cin >> color[r][c];

	int x, y, dir;
	for (int k = 1; k <= K; k++) {
		cin >> x >> y >> dir;
		board[x][y][0] = k;
		length[x][y]++;
		token[k] = { x, y, dir };
	}
	
	bool flag = false;
	int turn;
	for (turn = 1; turn <= 1000; turn++) {
		if(!moveToken()){
			flag = true; break;
		}
	}

	cout << (flag ? turn : -1) << "\n";

	return 0;
} 
