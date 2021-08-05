#include <stdio.h>

#define INF 987654321

int N, K;
int min;
int queue[100001] = { 0 , };
int visited[100001] = { 0, };
int front = 0, rear = 0;

int MIN(int a, int b) {
	if (a < b) return a;
	return b;
}

void enqueue(int x) {
	queue[rear++] = x;
}

int dequeue() {
	return queue[front++];
}

int boundary(int x) {
	if (x >= 0 && x <= 100000)
		return 1;
	return 0;
}

void BFS() {
	int x;
	visited[N] = 1;
	enqueue(N);

	while (front < rear){
		x = dequeue();

		if (x == K) break;

		if (boundary(2 * x) && !visited[2 * x]) {
			visited[2 * x] = visited[x];
			enqueue(2 * x);
		}

		if (boundary(x- 1) && !visited[x - 1]) {
			visited[x - 1] = visited[x] + 1;
			enqueue(x - 1);
		}
		if (boundary(x + 1) && !visited[x + 1]) {
			visited[x + 1] = visited[x] + 1;
			enqueue(x + 1);
		}
		

	}

}

int main() {
	scanf("%d %d", &N, &K);

	BFS();

	printf("%d\n", visited[K] - 1);
	return 0;
}
