#include <iostream>
#include <vector>
#include <queue>

#define MAX 32001

using namespace std;

int N, M;
vector<int> order[MAX];
int cnt[MAX];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		order[A].push_back(B);
		cnt[B]++;
	}

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = (q.top());
		q.pop();
		cout << cur << ' ';

		for (int i = 0; i < order[cur].size(); i++) {
			if (--cnt[order[cur][i]] == 0) {
				q.push(order[cur][i]);
			}
		}
	}

	return 0;
}
