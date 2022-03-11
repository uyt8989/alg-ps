#include <stdio.h>

#define MAX_INT 8

int arr[MAX_INT + 1] = { 0 , };
int visited[MAX_INT + 1] = { 0, };
int N, M;

int promising(int i, int count) {
	if (count <= M && i <= N)
		return 1;
	return 0;
}

void NM(int i, int count) {
	if (promising(i, count)) {
		if (count == M) {
			for (int j = 1; j <= M; j++)
				printf("%d ", arr[j]);
			printf("\n");
		}
		else {
			for(int j = 1; j < N + 1; j++)
				if (!visited[j]) {
					visited[j] = 1;
					arr[count + 1] = j;
					NM(i + 1, count + 1);
					visited[j] = 0;
				}

		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	NM(0, 0);

	return 0;
}
