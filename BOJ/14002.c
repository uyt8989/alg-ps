#include <stdio.h>

int N;
int arr[1001] = { 0, };
int dp[1001] = { 0, };
int path[1001] = { 0, };
int stack[1001];
int top = -1;

void push(int a) {
	stack[++top] = a;
}

int pop() {
	return stack[top--];
}

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}


	int max = 1;
	int max_idx = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					path[i] = j;
				}
			}
		}
		if (max < dp[i]) {
			max = dp[i];
			max_idx = i;
		}
	}
	printf("%d\n", max);

	int now = max_idx;
	while (now != 0) {
		push(arr[now]);
		now = path[now];
	}

	while (top > -1)
		printf("%d ", pop());

	return 0;
}
