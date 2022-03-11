#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <limits.h>

int N;
char exep[20];
int answer;

int calc(int a, int b, char op) {
	int res = a;

	switch (op) {
	case '+': res += b; break;
	case '-': res -= b; break;
	case '*': res *= b; break;
	}

	return res;
}

void sol(int i, int sum) {
	if (i >= N - 2) {
		sum = calc(sum, exep[i + 1] - '0', exep[i]);
		answer = std::max(answer, sum);
	}
	else if (i == -1) {
		//괄호
		int temp = calc(exep[i + 1] - '0', exep[i + 3] - '0', exep[i + 2]);
		sol(i + 4, calc(sum, temp, '+'));
		//괄호x
		sol(i + 2, calc(sum, exep[i + 1] - '0', '+'));
	}

	else {
		//괄호
		int temp = calc(exep[i + 1] - '0', exep[i + 3] - '0', exep[i + 2]);
		sol(i + 4, calc(sum, temp, exep[i]));
		//괄호x
		sol(i + 2, calc(sum, exep[i + 1] - '0', exep[i]));
	}
}

int main() {
	scanf("%d", &N);

	scanf("%s", exep);
	
	answer = INT_MIN;

	if (N > 1)
		sol(-1, 0);
	else
		answer = exep[0] - '0';

	printf("%d\n", answer);

	return 0;
}
