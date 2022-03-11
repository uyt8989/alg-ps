#include <stdio.h>

typedef struct Tower {
	int h;
	int idx;
}Tower;

int N;
int tower[500001];
int reception[500001] = { 0 , };
Tower stack[5000000];
int top = -1;

void push(int h, int idx) {
	top++;
	stack[top].h = h;
	stack[top].idx = idx;
}

Tower pop() {
	return stack[top--];
}

int main() {
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++)
		scanf("%d", &tower[i]);


	push(tower[N], N);
	for (int i = N - 1; i >= 1; i--) {
		if (stack[top].h < tower[i]) {
			Tower temp;
			while (stack[top].h < tower[i] && top > -1) {
				temp = pop();
				reception[temp.idx] = i;
			}
		}
		push(tower[i], i);
	}

	for (int i = 1; i <= N; i++)
		printf("%d ", reception[i]);

	return 0;
}
