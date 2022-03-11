#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

int i;
int order[100001];
int power[100001][5][5];


int move(int from, int to) {
	if (from == to) return 1;
	else if (from == 0) return 2;

	switch (from) {
	case 1: return to == 3 ? 4 : 3;
	case 2: return to == 4 ? 4 : 3;
	case 3: return to == 1 ? 4 : 3;
	case 4: return to == 2 ? 4 : 3;
	}
}

int DDR(int n, int left, int right) {
	if (n == i - 1) return 0;

	if (power[n][left][right] != 0) return power[n][left][right];

	return power[n][left][right] = std::min(move(left, order[n]) + DDR(n + 1, order[n], right),
		move(right, order[n]) + DDR(n + 1, left, order[n]) );
}

int main() {
	while (1) {
		scanf("%d", &order[i++]);
		if (order[i - 1] == 0) break;
	}

	printf("%d", DDR(0, 0, 0));

	return 0;
}
