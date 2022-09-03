#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int LIS(string s1, string s2) {
	int len1 = s1.length();
	int len2 = s2.length();
	
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[len1][len2];
}

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
		string str1, str2;

		cin >> str1 >> str2;

		memset(dp, 0, sizeof(dp));

		cout << '#' << test_case << ' ';
		cout << LIS(str1, str2) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}