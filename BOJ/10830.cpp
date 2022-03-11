#include <iostream>
#include <vector>

using namespace std;

#define ll long long

typedef vector<vector<ll>> matrix;

const ll mod = 1000;
int N;
ll B;
matrix A, ans;

matrix operator * (matrix& a, matrix& b) {
	matrix c(N, vector<ll>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)
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

	cin >> N >> B;

	A.resize(N, vector<ll>(N)); 
	ans.resize(N, vector<ll>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
		ans[i][i] = 1;
	}

	while (B > 0) {
		if ((B & 1) == 1) {
			ans = ans * A;
		}
		A = A * A;
		B = B >> 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << "\n";
	}

	return 0;
}
