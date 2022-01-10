#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 32001

int N, M;
vector<int> order[MAX];
int counter[MAX];
queue<int> Q;

int main() {
	scanf("%d %d", &N, &M);

	int A, B;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		order[A].push_back(B);
		counter[B]++;
	}

	for (int i = 1; i <= N; i++)
		if (counter[i] == 0) Q.push(i);

	int cur;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();

		printf("%d ", cur);

		for (int i = 0; i < order[cur].size(); i++) {
			if (--counter[order[cur][i]] == 0)
				Q.push(order[cur][i]);
		}
	}

	return 0;
}
