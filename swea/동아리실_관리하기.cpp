#include <iostream>
#include <string>
#include <cstring>

#define MAX_DAYS 10001
#define MAX 16
#define MOD 1000000007

using namespace std;

string admin;
long dp[MAX_DAYS][MAX];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		admin.clear();
		
		cin >> admin;

		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < admin.size(); i++) {
			int today_admin = 1 << (admin[i] - 'A');

			for (int j = 1; j < MAX; j++) {
				if (i == 0) {
					if ((today_admin & j) != 0 && (j & 1) != 0) {
						dp[i][j] = 1;
					}
				}
				else {
					if (dp[i - 1][j] != 0) {
						for (int k = 1; k < MAX; k++) {
							if ((j & k) != 0 && (k & today_admin) != 0) {
								dp[i][k] += dp[i - 1][j];
								dp[i][k] %= MOD;
							}
						}
					}
				}
			}
		}

		long answer = 0;
		for (int i = 1; i < MAX; i++) {
			answer += dp[admin.size() - 1][i];
			answer %= MOD;
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}
