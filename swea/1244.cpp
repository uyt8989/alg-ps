#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
int memo[11][1000000];
int ans;

int change(int cnt, string str) {
	int num = stoi(str);

	//cout << cnt << ' ' << str << '\n';
	
	if (cnt == N ) {
		//cout << cnt << ' ' << str << '\n';
		return num;
	}
	
	if (memo[cnt][num] != 0) {
		return memo[cnt][num];
	}

	int len = str.length();
	int ret = 0, temp = 0;

	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			swap(str[i], str[j]);
			temp = change(cnt + 1, str);
			swap(str[i], str[j]);

			if (temp > ret) ret = temp;
		}
	}
	
	return memo[cnt][num] = ret;
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
		string str;
		
		memset(memo, 0, sizeof(memo));

		cin >> str >> N;

		int ans = change(0, str);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}