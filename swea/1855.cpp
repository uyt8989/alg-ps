#include <iostream>
#include <vector>
#include <queue>

#define MAX_NODES 100001
#define MAX 19

using namespace std;

int N;
int parent[MAX_NODES][MAX];
int depth[MAX_NODES];
vector<int> child[MAX_NODES];

void get_depth() {
	pair<int, int> cur;
	queue<pair<int, int>> q;

	q.push({ 1, 0 });
	while (!q.empty()) {
		cur = q.front(); q.pop();
		depth[cur.first] = cur.second;

		for (int i = 0; i < child[cur.first].size(); i++) {
			q.push({ child[cur.first][i], cur.second + 1 });
		}
	}
}

void get_parent() {
	for (int k = 1; k < MAX; k++) {
		for (int cur = 1; cur <= N; cur++) { 
			parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
		}
	}
}

int get_LCA(int u, int v) {
	//u가 더 낮은 위치에 있음
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	int diff = depth[u] - depth[v];
	for (int i = 0; diff != 0; i++) {
		if ((diff & 1) == 1)
			u = parent[u][i];
		diff = diff >> 1;
	}

	if (u != v) {
		for (int i = MAX - 1; i >= 0; i--) {
			if (parent[u][i] != 0 && (parent[u][i] != parent[v][i])) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}

	return u;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N; 

		for (int i = 1; i <= N; i++)
			child[i].clear();

		for (int i = 2; i <= N; i++) {
			cin >> parent[i][0];
			child[parent[i][0]].push_back(i);
		}

		get_depth();
		get_parent();
		
		long long ans = 0;
		int prev = 1, cur;

		queue<int> q;
		//root의 child
		for (int i = 0; i < child[1].size(); i++)
			q.push(child[1][i]);
		
		while (!q.empty()) {
			cur = q.front(); q.pop();

			for (int i = 0; i < child[cur].size(); i++) {
				q.push(child[cur][i]);
			}

			int lca = get_LCA(prev, cur);

			
			ans = ans + (depth[prev] - depth[lca]) + (depth[cur] - depth[lca]);

			prev = cur;
		}
		
		cout << "#" << test_case << ' ' << ans << '\n';
	}

	return 0;
}