#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int N, M;
set<string> table;
priority_queue<string, vector<string>, greater<string>> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		table.insert(temp);
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		
		if (table.find(temp) != table.end()) {
			answer.push(temp);
		}
	}

	//sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	while(!answer.empty()) {
		cout << answer.top() << '\n';
		answer.pop();
	}

	return 0;
}
