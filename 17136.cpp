#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <limits.h>
#include <algorithm>

using namespace std;

int paper[10][10];
bool visit[10][10];
int pcount[6];
int answer;

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) 
		for (int j = y; j < y + n; j++)
			if (!paper[i][j]) return false;
	return true;
}

void glue(int x, int y, int n, int flag) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			paper[i][j] = flag;
}

void sol(int x, int y, int glued) {
	for (; y < 10; y++)
		if (paper[x][y] == 1) goto pass;

	for (x = x + 1; x < 10; x++)
		for (y = 0; y < 10; y++)
			if (paper[x][y] == 1) goto pass;

	answer = min(answer, glued);
	return;

pass:
	if (answer <= glued)
		return;

	for (int s = 5; s > 0; s--) {
		if (x + s > 10 || y + s > 10 || pcount[s] >= 5)
			continue;

		if (check(x, y, s)) {
			glue(x, y, s, 0);
			pcount[s]++;

			sol(x, y, glued + 1);

			glue(x, y, s, 1);
			pcount[s]--;
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			scanf("%d", &paper[i][j]);

	memset(pcount, 0, sizeof(pcount));

	answer = INT_MAX;

	sol(0, 0, 0);
	 
	printf("%d\n", answer == INT_MAX ? -1 : answer);

	return 0; 
}
