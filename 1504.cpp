#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

const int INF = 7654321;
int N, E;
int v1, v2;
int mat[1001][1001];
int dist[1001];

int Dijkstra(int start, int end) {
	if (start == end) return 0;
	
	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	std::priority_queue<std::pair<int, int>> pq;

	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (int i = 1; i <= N; i++) {
			if (dist[i] > dist[cur] + mat[cur][i]) {
				dist[i] = dist[cur] + mat[cur][i];
				pq.push({ -dist[i], i });
			}
		}
	}
	
	return dist[end];
}

int main() {
	std::cin >> N >> E;
	
	for (int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			mat[i][j] = INF;

	int a, b, c;
	for (int i = 0; i < E; i++) {
		std::cin >> a >> b >> c;
		mat[a][b] = c;
		mat[b][a] = c;
	}

	std::cin >> v1 >> v2;

	int sum1 = 0;
	int sum2 = 0;
	int result;
	
	result = Dijkstra(1, v1);
	sum1 += result;
	
	result = Dijkstra(v1 ,v2);
	sum1 += result;
	
	result = Dijkstra(v2, N);
	sum1 += result;

	//------------------------------

	result = Dijkstra(1, v2);
	sum2 += result;

	result = Dijkstra(v2, v1);
	sum2 += result;

	result = Dijkstra(v1, N);
	sum2 += result;

	result = std::min(sum1, sum2);

	if (result >= INF) std::cout << -1;
	else std::cout << result;

	return 0;
}
