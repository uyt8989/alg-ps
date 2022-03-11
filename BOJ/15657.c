#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 8

int arr[MAX_INT + 1] = { 0 , };
int input[MAX_INT + 1] = { 0 , };
int N, M;

int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return -1;

	if (*(int*)a > *(int*)b)
		return 1;

	return 0;
}

int promising(int count) {
	if (count <= M)
		return 1;
	return 0;
}

void NM(int count) {
	if (promising(count)) {
		if (count == M) {
			for (int j = 1; j < count + 1; j++)
				printf("%d ", arr[j]);
			printf("\n");
		}
		else {
			for (int j = 1; j <= N; j++) {
				if (arr[count] <= input[j]) {
					arr[count + 1] = input[j];
					NM(count + 1);
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i < N + 1; i++)
		scanf("%d", &input[i]);

	qsort(input, N+1, sizeof(int), compare);

	NM(0);

	return 0;
}
