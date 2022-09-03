#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int N;

string tree[1001];
pair<int, int> child[1001];

int dfs(int node) {
	if (tree[node][0] != '+' && tree[node][0] != '-' &&
		tree[node][0] != '*' && tree[node][0] != '/') {
		return stoi(tree[node]);
	}

	int lc = child[node].first;
	int rc = child[node].second;
	switch (tree[node][0]) {
	case '+': 
		return dfs(lc) + dfs(rc);
		break;
	case '-':
		return dfs(lc) - dfs(rc);
		break;
	case '*':
		return dfs(lc) * dfs(rc);
		break;
	case '/':(rc);
		return dfs(lc) / dfs(rc);
		break;
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int test_case;
	int T;
	

	//freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> N;

		int num, lc, rc;
		string data;
		for (int i = 1; i <= N; i++) {
			cin >> num >> data;

			tree[num] = data;

			if (data[0] == '+' || data[0] == '-' || 
				data[0] == '*' || data[0] == '/') {
				cin >> lc >> rc;
				child[num].first = lc;
				child[num].second = rc;

			}
		}
		cout << '#' << test_case << ' ' << dfs(1) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}