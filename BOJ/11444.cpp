#include <iostream>
#include <vector>

using namespace std;

#define ll long long

typedef vector<vector<ll>> matrix;

const ll mod = 1000000007;
ll N;
matrix A = { {1, 1}, {1, 0} };
matrix ans = { {1, 0}, {0, 1} };

matrix operator * (matrix& a, matrix& b) {
	matrix c = { {0, 0}, {0, 0} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) 
				c[i][j] += a[i][k] * b[k][j];
			c[i][j] = c[i][j] % mod;
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N > 0) {
		if ((N & 1) == 1) {
			ans = ans * A;
		}
		A = A * A;
		N = N >> 1;
	}

	cout << ans[0][1] << '\n';

	return 0;
}
