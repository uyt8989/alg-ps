#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL 2

using namespace std;

int N;
int house[17][17];
int answer;

bool check(int x, int y, int next_status) {
	switch (next_status) {
	case HORIZONTAL:
		if (house[x][y + 1]) return false;
		break;
	case VERTICAL:
		if (house[x + 1][y]) return false;
		break;
	case DIAGONAL:
		if (house[x][y + 1] || house[x + 1][y] || house[x + 1][y + 1])
			return false;
		break;
	}
	return true;
}

void dfs(int x1, int y1, int x2, int y2, int status) {
	if (x2 == N - 1 && y2 == N - 1)
		answer++;

	else {

		switch (status) {
		case HORIZONTAL:
			if (check(x2, y2, HORIZONTAL)) dfs(x2, y2, x2, y2 + 1, HORIZONTAL);
			if (check(x2, y2, DIAGONAL)) dfs(x2, y2, x2 + 1, y2 + 1, DIAGONAL);
			break;
		case VERTICAL:
			if (check(x2, y2, VERTICAL)) dfs(x2, y2, x2 + 1, y2, VERTICAL);
			if (check(x2, y2, DIAGONAL)) dfs(x2, y2, x2 + 1, y2 + 1, DIAGONAL);
			break;
		case DIAGONAL :
			if (check(x2, y2, HORIZONTAL)) dfs(x2, y2, x2, y2 + 1, HORIZONTAL);
			if (check(x2, y2, VERTICAL)) dfs(x2, y2, x2 + 1, y2, VERTICAL);
			if (check(x2, y2, DIAGONAL)) dfs(x2, y2, x2 + 1, y2 + 1, DIAGONAL);
			break;
		}
	}

	return;
}


int main() {
	scanf("%d", &N);

	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 17; j++)
			house[i][j] = 1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &house[i][j]);

	dfs(0, 0, 0, 1, HORIZONTAL);

	printf("%d\n", answer);

	return 0;
}
