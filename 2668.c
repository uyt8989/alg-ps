#include <stdio.h>

int N;
int table[101];
int visit[101] = { 0, };
int ans[101] = { 0, };
int num = 0;
int stack[100];
int top = -1;

void push(int a) {
	stack[++top] = a;
}

int pop() {
	return stack[top--];
}

void init_visit() {
	for (int i = 1; i <= N; i++)
		visit[i] = ans[i];
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[i]);
		if (table[i] == i) {
			ans[i] = 1;
			num++;
		}
	}

	for (int i = 1; i <= N; i++) {
		top = -1;
		init_visit();
		
		int next = table[i];
		while (1) {
			visit[next] = 1;
			push(next);
			next = table[next];
			if (visit[next] == 1) break;
			if (next == i) {
				ans[i] = 1;
				num++;
				while (top > -1) {
					ans[pop()] = 1;
					num++;
				}
			}
		}
	}

	printf("%d\n", num);
	for (int i = 1; i <= N; i++)
		if (ans[i] == 1) printf("%d\n", i);

	return 0;
}
