#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> s;
int N, M;

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
		s.clear();

		cin >> N >> M;

		string temp;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			s.insert(temp);
		}

		int ans = 0;
		for (int i = 0; i < M; i++) {
			cin >> temp;
			if (s.find(temp) != s.end()) {
				ans++;
			}
		}

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
