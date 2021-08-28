#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define my 1
#define your 0
#define win true
#define lose false

int dp[2][1001];

int func(int turn, int remain) {
    if (remain == 0) {
        if (turn == my)
            return dp[turn][remain] = lose;
        if (turn == your)
            return dp[turn][remain] = win;
    }

    if (remain < 0) {
        if (turn == my)
            return 1;
        if (turn == your)
            return 0;
    }

    if (dp[turn][remain] != -1)
        return dp[turn][remain];

    if (turn == my)
        dp[my][remain] =
        func(turn ^ 1, remain - 1) | func(turn ^ 1, remain - 3);

    if (turn == your)
        dp[your][remain] =
        func(turn ^ 1, remain - 1) & func(turn ^ 1, remain - 3);

    return dp[turn][remain];
}

int main() {
	int N;
	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));

    if (func(1, N) == win)
        puts("SK");
    else
        puts("CY");

	return 0;
}
