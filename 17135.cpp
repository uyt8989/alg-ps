#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <tuple>
#include <vector>

using namespace std;

int N, M, D;
int field[15][15];
bool shooted[15][15];
bool position[15];
vector<tuple<int, int, int>> temp(15);
int answer;

int get_distance(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}

void simulation() {
	int killed = 0;

	memset(shooted, false, sizeof(shooted));

	for (int t = N; t > 0; t--) {
		temp.clear();
		temp.resize(15);
		for (int a = 0; a < M; a++) {
			if (position[a] == true) {
				int min_dist = INT_MAX;
				int min_i = 0; int min_j = 0;

				for (int j = 0; j < M; j++){
					for (int i = 0; i < t; i++) {
						if (field[i][j] == 1) {
							if (!shooted[i][j] && min_dist > get_distance(t, a, i, j)) {
								min_dist = get_distance(t, a, i, j);
								min_i = i; min_j = j;
							}
						}
					}
				}

				get<0>(temp[a]) = min_dist;
				get<1>(temp[a]) = min_i; get<2>(temp[a]) = min_j;
			}
		}

		for (int a = 0; a < M; a++) {
			if (position[a] == true) {
				if (get<0>(temp[a]) <= D && !shooted[get<1>(temp[a])][get<2>(temp[a])]){
					killed++;
					shooted[get<1>(temp[a])][get<2>(temp[a])] = true;
				}
			}
		}

	}

	answer = max(answer, killed);
}

void arrange(int i, int archers) {
	if (archers == 3){
		simulation();
	}

	else if(i < M){
		position[i] = true;
		arrange(i + 1, archers + 1);
		position[i] = false;
		arrange(i + 1, archers);
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &D);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &field[i][j]);

	arrange(0, 0);

	printf("%d\n", answer);

	return 0;
}
