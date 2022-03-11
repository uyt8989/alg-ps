#include <stdio.h>
#include <string.h>

char str1[1001];
char str2[1001];
int dp[1001][1001] = { 0, };

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	scanf("%s", str1);
	scanf("%s", str2);

	for (int i = 1; i <= strlen(str1); i++) {
		for (int j = 1; j <= strlen(str2); j++) {
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	printf("%d\n", dp[strlen(str1)][strlen(str2)]);

	return 0;
}
