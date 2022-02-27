#include <iostream>
#include <vector>

#define MAX 40001
#define MAX_PARENT 17

using namespace std;

int N, M;
int a, b, d;
vector<pair<int, int>> tree[MAX];
int parent[MAX][MAX_PARENT];
int depth[MAX]; bool visited[MAX]; int dist[MAX];

void getDepth(int cur, int _depth, int _dist) {
	visited[cur] = true;
	depth[cur] = _depth;
	dist[cur] = _dist;

	int size = tree[cur].size();
	for (int i = 0; i < size; i++) {
		if (!visited[tree[cur][i].first]) {
			parent[tree[cur][i].first][0] = cur;
			getDepth(tree[cur][i].first, _depth + 1, 
				_dist + tree[cur][i].second);
		}
	}
}

void connect() {
	for (int k = 1; k < MAX_PARENT; k++) {
		for (int cur = 1; cur <= N; cur++) {
			parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
		}
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];

	for (int i = 0; diff != 0; i++) {
		if ((diff & 1) == 1) u = parent[u][i];
		diff = diff >> 1;
	}

	if (u != v) {
		for (int i = MAX_PARENT - 1; i >= 0; i--) {
			if (parent[u][i] != 0 && 
				parent[u][i] != parent[v][i]) {
				u = parent[u][i]; v = parent[v][i];
			}
		}
		u = parent[u][0];
	}

	return u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> d;
		tree[a].push_back({ b, d });
		tree[b].push_back({ a, d });
	}

	//1번 노드를 루트로 설정
	getDepth(1, 0, 0);
	connect();

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		int lca = LCA(a, b);

		cout << dist[a] + dist[b] - 2 * dist[lca] << '\n';
	}


	return 0;
}
