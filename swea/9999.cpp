#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> peak[100000];
int sum[100001];

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
		int L, N;	
		
		cin >> L >> N;

		int s, e;
		for (int i = 0; i < N; i++) {
			cin >> peak[i].first >> peak[i].second;
			sum[i + 1] = sum[i] + (peak[i].second - peak[i].first);
		}

		int end = peak[N - 1].second - L + 1;
		int cur = 0;
		int ans = 0;

		int s = 0;
		for(int e = 0; e < N; e++){
			for (; s <= e && peak[s].first + L <= peak[e].second; s++) {
				int len = peak[s].first + L - peak[e].first;
				if (len > 0) {
					ans = max(ans, sum[e] - sum[s] + len);
				}
				else {
					ans = max(ans, sum[e] - sum[s]);
				}
			}
		}
		if (s < N)
			ans = max(ans, sum[N] - sum[s]);

		cout << '#' << test_case << ' ' << ans << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}