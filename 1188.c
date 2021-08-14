#include <stdio.h>

int N, M;

int cut(int s, int p) {
	if (s == p)
		return 0;

	else if (s > p)
		return cut(s - p, p);

	else if (s < p)
		return cut(s, p - s) + s;
}

int main() {
	int cutting = 0;

	scanf("%d %d", &N, &M);
	
	printf("%d\n", cut(N, M));

	return 0;
}
