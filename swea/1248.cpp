#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int V, E, n1, n2;
int parent[10001][16];
vector<int> child[10001];
int depth[10001];

int bfs(int start) {
	int cnt = 0;
	queue<pair<int, int>> q;

	q.push({ start, 0 });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		cnt++;

		depth[cur.first] = cur.second;

		for (int i = 0; i < child[cur.first].size(); i++) {
			q.push({ child[cur.first][i], cur.second + 1 });
		}
	}

	return cnt;
}

void connect() {
	for (int k = 1; k < 16; k++) {
		for (int cur = 1; cur <= V; cur++) {
			parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
		}
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	int diff = depth[u] - depth[v];
	for (int i = 0; diff != 0; i++) {
		if ((diff & 1) == 1) {
			u = parent[u][i];
		}
		diff = diff >> 1;
	}

	if (u != v) {
		for (int i = 15; i >= 0; i--) {
			if (parent[u][i] != 0 && parent[u][i] != parent[v][i]) {
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
	int test_case;
	int T;
	
	freopen("input.txt", "r", stdin);

	cin >> T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		memset(parent, 0, sizeof(parent));
		memset(depth, 0, sizeof(depth));
		for (int i = 0; i < 10001; i++)
			child[i].clear();

		cin >> V >> E >> n1 >> n2;

		int p, c;
		for (int i = 0; i < E; i++) {
			cin >> p >> c;
			parent[c][0] = p;
			child[p].push_back(c);
		}

		bfs(1);
		connect();

		cout << '#' << test_case << ' ';
		int ans1 = LCA(n1, n2);
		cout << ans1 << ' ';
		int ans2 = bfs(ans1);

		cout << ans2 << '\n';
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
