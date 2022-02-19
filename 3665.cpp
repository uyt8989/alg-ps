#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int TC, N, M, a, b;
int adj[501][501], t[501], outEdge[501], ans[500], cnt;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;

	for (int tc = 0; tc < TC; tc++) {
		memset(adj, 0, sizeof(adj));
		memset(t, 0, sizeof(t));
		memset(outEdge, 0, sizeof(outEdge));
		memset(ans, 0, sizeof(ans)); cnt = 0;
		q = queue<int>();

		cin >> N;

		for (int i = 1; i <= N; i++) 
			cin >> t[i];

		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				//t[i]->t[j] : t[i] 이전에 t[j]가 나와야 함
				adj[t[i]][t[j]] = 1;
				outEdge[t[j]]++;
			}
		}

		cin >> M;

		for (int i = 1; i <= M; i++) {
			cin >> a >> b;
			//간선이 이미 있는 경우 간선을 뒤집어 준다.
			if (adj[a][b]) {
				adj[a][b] = 0; outEdge[b]--;
				adj[b][a] = 1; outEdge[a]++; 
			}
			else {
				adj[a][b] = 1; outEdge[b]++;
				adj[b][a] = 0; outEdge[a]--;
			}
		}

		for (int i = 1; i <= N; i++) {
			if (!outEdge[i]) q.push(i);
		}

		bool flag = true;

		while (!q.empty()) {
			if (q.size() > 1) {
				flag = false; break;
			}

			int cur = q.front(); q.pop();
			ans[cnt++] = cur;
			
			for (int i = 1; i <= N; i++) {
				if (adj[cur][i] != 0) {
					outEdge[i]--;
					if (outEdge[i] == 0) q.push(i);
				}
			}
		}

		if (!flag) cout << "?\n";
		else if (cnt == N) {
			for (int i = 0; i < N; i++)
				cout << ans[i] << ' ';
			cout << '\n';
		}
		else cout << "IMPOSSIBLE\n";
	}

	return 0;
}
