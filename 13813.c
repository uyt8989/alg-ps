#include <stdio.h>

#define INF 987654321

int N, K;
int min;
int queue[100001] = { 0 , };
int visited[100001] = { 0, };
int before[1000001] = { 0 , };
int front = 0, rear = 0;
int stack[100001] = { 0 , };
int top = 0;

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
	before[N] = INF;
	enqueue(N);

	while (front < rear) {
		x = dequeue();

		if (x == K) break;

		if (boundary(x - 1) && !visited[x - 1]) {
			visited[x - 1] = visited[x] + 1;
			before[x - 1] = x;
			enqueue(x - 1);
		}
		if (boundary(x + 1) && !visited[x + 1]) {
			visited[x + 1] = visited[x] + 1;
			before[x + 1] = x;
			enqueue(x + 1);
		}
		if (boundary(2 * x) && !visited[2 * x]) {
			visited[2 * x] = visited[x] + 1;
			before[2 * x] = x;
			enqueue(2 * x);
		}

	}

}

void push(int x) {
	stack[top++] = x;
}

int pop() {
	if (top == 0) return -1;
	return stack[--top];
}

void find_path() {
	int b;
	
	push(K);

	b = before[K];
	while (b != INF) {
		push(b);
		b = before[b];
	}

	printf("\n");
	for(int i = 0; i < visited[K]; i++){
		printf("%d ", pop());
	}
}

int main() {
	scanf("%d %d", &N, &K);

	BFS();
	
	printf("%d\n", visited[K] - 1);
	
	find_path();

	return 0;
}
