#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int INF = 987654321;

int n, m, A, B;
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>> pq;
int prev_node[1001], dist[1001];
stack<int> path;

void Dijkstra(int start) {
	prev_node[start] = -1;
	dist[start] = 0;

	pq.push({ start, 0 });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int d = -pq.top().second;
		pq.pop();

		if (dist[cur] < d) continue;

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int nd = d + adj[cur][i].second;

			if (nd < dist[next]) {
				prev_node[next] = cur;
				dist[next] = nd;
				pq.push({ next, -nd });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
	}
	cin >> A >> B;

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	Dijkstra(A);

	cout << dist[B] << "\n";

	int temp = B;
	while (temp != -1) {
		path.push(temp);
		temp = prev_node[temp];
	}
	cout << path.size() << "\n";

	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
	}

	return 0;
}
