#include <stdio.h>

#define INF 987654321

int N, M, X;
int from, to, w;
int adj[1001][1001];
int comeback[1001];
int visit[1001];

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int choose(int dist[]) {
	int min = INF;
	int min_pos = -1;

	for (int i = 1; i <= N; i++) {
		if (!visit[i] && dist[i] < min) {
			min = dist[i];
			min_pos = i;
		}
	}
	return min_pos;
}

void dijkstra(int start, int *dist) {
	int u;

	dist[start] = 0;
	
	for (int i = 1; i <= N; i++) {
		u = choose(dist);
		visit[u] = 1;

		for (int v = 1; v <= N; v++) {
			if (!visit[v] && dist[v] > dist[u] + adj[u][v])
				dist[v] = dist[u] + adj[u][v];
		}
	}

	return;
}

int main() {
	scanf("%d %d %d", &N, &M, &X);
	
	for (int i = 1; i <= N; i++) {
		comeback[i] = INF;
		visit[i] = 0;
		for (int j = 1; j <= N; j++)
			adj[i][j] = INF;
	}

	
	
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &from, &to, &w);
		adj[from][to] = w;
	}

	dijkstra(X, comeback);

	int max = 0;
	for (int i = 1; i <= N; i++) {
		int dist[1001];
		for (int j = 1; j <= N; j++) {
			dist[j] = INF;
			visit[j] = 0;
		}
		dijkstra(i, dist);

		//printf("%d\n", dist[X]);
		max = MAX(max, dist[X] + comeback[i]);
	}
	printf("%d\n", max);

	return 0;
}
