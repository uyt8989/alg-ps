#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10001

typedef struct element {
	int key;
	int u, v;
}element;

int parent[MAX_VERTICES];
int rank[MAX_VERTICES];
int V, E;
element e[100001];

int compare(const void* a, const void* b) {
	element* m = (element*)a;
	element* n = (element*)b;
	return (m->key - n->key);
}

void init_set(int i) {
	parent[i] = i;
}

int find_set(int v) {
	if (parent[v] == v)
		return v;
	else
		return parent[v] = find_set(parent[v]);
}

void union_set(int u, int v) {
    parent[v] = u;
}

int kruskal() {
	int u, v;
	int mst_e = 0;
	int mst_e_n = 0;

	qsort(e, E, sizeof(element), compare);
	for (int i = 0; i < V; i++)
		init_set(i);
	for (int i = 0; mst_e_n < V - 1; i++) {
		u = e[i].u;
		v = e[i].v;
		int rootA = find_set(u);
		int rootB = find_set(v);
		if (rootA != rootB) {
			mst_e += e[i].key;
			mst_e_n++;
			union_set(rootA, rootB);
		}
	}

	return mst_e;
}

int main() {
	int A, B, C;
	
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &A, &B, &C);
		e[i].u = A;
		e[i].v = B;
		e[i].key = C;
	}

	printf("%d\n", kruskal());

	return 0;
}
