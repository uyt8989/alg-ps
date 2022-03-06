#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct _Point {
	int x, y;
} Point;

int T, N, visited;
Point p[20];
double ans;

void getStart(int cur, int cnt) {
	if (cur > N) return;

	if (cnt == N / 2) {
		Point vec = { 0 , 0 };

		for (int i = 0; i < N; i++) {
			if (visited & (1 << i)) {
				vec.x -= p[i].x; vec.y -= p[i].y;
			}
			else {
				vec.x += p[i].x; vec.y += p[i].y;
			}
		}
	
		ans = min(ans, sqrt((double)vec.x * vec.x + (double)vec.y * vec.y));

		return;
	}


	visited = visited | (1 << cur);
	getStart(cur + 1, cnt + 1);
	visited = visited & (~(1 << cur));
	getStart(cur + 1, cnt);

	return;
	
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
			scanf("%d %d", &p[i].x, &p[i].y);

		visited = 0;
		ans = 1e9 + 7;

		getStart(0, 0);

		printf("%.6lf\n", ans);
	}

	return 0;
}
