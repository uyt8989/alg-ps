#include <stdio.h>

#define MAX_V 101
#define INF 987654321

int V, E;
int adj[MAX_V][MAX_V];

int MIN(int a, int b) {
	if (a < b) return a;
	return b;
}

void initAdj() {
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			adj[i][j] = INF;
			if (i == j) adj[i][j] = 0;
		}
	}
}

void floyd() {
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				adj[i][j] = MIN(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main() {
	int v1, v2, cost;

	scanf("%d", &V);
	scanf("%d", &E);

	initAdj();

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &v1, &v2, &cost);
		if (cost < adj[v1][v2])
			adj[v1][v2] = cost;
	}

	floyd();

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (adj[i][j] == INF)
				adj[i][j] = 0;
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}

	return 0;
}
