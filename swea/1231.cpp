#include <iostream>
#include <cstring>

using namespace std;

int N;
char str[101];

void dfs(int node) {

	if(2 * node <= N)
		dfs(2 * node);
	
	cout << str[node];

	if(2 * node + 1 <= N)
		dfs(2 * node + 1);
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		memset(str, 0, sizeof(str));

		cin >> N;

		int num, lc, rc;
		char c;

		for (int i = 1; i <= N; i++) {
			cin >> num >> c;

			str[num] = c;

			if (2 * num <= N) cin >> lc;
			if (2 * num + 1 <= N) cin >> rc;
		}

		cout << '#' << test_case << ' ';
		dfs(1);
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}