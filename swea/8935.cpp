#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dp[3002][2][102][102];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		vector<int> A(3002), B(102);

		memset(dp, 0, sizeof(dp));

		cin >> N;
		for (int i = 2; i <= N + 1; i++)
			cin >> A[i];

		cin >> M;
		for (int i = 2; i <= M + 1; i++)
			cin >> B[i];

		sort(B.begin() + 2, B.begin() + M + 2, greater<int>());

		for (int i = 1; i <= M + 1; i++)
			cout << B[i];
		cout << endl;

		for (int i = 1; i <= N + 1; i++) {
			for (int j = 1; j <= M + 1; j++) {
				for (int k = 1; k <= M - j + 2; k++) {
					dp[i][0][j][k] = max(max(dp[i - 1][0][j][k], dp[i - 1][1][j][k]), max(dp[i][0][j][k - 1], dp[i][1][j][k - 1]));
					dp[i][1][j][k] = max(dp[i - 1][0][j][k] + A[i], dp[i][0][j - 1][k] + (B[j]));
				}
			}
		}

		int res = 0;
		for (int i = 1; i <= M + 1; i++) {
			for (int k = 0; k < 2; k++) {
				res = max(res, dp[N + 1][k][i][M + 2 - i]);
			}
		}

		cout << '#' << test_case << ' ' << res << '\n';
 	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}