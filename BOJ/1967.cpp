#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<pair<int, int>> child[10001];
int visited[10001];
int u, uWeight;

void DFS(int cur, int tWeight) {
	visited[cur] = true;

	if (tWeight > uWeight) {
		u = cur;
		uWeight = tWeight;
	}

	for (int i = 0; i < child[cur].size(); i++) {
		if(!visited[child[cur][i].first])
			DFS(child[cur][i].first, tWeight + child[cur][i].second);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int p, c, w;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> c >> w;
		child[p].push_back({ c, w });
		child[c].push_back({ p, w });
	}

	DFS(1, 0);
	
	int v = u;
	u = 0; uWeight = 0;

	memset(visited, false, sizeof(visited));

	DFS(v, 0);

	cout << uWeight;

	return 0;
}
