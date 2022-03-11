#include <stdio.h>

int N;
int cnt = -1;
long long int queue[100000];
int front = 0, rear = 0;

void enqueue(long long int a) {
	queue[rear++] = a;
	cnt++;
}

long long int dequeue() {
	if (front < rear) return queue[front++];
	return -1;
}

int main() {
	scanf("%d", &N);

	if (N > 1022) {
		printf("-1");
		return 0;
	}

	for (int i = 0; i <= 9; i++) {
		enqueue(i);
		if (cnt == N) {
			printf("%lld\n", (long long)i);
			return 0;
		}
	}
	while (1) {
		long long int num = dequeue();
		long long int mod = num % 10;

		for (int i = 0; i < mod; i++) {
			enqueue(num * 10 + i);
			if (cnt == N) {
				printf("%lld\n", num * 10 + i);
				break;
			}
		}
		if (cnt == N) break;
	}
	return 0;
}
