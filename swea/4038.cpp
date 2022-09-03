#include <iostream>
#include <string>

#define HASH_SIZE (1 << 18)
#define DIV (HASH_SIZE - 1)

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ans = 0;

		string ws, ps;

		cin >> ws;
		cin >> ps;

		int wsSize = ws.size();
		int psSize = ps.size();

		long long wsHash[5] = { 0, };
		long long psHash[5] = { 0, };

		long long power[5] = { 1, 1, 1, 1, 1 }; // 제곱수

		for (int i = 0; i <= wsSize - psSize; i++) {
			if (i == 0) {
				for (int j = 0; j < psSize; j++) {
					for (int i = 0; i < 5; i++) {
						wsHash[i] += ws[psSize - 1 - j] * power[i];
						psHash[i] += ps[psSize - 1 - j] * power[i];
					}
					if (j < psSize - 1) {
						for (int k = 0; k < 5; k++) {
							power[k] *= (k + 1);
						}
					}
				}
			}
			else {

				for (int k = 0; k < 5; k++) {
					wsHash[k] = (k + 1) * (wsHash[k] - ws[i - 1] * power[k]) + ws[psSize - 1 + i];
				}
			}
			bool flag = true;
			for (int k = 0; k < 5; k++) {
				if (wsHash[k] != psHash[k]) {
					flag = false;
				}
			}
			if (flag) {
				ans++;
			}
		}
		
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
