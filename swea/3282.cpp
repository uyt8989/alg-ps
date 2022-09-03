#include <iostream>
#include <algorithm>

using namespace std;

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
		int N, K;
		pair<int, int> thing[100];
		int dp[101][1001] = { 0, };

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> thing[i].first >> thing[i].second;
		}

		for(int i = 1; i <= N; i++){
			for (int j = 0; j <= K; j++) {
				if (j - thing[i - 1].first >= 0)
					dp[i][j] = max(dp[i - 1][j],
						dp[i - 1][j - thing[i - 1].first] + thing[i - 1].second);
				else dp[i][j] = dp[i - 1][j];
			}
		}
		
		cout << '#' << test_case << ' ';
		cout << dp[N][K] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}