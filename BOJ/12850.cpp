#include <iostream>
#include <vector>

using namespace std;

#define ll long long
typedef vector<vector<ll>> matrix;

const int mod = 1000000007;
int D;
matrix A = {
	{0, 1, 0, 0, 0, 1, 0, 0},
	{1, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 1, 0, 0, 1, 1},
	{0, 0, 1, 0, 1, 0, 0, 1},
	{0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 0, 0, 1, 0, 1},
	{0, 0, 1, 1, 1, 0, 1, 0}
};

matrix ans = {
	{1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 1}
};

matrix operator * (matrix &a, matrix &b) {
	matrix c(8, vector<ll>(8));

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= mod;
		}
	}

	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> D;

	while (D > 0) {
		if (D & 1) {
			ans = ans * A;
		}

		A = A * A;
		D = D >> 1;
	}

	cout << ans[4][4] << "\n";

	return 0;
}
