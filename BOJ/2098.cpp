#include <iostream>
#include <cstring>

#define INF 987654321

int N;
int W[16][16];
int D[16][1 << 16];

int min(int a, int b) {
	return a < b ? a : b;
}

int TSP(int cur, int visited) {
	int& ret = D[cur][visited];

	if (ret != -1) return ret;

	if (visited == (1 << N) - 1) {
		if (W[cur][0] == 0) return INF;
		else return W[cur][0];
	}

	ret = INF;

	for (int i = 0; i < N; i++) {
		if (visited & (1 << i) || W[cur][i] == 0) continue;
		ret = min(ret, TSP(i, visited | 1 << i) + W[cur][i]);
	}

	return ret;
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			std::cin >> W[i][j];
	
	memset(D, -1, sizeof(D));

	std::cout << TSP(0, 0b0000000000000001);

	return 0;
}
