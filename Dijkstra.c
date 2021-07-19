#include <stdio.h>

#define MAX_V 100
#define INF 987654321

int adj[MAX_V][MAX_V];
int visit[MAX_V] = { 0, };
int dist[MAX_V];
int N, start, end;

void init(){
	for (int i = 0; i < MAX_V; i++) {
		dist[i] = INF;
		for (int j = 0; j < MAX_V; j++) {
			adj[i][j] = INF;
			if (i == j) adj[i][j] = 0;
		}
	}
}

void dijkstra() {
	int min, v;

	dist[start] = 0;

	for (int i = 0; i < N; i++) {
		min = INF;
		for (int j = 0; j < N; j++) {
			if (visit[j] == 0 && min > dist[j]) {
				min = dist[j];
				v = j;
			}
			visit[v] = 1;
			
			for (int j = 0; j < N; j++) {
				if (dist[j] > dist[v] + adj[v][j])
					dist[j] = dist[v] + adj[v][j];
			}

		}
	}
}

int main() {
	int M, from, to, w;

	init();

	scanf("%d %d %d %d", &N, &M, &start, &end);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &w);
		adj[from][to] = w;
	}

	return 0;
}
