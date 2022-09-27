#include <iostream>
#include <queue>

using namespace std;

int N, cards, current, sum, first, second;
priority_queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cards;
		q.push(-cards);
	}

	while (q.size() > 1) {
		first = q.top(); q.pop();
		second = q.top(); q.pop();

		sum += -(first + second);

		q.push(first + second);
 	}

	cout << sum;

	return 0;
}