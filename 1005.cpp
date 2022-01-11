#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001

int T, N, K, W;
int D[MAX];
vector<int> order[MAX];
int counter[MAX];
queue<int> Q;
int dp[MAX];

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &K);

		for (int i = 1; i <= N; i++)
			order[i].clear();
	

		for (int i = 1; i <= N; i++) {
			scanf("%d", &D[i]);
			dp[i] = D[i];
		}

		int X, Y; 
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &X, &Y);
			order[X].push_back(Y);
			counter[Y]++;
		}
		scanf("%d", &W);

		for (int i = 1; i <= N; i++)
			if (counter[i] == 0) Q.push(i);
		
		int cur;
		while (!Q.empty()) {
			cur = Q.front();
			Q.pop();

			for (int i = 0; i < order[cur].size(); i++) {
				if (--counter[order[cur][i]] == 0)
					Q.push(order[cur][i]);
				dp[order[cur][i]] = max(dp[order[cur][i]], dp[cur] + D[order[cur][i]]);
			}
		}

		printf("%d\n", dp[W]);
	}

	return 0;
}
