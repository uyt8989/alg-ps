#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 98765432

int N, M;
int a, b, c;
int adj[1001][1001];
int selected[1001] = { 0, };
int dist[1001] = { 0 , };

int MIN(int a, int b) {
	if (a < b) return a;
	return b;
}

int getMinVertex() {
	int min_dist = INF;
	int min_v = 0;

	for (int v = 1; v <= N; v++) {
		if (!selected[v] && dist[v] < min_dist) {
			min_dist = dist[v];
			min_v = v;
		}
	}

	return min_v;
}

void prim() {
	dist[1] = 0;

	for (int i = 1; i <= N ; i++) {
		int u = getMinVertex();
		
		if (dist[u] == INF) return ;
		
		selected[u] = 1; 
		for (int v = 1; v <= N; v++) {
			if (adj[u][v] != INF) {
				if (!selected[v] && adj[u][v] < dist[v])
					dist[v] = adj[u][v];
			}
		}
	}

	return ;
}

int main() {
	memset(adj, INF, sizeof(adj));
	
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = adj[b][a] = c;
	}

	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	prim();

	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans += dist[i];

	printf("%d\n", ans);

	return 0;
}
