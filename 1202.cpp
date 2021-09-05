#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	pair<int, int> gem[300001];
	int bag[300001];
	priority_queue<int> pq;

	for (int i = 0; i < N; i++)
		cin >> gem[i].first >> gem[i].second;
	for (int i = 0; i < K; i++)
		cin >> bag[i];

	sort(gem, gem + N);
	sort(bag, bag + K);

	long long int ans = 0;
	int idx = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N && gem[idx].first <= bag[i])
			pq.push(gem[idx++].second);
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;

	return 0;
}
