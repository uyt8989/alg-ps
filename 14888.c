#include <stdio.h>

#define INF 1987654321

int N;
int max = -1987654321;
int min = 1987654321;
int A[101] = { 0, };
int selected[101] = { 0, };
//0: plus, 1: minus, 2: mult, 3:div
int operand[4] = { 0, };


int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int MIN(int a, int b) {
	if (a < b) return a;
	return b;
}

void calc(int i, int plus, int minus, int mult, int div) {
	int temp;
	if (i == N - 1) {
		
		temp = A[1];
		for (int i = 1; i <= N - 1; i++) {
			switch (selected[i]) {
			case 0: temp += A[i + 1]; break;
			case 1: temp -= A[i + 1]; break;
			case 2: temp *= A[i + 1]; break;
			case 3: temp /= A[i + 1]; break;
			}
		}
		//printf("%d\n", temp);
		max = MAX(max, temp);
		min = MIN(min, temp);

		return;
	}

	if (plus > 0) {
		selected[i + 1] = 0;
		calc(i + 1, plus - 1, minus, mult, div);
	}
	if (minus > 0) {
		selected[i + 1] = 1;
		calc(i + 1, plus, minus - 1, mult, div);
	}
	if (mult > 0) {
		selected[i + 1] = 2;
		calc(i + 1, plus, minus, mult - 1, div);
	}
	if (div > 0) {
		selected[i + 1] = 3;
		calc(i + 1, plus, minus, mult, div - 1);
	}
	return;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &operand[i]);

	calc(0, operand[0], operand[1], operand[2], operand[3]);

	printf("%d\n%d\n", max, min);
		
	return 0;
}
