#include <iostream>

using namespace std;

int N, L;

int checkVerticalRoad(int map[][100], int x) {
	bool slope[100];

	for (int i = 0; i < N; i++)
		slope[i] = false;
	
	//내려가는 방향
	for (int i = 1; i < N; i++) {
		//이전보다 내려온 경우
		if (map[i][x] < map[i - 1][x]) {
			//차이가 1이상 나는 경우
			if (map[i - 1][x] - map[i][x] > 1) 
				return 0;

			//아래 방향으로 경사로 설치 가능한지 검사
			int cnt = 0;
			for (int l = i; l < i + L && l < N; l++) 
				if (map[i][x] == map[l][x] && !slope[l]) cnt++;

			//경사로 설치 가능한 경우
			if (cnt == L) 
				for (int l = i; l < i + L; l++)
					slope[l] = true;
			 else if (cnt != L) 
				return 0;
		}
	}

	//올라오는 방향
	for (int i = N - 2; i >= 0; i--) {
		if (map[i][x] < map[i + 1][x]) {
			//차이가 1이상 나는 경우
			if (map[i + 1][x] - map[i][x] > 1)
				return 0;

			//아래 방향으로 경사로 설치 가능한지 검사
			int cnt = 0;
			for (int l = i; l > i - L && l >= 0; l--)
				if (map[i][x] == map[l][x] && !slope[l]) cnt++;

			//경사로 설치 가능한 경우
			if (cnt == L) 
				for (int l = i; l > i - L; l--)
					slope[l] = true;
			else if (cnt != L)
				return 0;
		}
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	int map[100][100];
	int trans[100][100];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			trans[j][i] = map[i][j];
		}
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++) 
		ans += checkVerticalRoad(map, i) 
		+ checkVerticalRoad(trans, i);
	
	cout << ans << '\n';

	return 0;
}
