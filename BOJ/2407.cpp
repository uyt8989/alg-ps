#include <iostream>
#include <string>

using namespace std;

int n, m;
string C[101][101];

string add(string n1, string n2) {
	string res = "";
	int len1 = n1.length();
	int len2 = n2.length();
	int len = len1 > len2 ? len1 : len2;
	int sum = 0;

	for (int i = 0; i < len || sum; i++) {
		if (len1 > i) sum += n1[i] - '0';
		if (len2 > i) sum += n2[i] - '0';

		res += (sum % 10) + '0';
		sum /= 10;
	}

	return res;
}

string Comb(int N, int M) {
	if (M == 0 || N == M) return C[N][M] = "1";
	
	if (C[N][M] != "") return C[N][M];

	return C[N][M] = add(Comb(N - 1, M - 1), Comb(N - 1, M));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	Comb(n, m);

	for (int i = C[n][m].length() - 1; i >= 0; i--)
		cout << C[n][m][i];

	return 0;
}
