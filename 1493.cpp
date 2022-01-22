#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int l, w, h;
int N;
int B[21];
long long cnt;

void sol(int l, int w, int h) {
	if (l == 0 || w == 0 || h == 0) return;

	int k = min(min(l, w), h);
	int t = log2(k);

	for (; t >= 0; t--)
		if (B[t] > 0) 
			goto pass;

	cout << -1;
	exit(0);

pass:
	B[t]--;
	cnt++;
	
	int p = 1 << t;
	sol(l - p, w, h);
	sol(p, w - p, p);
	sol(p, w, h - p);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> l >> w >> h;
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		B[a] = b;
	}

	sol(l, w, h);

	cout << cnt;

	return 0;
}
