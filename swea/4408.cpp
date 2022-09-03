#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int convert(int idx) {
	if (idx & 1) return idx >> 1;
	else return (idx >> 1) - 1;
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
		int N, a, b;
		vector<int> cnt(200);

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> a >> b;

			a = convert(a);
			cout << a;
			b = convert(b);
			cout << b;
			if (b < a) {
				swap(a, b);
			}
			for (int j = a; j <= b; j++) {
				cnt[j]++;
			}
		}
		
		int ans = *max_element(cnt.begin(), cnt.end());
		cout << "#" << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}