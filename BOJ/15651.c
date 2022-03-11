#include <stdio.h>

#define MAX_INT 8

int arr[MAX_INT + 1] = { 0 , };
int N, M;

int promising(int i, int count) {
	if (count <= M && i <= N)
		return 1;
	return 0;
}

void NM(int i, int count) {
	if (promising(i, count)) {
		if (count == M) {
			for (int j = 1; j < count + 1; j++)
				printf("%d ", arr[j]);
			printf("\n");
		}
		else {
			for (int i = 1; i < N + 1; i++) {
				arr[count+1] = i;
				NM(i, count+1);
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	NM(0, 0);

	return 0;
}
