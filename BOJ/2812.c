#include <stdio.h>

int N, K;
int num[500000];
int stack[500000];
int top = 0;

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
		scanf("%1d", &num[i]);

	for (int i = 0; i < N; i++) {
		while (K > 0 && top > 0 && stack[top - 1] < num[i]) {
			top--;
			K--;
		}
		stack[top++] = num[i];
	}

	top -= K;

	for (int i = 0; i < top; i++)
		printf("%d", stack[i]);

	return 0;
}
