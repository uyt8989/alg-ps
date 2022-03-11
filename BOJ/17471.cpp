#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#define MAX 10000

using namespace std;

int N;
int population[11];
vector<int> adj[11];
 
int checkArea(int area) {
	int visited = 0, cur;
	queue<int> q;
	int p0, p1;

	p0 = p1 = 0;

	//0으로 마스킹된 구역
	for (int i = 1; i <= N; i++) {
		if ((area & (1 << i)) == 0) {
			visited = visited | (1 << i);
			q.push(i);
			break;
		}
	}

	while (!q.empty()) {
		cur = q.front(); q.pop();
		p0 += population[cur];

		for (int i = 0; i < adj[cur].size(); i++) {
			if ((visited & (1 << adj[cur][i])) != (1 << adj[cur][i])
				&& ((area & (1 << adj[cur][i])) == 0)) {
				visited = visited | (1 << adj[cur][i]);
				q.push(adj[cur][i]);
			}
		}
	}

	//1로 마스킹된 구역
	for (int i = 1; i <= N; i++) {
		if ((area & (1 << i)) == (1 << i)) {
			visited = visited | (1 << i);
			q.push(i);
			break;
		}
	}

	while (!q.empty()) {
		cur = q.front(); q.pop();
		p1 += population[cur];

		for (int i = 0; i < adj[cur].size(); i++) {
			if ((visited & (1 << adj[cur][i])) != (1 << adj[cur][i])
				&& ((area & (1 << adj[cur][i])) == (1 << adj[cur][i]))) {
				visited = visited | (1 << adj[cur][i]);
				q.push(adj[cur][i]);
			}
		}
	}
	
	if (visited != ((1 << (N + 1)) - 2)) {
		return MAX;
	}

	return abs(p0 - p1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> population[i];
	}

	int num, temp;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> temp;
			adj[i].push_back(temp);
		} 
	}

	int ans = MAX;
	int bound = ((1 << (N + 1)) - 1) >> 1;
	for (int area = 2; area < bound; area++) {
		ans = min(ans, checkArea(area));
	}
	
	if (ans == MAX) {
		cout << -1 << "\n";
	}
	else 
		cout << ans << '\n';

	return 0;
}
