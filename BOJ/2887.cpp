#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Planet {
	int x, y, z, num;
}Planet;

typedef struct Edge {
	int w, from, to;
}Edge;

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.w > b.w;
	}
};

bool cmpX(const Planet& p1, const Planet& p2) {
	return p1.x > p2.x;
}
bool cmpY(const Planet& p1, const Planet& p2) {
	return p1.y > p2.y;
}
bool cmpZ(const Planet& p1, const Planet& p2) {
	return p1.z > p2.z;
}

int N;
int root[100001];
Planet planet[100001];
priority_queue<Edge, vector<Edge>, cmp> edge;

int find(int x) {
	if (root[x] == x) return x;
	return root[x] = find(root[x]);
}

void union_set(int u, int v) {
	u = find(u);
	v = find(v);

	root[v] = u;

	return;
}

long long kruskal() {
	long long ans = 0;
	int mst_e = 0;
	int u, v, w;

	for (int i = 1; i <= N; i++)
		root[i] = i;

	while (mst_e < N - 1) {
		w = edge.top().w;
		u = edge.top().from;
		v = edge.top().to;
		edge.pop();

		if (find(u) != find(v)) {
			ans += w;
			union_set(u, v);
			mst_e++;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> planet[i].x >> planet[i].y >> planet[i].z;
		planet[i].num = i;
	}

	sort(planet + 1, planet + 1 + N, cmpX);
	for (int i = 1; i <= N - 1; i++)
		edge.push({ abs(planet[i].x - planet[i + 1].x), planet[i].num, planet[i + 1].num });
	
	sort(planet + 1, planet + 1 + N, cmpY);
	for (int i = 1; i <= N - 1; i++)
		edge.push({ abs(planet[i].y - planet[i + 1].y), planet[i].num, planet[i + 1].num });
	
	sort(planet + 1, planet + 1 + N, cmpZ);
	for (int i = 1; i <= N - 1; i++)
		edge.push({ abs(planet[i].z - planet[i + 1].z), planet[i].num, planet[i + 1].num });

	cout << kruskal();

	return 0;
}
