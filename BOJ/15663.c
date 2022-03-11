#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 8

int arr[MAX_INT + 1] = { 0 , };
int input[MAX_INT + 1] = { 0 , };
int visited[MAX_INT+1] = { 0 , };
int N, M;

int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return -1;

	if (*(int*)a > *(int*)b)
		return 1;

	return 0;
}

int promising(int i, int count) {
	if (count <= M)
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
			int visited1[10001] = { 0, };
			for (int j = 1; j <= N; j++) {
				if (!visited1[input[j]] && !visited[j]) {
					arr[count + 1] = input[j];
					visited[j] = 1;
					visited1[input[j]] = 1;
					NM(i + 1, count + 1);
					visited[j] = 0;
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++)
		scanf("%d", &input[i]);

	qsort(input, N + 1, sizeof(int), compare);

	NM(0, 0);

	return 0;
}
