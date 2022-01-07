#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N, M;
int T;
int parent[51];
int truth[51];
int party[50][51];

int find_set(int x) {
	if (parent[x] == 0) return 0;
	if (parent[x] == x) return x;
	else return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		if (a < b) parent[b] = a;
		else parent[a] = b;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
		scanf("%d", &truth[i]);

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < T; i++)
		parent[truth[i]] = 0;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &party[i][0], &party[i][1]);
		for (int j = 2; j <= party[i][0]; j++) {
			scanf("%d", &party[i][j]);
			union_set(party[i][1], party[i][j]);
		}
	}

	int answer = 0;

	for (int i = 0; i < M; i++) {
		int flag = 0;

		for (int j = 1; j <= party[i][0]; j++) {
			if (find_set(party[i][j]) == 0) flag = 1;
		}

		if (flag == 0) answer++;
	}

	printf("%d\n", answer);

	return 0;
}
