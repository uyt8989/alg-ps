#include <stdio.h>

#define MAX_V 10
#define MIN(a, b) a < b ? a : b
#define INF 987654321

int V, E;
int adj[MAX_V][MAX_V];

void initAdj() {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			adj[i][j] = INF;
			if (i == j) adj[i][j] = 0;
		}
	}
}

void floyd() {
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				adj[i][j] = MIN(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main() {
	int v1, v2, cost;

	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &v1, &v2, &cost);
		adj[v1][v2] = adj[v2][v1] = cost;
	}

	floyd();

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			printf("%d~%d : %d\n", i, j, adj[i][j]);
		}
	}

	return 0;
}
