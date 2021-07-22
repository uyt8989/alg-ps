#include <stdio.h>

#define MAX_INT 8

int include[MAX_INT + 1] = { 0 , };
int N, M;

int promising(int i, int count) {
	if (count <= M && i <= N)
		return 1;
	return 0;
}

void NM(int i, int count) {
	if (promising(i, count)) {
		if (count == M) {
			for (int j = 1; j < i + 1; j++)
				if (include[j]) printf("%d ", j);
			printf("\n");
		}
		else {
			include[i+1] = 1;
			NM(i+1, count+1);
			include[i+1] = 0;
			NM(i+1, count);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	NM(0, 0);

	return 0;
}
