#include <stdio.h>

#define MAX_V 10
#define INF 987654321

int selected[MAX_V];
int dist[MAX_V];
int adj[MAX_V][MAX_V];

int V, E, start, end;

void initAdj() {
	for (int i = 0; i < V; i++) {
		dist[i] = INF;
		selected[i] = INF;
		for (int j = 0; j < V; j++) {
			adj[i][j] = INF;
			if (i == j) adj[i][j] = 0;
		}
	}
}

void prim() {
	int min, v;

	dist[start] = 0;

	for (int i = 0; i < V; i++) {
		min = INF;
		for (int j = 0; j < V; j++) {
			if (selected[j] == 0 && min > dist[j]) {
				min = dist[j];
				v = j;
			}
			selected[v] = 1;
		}
		for (int j = 0; j < V; j++) {
			if (adj[v][j] != INF) {
				if (selected[v] == 0 && adj[v][j] < dist[j])
					dist[j] = adj[v][j];
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

	scanf("%d %d", &start, &end);

	prim();

	return 0;
}
