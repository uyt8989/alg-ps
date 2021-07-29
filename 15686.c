#include <stdio.h>
#include <stdlib.h>

#define INF 987654321;

int N, M;
int mat[51][51];
int house_count = 0;
int house[101][2];
int chicken_count = 0;
int chicken[14][2];
int include[14] = { 0, };
int result = INF;

int MIN(int a, int b) {
	if (a < b) return a;
	return b;
}

int distance(int i1, int j1, int i2, int j2) {
	return abs(i1 - i2) + abs(j1 - j2);
}

void search(int i, int count) {
	if (i == chicken_count && count == M) {
		int min_sum = 0;
		for (int k = 1; k <= house_count; k++) {
			int d = INF;
			for (int l = 1; l <= chicken_count; l++) {
				if (include[l])
					d = MIN(d, distance(house[k][0], house[k][1], chicken[l][0], chicken[l][1]));
			}
			min_sum += d;
		}
		result = MIN(result, min_sum);
	}

	if (i == chicken_count)
		return;

	include[i+1] = 0;
	search(i + 1, count);
	include[i+1] = 1;
	search(i + 1, count + 1);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &mat[i][j]);
			if (mat[i][j] == 1) {
				house_count++;
				house[house_count][0] = i; house[house_count][1] = j;
				
			}
			if (mat[i][j] == 2) {
				chicken_count++;
				chicken[chicken_count][0] = i; chicken[chicken_count][1] = j;
			}
		}
	}

	search(0, 0);

	printf("%d\n", result);

	return 0;
}
