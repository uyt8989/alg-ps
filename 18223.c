#include <stdio.h>

#define INF 1987654321

int V, E, P;
int adj[5001][5001];
int visit[5001] = { 0, };
int dist[5001];

void init() {
	for (int i = 1; i < 5001; i++) {
		dist[i] = INF;
		visit[i] = 0;
		for (int j = 1; j < 5001; j++) {
			adj[i][j] = INF;
			if (i == j) adj[i][j] = 0;
		}
	}
}

int choose() {
	int min = INF;
	int min_pos = -1;
	for (int i = 1; i <= V; i++) {
		if (dist[i] < min && !visit[i]) {
			min = dist[i];
			min_pos = i;
		}
	}
	return min_pos;
}

void dijkstra(int start) {
	int v = start;
	int u, w;
	for (int i = 1; i <= V; i++) {
		visit[i] = 0;
		dist[i] = adj[v][i];
	}
	visit[v] = 1;
	dist[v] = 0;

	for (int i = 1; i < V - 1; i++) {
		u = choose();
		visit[u] = 1;
		for (w = 1; w <= V; w++)
			if (!visit[w])
				if (dist[u] + adj[u][w] < dist[w])
					dist[w] = dist[u] + adj[u][w];
	}
}

int main() {
	int from, to, w;
	int masan, gunwoo;

	init();

	scanf("%d %d %d", &V, &E, &P);
	for (int i = 1; i <= E; i++) {
		scanf("%d %d %d", &from, &to, &w);
		adj[from][to] = w;
		adj[to][from] = w;
	}

	dijkstra(1);
	masan = dist[V];
	gunwoo = dist[P];
	
	dijkstra(P);
	gunwoo += dist[V];

	if (masan < gunwoo)
		printf("GOOD BYE\n");
	else
		printf("SAVE HIM\n");
	
	return 0;
}
