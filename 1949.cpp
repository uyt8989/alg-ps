#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001

int N;
int u, v;
vector<int> edge[MAX];
int p[MAX];
int dp[MAX][2];
bool visited[MAX];

void find(int x) {
	visited[x] = true;
	dp[x][1] = p[x];

	for (int i = 0; i < edge[x].size(); i++) {
		int child = edge[x][i];
		if (visited[child]) continue;
		find(child);

		dp[x][1] += dp[child][0];
		dp[x][0] += max(dp[child][1], dp[child][0]);
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &p[i]);

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	find(1);

	printf("%d\n", max(dp[1][0], dp[1][1]));

	return 0;
}
