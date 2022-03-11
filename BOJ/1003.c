#include <stdio.h>

int res[40][1];
int T;

int main() {
	int d;

	scanf("%d", &T);

	res[0][0] = 1; res[0][1] = 0;
	res[1][0] = 0; res[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		res[i][0] = res[i - 1][0] + res[i - 2][0];
		res[i][1] = res[i - 1][1] + res[i - 2][1];
	}

	for (int i = 0; i < T; i++) {
		scanf("%d", &d);
		printf("%d %d\n", res[d][0], res[d][1]);
	}

	return 0;
}