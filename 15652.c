#include <stdio.h>

#define MAX_INT 8

int arr[MAX_INT + 1] = { 0 , };
int N, M;

int promising(int count) {
	if (count <= M)
		return 1;
	return 0;
}

void NM(int count) {
	if (promising(count)) {
		if (count == M) {
			for (int j = 1; j < count+ 1; j++)
				printf("%d ", arr[j]);
			printf("\n");
		}
		else {
			for (int j = 1; j < N + 1; j++) {
				if (arr[count] <= j) {
					arr[count + 1] = j;
					NM(count + 1, j);
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	NM(0, 0);

	return 0;
}
