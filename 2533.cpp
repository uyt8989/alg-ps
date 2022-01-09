#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000001

int N;
int u, v;
vector<int> edge[MAX];
int dp[MAX][2];
bool visited[MAX];

void find(int x) {
	visited[x] = true;
	dp[x][0] = 1;

	for (int i = 0; i < edge[x].size(); i++) {
		int child = edge[x][i];
		if (visited[child]) continue;
		find(child);

		dp[x][1] += dp[child][0];
		dp[x][0] += min(dp[child][0], dp[child][1]);
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	find(1);

	printf("%d\n", min(dp[1][0], dp[1][1]));

	return 0;
}
