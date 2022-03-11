#include <stdio.h>

#define INF 1987654321

int N, M;
int adj[1001][1001];
int visit[1001] = { 0, };
int dist[1001];
int start, end;

void init() {
	for (int i = 1; i < 1001; i++) {
		dist[i] = INF;
		for (int j = 1; j < 1001; j++) {
			adj[i][j] = INF;
			if (i == j) adj[i][j] = 0;
		}
	}
}

int choose() {
	int min = INF;
	int min_pos = -1;
	for (int i = 1; i <= N; i++) {
		if (dist[i] < min && !visit[i]) {
			min = dist[i];
			min_pos = i;
		}
	}
	return min_pos;
}

void dijkstra() {
	int v = start;
	int u, w;
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
		dist[i] = adj[v][i];
	}
	visit[v] = 1;
	dist[v] = 0;

	for (int i = 1; i < N - 1; i++) {
		u = choose();
		visit[u] = 1;
		for (w = 1; w <= N; w++)
			if (!visit[w])
				if (dist[u] + adj[u][w] < dist[w])
					dist[w] = dist[u] + adj[u][w];
	}
}


int main() {
	int from, to, w;

	init();

	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &w);
		if(w < adj[from][to])
			adj[from][to] = w;
	}


	scanf("%d %d", &start, &end);

	dijkstra();

	printf("%d\n", dist[end]);

	return 0;
}
