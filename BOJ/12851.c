#include <stdio.h>

#define INF 987654321

int N, K;
int min = 0 ;
int queue[10000001][2] = { 0 , };
int visited[1000001] = { 0, };
int front = 0, rear = 0;
int path = 0;

void enqueue(int x, int i) {
	queue[rear][0] = x;
	queue[rear][1] = i;
	rear++;
}

int dequeue(int *i) {
	*i = queue[front][1];
	return queue[front++][0];
}

int boundary(int x) {
	if (x >= 0 && x <= 100000)
		return 1;
	return 0;
}

void BFS() {
	int x, i;

	visited[N] = 1;
	enqueue(N, 0);

	while (front < rear){
		x = dequeue(&i);
		
		visited[x] = 1;
		if (x == K && min && i == min)
			path++;


		if (x == K && !min)
			min = i;
			path++;

		if (boundary(x - 1))
			if(!visited[x-1])
				enqueue(x - 1, i + 1);

		if (boundary(x + 1))
			if(!visited[x+1])
				enqueue(x + 1, i + 1);

		if (boundary(2 * x))
			if (!visited[2 * x])
				enqueue(2 * x, i + 1);
	}
}

int main() {
	scanf("%d %d", &N, &K);

	BFS();

	printf("%d\n", min);

	printf("%d\n", path);
	return 0;
}
