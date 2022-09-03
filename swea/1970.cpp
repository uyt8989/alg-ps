#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	int money[8] = 
	{ 50000, 10000, 5000, 1000, 500, 100, 50, 10 };

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int cnt[8] = { 0, };

		cin >> N;
		
		
		for (int i = 0; i < 8; i++) {
			cnt[i] = N / money[i];
			N -= cnt[i] * money[i];
		}
	

		cout << "#" << test_case << '\n';
		for (int i = 0; i < 8; i++) {
			cout << cnt[i] << ' ';
		}
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}