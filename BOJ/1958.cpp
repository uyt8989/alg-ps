#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[101][101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2, str3;
	cin >> str1 >> str2 >> str3; 

	int len1, len2, len3;
	int answer = 0;
	len1 = str1.length();
	len2 = str2.length();
	len3 = str3.length();

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			for (int k = 1; k <= len3; k++) {
				if (str1[i - 1] == str2[j - 1] && str2[j-1] == str3[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else {
					dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
				}
			}
		}
	}

	cout << dp[len1][len2][len3];

	return 0;
}
