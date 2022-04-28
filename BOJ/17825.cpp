#include <iostream>

using namespace std;

typedef struct _BOARD {
	int next[6];
} board_t;

board_t board[33];
int score[33];
int player[5], number[11];
int cur[33];
int ans = -1;

void makeBoard() {
	for (int i = 0; i <= 20; i++) for (int j = 1; j <= 5; j++)
			board[i].next[j] = i + j;
	
	board[5].next[1] = 21; board[5].next[2] = 22; board[5].next[3] = 23; 
	board[5].next[4] = 29; board[5].next[5] = 30;

	board[10].next[1] = 24; board[10].next[2] = 25; board[10].next[3] = 29; 
	board[10].next[4] = 30; board[10].next[5] = 31;

	for (int i = 16; i <= 20; i++) for (int j = 0; j <= i - 16 ; j++) 
			board[i].next[5 - j] = 32;
	
	int x;

	x = 21;
	board[x].next[1] = 22; board[x].next[2] = 23; board[x].next[3] = 29;
	board[x].next[4] = 30; board[x].next[5] = 31;

	x++;
	board[x].next[1] = 23; board[x].next[2] = 29; board[x].next[3] = 30;
	board[x].next[4] = 31; board[x].next[5] = 20;

	x++;
	board[x].next[1] = 29; board[x].next[2] = 30; board[x].next[3] = 31;
	board[x].next[4] = 20; board[x].next[5] = 32;

	x++;
	board[x].next[1] = 25; board[x].next[2] = 29; board[x].next[3] = 30;
	board[x].next[4] = 31; board[x].next[5] = 20;

	x++;
	board[x].next[1] = 29; board[x].next[2] = 30; board[x].next[3] = 31;
	board[x].next[4] = 20; board[x].next[5] = 32;

	x++;
	board[x].next[1] = 27; board[x].next[2] = 28; board[x].next[3] = 29;
	board[x].next[4] = 30; board[x].next[5] = 31;

	x++;
	board[x].next[1] = 28; board[x].next[2] = 29; board[x].next[3] = 30;
	board[x].next[4] = 31; board[x].next[5] = 20;

	x++;
	board[x].next[1] = 29; board[x].next[2] = 30; board[x].next[3] = 31;
	board[x].next[4] = 20; board[x].next[5] = 32;

	x++;
	board[x].next[1] = 30; board[x].next[2] = 31; board[x].next[3] = 20;
	board[x].next[4] = 32; board[x].next[5] = 32;

	x++;
	board[x].next[1] = 31; board[x].next[2] = 20; board[x].next[3] = 32;
	board[x].next[4] = 32; board[x].next[5] = 32;

	x++;
	board[x].next[1] = 20; board[x].next[2] = 32; board[x].next[3] = 32;
	board[x].next[4] = 32; board[x].next[5] = 32;

	for (int i = 1; i <= 20; i++)
		score[i] = 2 * i;

	for (int i = 1; i <= 3; i++)
		score[20 + i] = 10 + 3 * i;

	score[24] = 22;
	score[25] = 24;

	for (int i = 1; i <= 3; i++)
		score[25 + i] = 29 - i;

	for (int i = 1; i <= 3; i++)
		score[28 + i] = 20 + 5 * i;
}

void DFS(int dpt, int tot_score) {
	if (dpt > 10) {
		if (ans < tot_score)
			ans = tot_score;
		return;
	}

	int num = number[dpt];
	for (int i = 1; i <= 4; i++) {
		int cur_place = player[i];
		int next_place = board[cur_place].next[num];

		// 움직일 곳에 이미 말이 있거나 해당 말이 이미 도착점인 경우 제외
		if ((next_place != 32 && cur[next_place] > 0) || player[i] == 32) continue;

		cur[cur_place] = 0;
		cur[next_place] = 1;
		player[i] = next_place;
		DFS(dpt + 1, tot_score + score[next_place]);
		cur[cur_place] = 1;
		cur[next_place] = 0;
		player[i] = cur_place;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < 11; i++) 
		cin >> number[i];
	
	for (int i = 1; i <= 4; i++)
		player[i] = 0;
	
	makeBoard();

	DFS(0, 0);

	cout << ans << "\n";


	return 0;
}
