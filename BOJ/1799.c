#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Bishop {
	int x;
	int y;
	int play;
}Bishop;

int N;
int board[11][11];
Bishop white_bishop[101];
Bishop black_bishop[101];
int white_avail = 1;
int black_avail = 1;
int white_max = 0;
int black_max = 0;

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int white_promising(int i, int x, int y) {
	bool flag = true;

	if (white_bishop[i].play == true) {
		for (int j = 1; j < i; j++) {
			if (white_bishop[j].play == true) {
				if (abs(white_bishop[j].x - x) == abs(white_bishop[j].y - y)) {
					flag = false;
					break;
				}
			}
		}
	}

	return flag;
}

int black_promising(int i, int x, int y) {
	bool flag = true;

	if (black_bishop[i].play == true) {
		for (int j = 1; j < i; j++) {
			if (black_bishop[j].play == true) {
				if (abs(black_bishop[j].x - x) == abs(black_bishop[j].y - y)) {
					flag = false;
					break;
				}
			}
		}
	}

	return flag;
}

void white_dfs(int i, int n) {
	if (white_promising(i, white_bishop[i].x, white_bishop[i].y)) {
		if (i == white_avail - 1) {
			white_max = MAX(white_max, n);
			return;
		}

		white_bishop[i + 1].play = true;
		white_dfs(i + 1, n + 1);
		white_bishop[i + 1].play = false;
		white_dfs(i + 1, n);
	}
	return;
}

void black_dfs(int i, int n) {
	if (black_promising(i, black_bishop[i].x, black_bishop[i].y)) {
		if (i == black_avail - 1) {
			black_max = MAX(black_max, n);
			return;
		}

		black_bishop[i + 1].play = true;
		black_dfs(i + 1, n + 1);
		black_bishop[i + 1].play = false;
		black_dfs(i + 1, n);
	}
	return;
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 1 && (i + j) % 2 == 0) {
				white_bishop[white_avail].x = i;
				white_bishop[white_avail].y = j;
				white_bishop[white_avail++].play = false;
			}
			else if (board[i][j] == 1 && (i + j) % 2 == 1) {
				black_bishop[black_avail].x = i;
				black_bishop[black_avail].y = j;
				black_bishop[black_avail++].play = false;
			}
		}
	}
	
	white_dfs(0, 0);
	black_dfs(0, 0);

	printf("%d\n", white_max + black_max);
}
