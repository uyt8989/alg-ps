#include <stdio.h>

int money, company;
int mat[21][301] = { 0, };
int dp[21][301] = { 0, };
int path[21][301] = { 0, };
int stack[30];
int top = -1;

void push(int a) {
	stack[++top] = a;
}

int pop() {
	return stack[top--];
}

int main() {
	int trash;

	scanf("%d %d", &money, &company);

	for (int i = 1; i <= money; i++) {
		scanf("%d", &trash);
		for (int j = 1; j <= company; j++)
			scanf("%d", &mat[j][i]);
	}

	for (int i = 1; i <= company; i++) { //기업 순서대로
		for (int cost = 1; cost <= money; cost++) { //투자 금액
			for (int j = 0; j <= cost; j++) { //현재 기업에 j원 투자
				if (dp[i - 1][cost - j] + mat[i][j] > dp[i][cost]) {
					dp[i][cost] = dp[i - 1][cost - j] + mat[i][j];
					path[i][cost] = j;
				}
			}
		}
	}
	
	printf("%d\n", dp[company][money]);


	int c = company;
	int i = money;
	while (c > 0) {
		int now = path[c][i];
		push(now);
		c--;
		i -= now;
	}

	while (top > -1)
		printf("%d ", pop());

	return 0;
}
