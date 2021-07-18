#include <stdio.h>

int N;

int calc(int d) {
	if (d == 1)
		return 1;
	else if (d == 2)
		return 2;
	else if (d == 3)
		return 4;

	if(d > 3)
		return calc(d - 1) + calc(d - 2) + calc(d - 3);
	
}

int main() {
	int d;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &d);
		printf("%d\n", calc(d));
	}

	return 0;
}