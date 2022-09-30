#include <iostream>
#include <list>
#include <queue>

using namespace std;

int N, root, removed, answer;
int parent[50];
bool visited[50];
list<int> childs[50];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> parent[i];
		if (parent[i] == -1) {
			root = i;
		}
		else {
			childs[parent[i]].push_back(i);
		}
	}
	cin >> removed;

	if (removed == root) {
		cout << 0;
		return 0;
	}

	childs[parent[removed]].remove(removed);

	q.push(root);
	visited[root] = true;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (childs[cur].size() == 0) {
			answer++;
		}
		else {
			for (auto iter : childs[cur]) {
				if (!visited[iter] && iter != removed) {
					q.push(iter);
					visited[iter] = true;
				}
			}
		}
	}

	cout << answer;

	return 0;
}