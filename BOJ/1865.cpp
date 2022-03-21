#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

typedef struct _Edge {
	int S, E, T;
} Edge;

int TC, N, M, W, S, E, T;
vector<Edge> graph;
int dist[501];

bool traversal() {
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dist[1] = 0;

	int S, E, T;
	int size = 2 * M + W;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < size; j++) {
			S = graph[j].S; E = graph[j].E; T = graph[j].T;

			if (dist[E] > dist[S] + T)
				dist[E] = dist[S] + T;
		}
	}

	for (int i = 0; i < size; i++) {
		S = graph[i].S; E = graph[i].E; T = graph[i].T;
		if (dist[E] > dist[S] + T)
			return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;

	while (TC--) {
		cin >> N >> M >> W;

		graph.clear();

		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			graph.push_back({ S, E, T });
			graph.push_back({ E, S, T });
		}

		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			graph.push_back({ S, E, -T });
		}

		cout << (traversal() ? "YES" : "NO") << "\n";
	}

	return 0;
}
