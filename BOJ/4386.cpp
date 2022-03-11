#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int root[101];

class Edge {
public:
	int node[2];
	double distance;
	Edge(int a, int b, double distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int getParent(int node) {
	if (root[node] == node) return node;
	return root[node] = getParent(root[node]);
}

void unionParent(int node1, int node2) {
	root[node2] = node1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<double, double>> star(n + 1);
	vector<Edge> v;

	for (int i = 1; i <= n; i++) 
		cin >> star[i].first >> star[i].second;

	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			v.push_back(Edge(i, j, sqrt(pow(star[i].first - star[j].first, 2) 
				+ pow(star[i].second - star[j].second, 2))));
		}
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++)
		root[i] = i;

	double sum = 0;
	int edges = 0;
	for (int i = 0; edges < n - 1; i++) {
		int root1 = getParent(v[i].node[0]);
		int root2 = getParent(v[i].node[1]);
		if (root1 != root2) {
			sum += v[i].distance;
			edges++;
			unionParent(root1, root2);
		}
	}

	cout << fixed;
	cout.precision(3);

	cout << sum << endl;

	return 0;
}
