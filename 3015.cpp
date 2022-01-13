#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

int N, h;
stack<pair<int, int>> S;
pair<int, int> temp;
long answer;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &h);

		int d = 1;
		while (!S.empty() && S.top().first <= h) {
			if (S.top().first == h) {
				temp = S.top();
				S.pop();

				answer += temp.second;
				d = temp.second + 1;
			}

			else {
				temp = S.top();
				S.pop();

				answer += temp.second;
				d = 1;
			}
		}
		if (!S.empty()) answer++;
		S.push(make_pair(h, d));
	}

	printf("%ld\n", answer);

	return 0;
}
