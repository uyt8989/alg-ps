#include<iostream>
#include <cstring>


using namespace std;

int days[200002];
bool visit[1000001];

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
		int n, p;
		int c;

		cin >> n >> p;

		memset(days, 0, sizeof(days));
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < n; i++) {
			cin >> days[i];
			visit[days[i]] = true;
		}
		
		int ans = p + 1;
		int start = 1, end = 1;
		int cnt = 0;

		while (end <= days[n - 1]) {
			//공부한 날
			if (visit[end]) {
				cnt++;
				end++;
			}
			//공부 안한 날
			else {
				//해킹 더 이상 못함
				if (p == 0) {
					//시작날이 해킹했던 경우
					if (visit[start] == false) p++;
					start++;
					cnt--;
				}
				//해킹 가능함
				else {
					p--;
					end++;
					cnt++;
				}
			}
			ans = cnt > ans ? cnt : ans;
		}

		cout << "#" << test_case << ' ' << ans << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}