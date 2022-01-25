#include <iostream>
#include <vector>

#define MAX 500001

using namespace std;

int N, M;

vector<int> child[MAX];
bool visited[MAX];
int depth[MAX];
int parent[MAX][17];

void dfs(int x, int d) {
	if (visited[x]) return;

	depth[x] = d;
	visited[x] = true;

	for (int i = 0; i < child[x].size(); i++) {
		int c = child[x][i];

		if (!visited[c]) {
			parent[c][0] = x;
			dfs(c, d + 1);
		}
	}
}

void connect() {
	for (int k = 1; k < 17; k++)
		for (int cur = 1; cur <= N; cur++)
			parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	int diff = depth[u] - depth[v];
	for (int i = 0; diff != 0; i++) {
		if ((diff & 1) == 1) u = parent[u][i];
		diff = diff >> 1;
	}

	if (u != v) {
		for (int i = 16; i >= 0; i--) {
			if (parent[u][i] != 0 && parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}

		u = parent[u][0];
	}

	return u;
}

int main() {
	cin >> N;

	int p, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> c;

		child[p].push_back(c);
		child[c].push_back(p);
	}

	dfs(1, 0);
	connect();

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> p >> c;

		cout << LCA(p, c) << '\n';
	}

	return 0;
}
