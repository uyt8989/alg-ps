#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N, M;
int cnt[1001];
vector<int> order[1001];
queue<int> q;
queue<int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int prev = 0, cur;
		int num;
		cin >> num;

		for (int j = 0; j < num; j++) {
			cin >> cur;
			if (prev != 0) {
				cnt[cur]++;
				order[prev].push_back(cur);
			}
			prev = cur;
		}
	} 

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push(cur);

		for (int i = 0; i < order[cur].size(); i++) {
			if (--cnt[order[cur][i]] == 0) {
				q.push(order[cur][i]);
			}
		}
	}

	if (ans.size() != N) {
		cout << 0 << '\n';
	} else {
		for (int i = 0; i < N; i++) {
			cout << ans.front() << "\n";
			ans.pop();
		}
	}
}
