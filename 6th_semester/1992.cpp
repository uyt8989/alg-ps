#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

int N;
int data[64][64];

void subsize(int x, int y, int size) {
	int half = size / 2;
	std::set<int> numset;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			numset.insert(data[i][j]);
		}
	}

	if (numset.size() == 1)
		printf("%d", data[x][y]);

	else {
		printf("(");
		subsize(x, y, half);
		subsize(x, y + half, half);
		subsize(x + half, y, half);
		subsize(x + half, y + half, half);
		printf(")");
	}
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &data[i][j]);

	subsize(0, 0, N);

	return 0;
}
