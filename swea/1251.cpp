#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <limits.h>

using namespace std;

#define MAX_ISLAND 1000

int N;
double E;
pair<long long, long long> loca[MAX_ISLAND];
long long adj[MAX_ISLAND][MAX_ISLAND];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> loca[i].first;
	}
	for (int i = 0; i < N; i++) {
		cin >> loca[i].second;
	}

	cin >> E;
}

void make_mat() {
	long long temp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp = ((loca[i].first - loca[j].first) * (loca[i].first - loca[j].first))
				+ ((loca[i].second - loca[j].second) * (loca[i].second - loca[j].second));

			adj[i][j] = temp;
			adj[j][i] = temp;
		}
	}
}

long long get_mst(int start) {
	long long cost = 0;

	bool visit[MAX_ISLAND];
	long long dist[MAX_ISLAND];

	memset(visit, false, sizeof(visit));

	visit[start] = true;

	for (int i = 0; i < N; i++) {
		dist[i] = adj[start][i];
	}

	for (int t = 0; t < N - 1; t++) {
		int min_idx = -1;
		long long min = LLONG_MAX;

		for (int i = 0; i < N; i++) {
			if (!visit[i] && dist[i] < min) {
				min_idx = i;
				min = dist[i];
			}
		}

		cost += min;
		visit[min_idx] = true;

		for (int i = 0; i < N; i++) {
			if (!visit[i]) {
				if (adj[min_idx][i] < dist[i]) {
					dist[i] = adj[min_idx][i];
				}
			}
		}
	}

	return cost;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		input();

		make_mat();

		long long ans = get_mst(0);

		ans = round(ans * E);

		cout << "#" << test_case << ' ' << ans << '\n';
	}

	return 0;
}