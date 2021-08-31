#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
	int from, to, cost;
}Edge;

int N, M;
int dist[100001];
int root[100001];
Edge edge[1000001];
int mst = 0;
int max_edge = 0;

int compare(const void* a, const void* b) {
	Edge e1 = *(Edge*)a;
	Edge e2 = *(Edge*)b;

	return e1.cost - e2.cost;
}

int find_set(int x) {
	if (root[x] == x)
		return x;
	else return root[x] = find_set(root[x]);
}

void union_set(int u, int v) {
	root[v] = u;
	return;
}

void kruskal() {
	int edges = 0;

	for (int i = 1; i <= N; i++)
		root[i] = i;

	for (int i = 0; edges < N - 1; i++) {
		int rootA = find_set(edge[i].from);
		int rootB = find_set(edge[i].to);

		if (rootA != rootB) {
			printf("%d %d %d\n", edge[i].from, edge[i].to, edge[i].cost);

			union_set(edge[i].from, edge[i].to);
			mst += edge[i].cost;
			edges++;
			if (max_edge < edge[i].cost)
				max_edge = edge[i].cost;
		}
	}
	return;
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
		scanf("%d %d %d", &edge[i].from, &edge[i].to, &edge[i].cost);

	qsort(edge, M, sizeof(Edge), compare);

	printf("\n");
	//for (int i = 0; i < M; i++)
	//	printf("%d %d %d\n", edge[i].from, edge[i].to, edge[i].cost);

	kruskal();

	printf("%d\n", mst - max_edge);

	return 0;
}
