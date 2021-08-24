#include <stdio.h>

int D, K;
int dp[3] = { 0 , };

void dduck(int i) {
	if (i == 1)
		dp[1]++;
	else if (i == 2)
		dp[2]++;
	else if (i > 2) {
		dduck(i - 1);
		dduck(i - 2);
	}
	
	return;
}

int main() {
	scanf("%d %d", &D, &K);

	dduck(D);

	for (int i = 1; i <= K; i++) {
		if ((K - dp[1] * i) % dp[2] == 0) {
			printf("%d\n%d\n", i, (K - dp[1] * i) / dp[2]);
			break;
		}
	}

	return 0;
}
