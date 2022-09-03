#include <iostream>
#include <queue>

struct Road {
	int start, end, cost;

	Road(int s, int e, int c): start(s), end(e), cost(c) {};

	bool operator<(const Road r) const {
		return this->cost > r.cost;
	}
};

using namespace std;

int N, M;
int parent[50002];
priority_queue<Road> pq;


int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

bool checkParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	return x == y;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	int s, e, c;
	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> N;
		cin >> M;

		for (int i = 0; i < M; i++) {
			cin >> s >> e >> c;
			pq.push({ s, e, c });
		}

		for (int i = 0; i < N; i++)
			parent[i] = i;

		int ans = 0;
		while (!pq.empty()) {
			Road cur = pq.top();
			pq.pop();
			if (!checkParent(cur.start, cur.end)) {
				unionParent(cur.start, cur.end);
				ans += cur.cost;
			}	
		}

		cout << "#" << test_case << ' ' << ans << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
