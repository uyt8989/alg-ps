#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

#define MAX 200000

int N, K;
int W[MAX], S[MAX];

int check(int x) {
	int cur = 0;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (W[i] <= x) {
			cnt++;
		}
		else {
			cnt = 0;
		}

		if (cnt == S[cur]) {
			cur++;
			cnt = 0;
			if (cur == K) break;
		}
	}

	return cur == K;
}

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
		cin >> N >> K;

		for (int i = 0; i < N; i++) 
			cin >> W[i];
		for (int i = 0; i < K; i++) 
			cin >> S[i];
		
		int l = 0, r = MAX;
		int m;
		while (l < r) {
			m = (l + r) / 2;

			if (check(m)) r = m;
			else l = m + 1;
		}

		cout << '#' << test_case << ' ';
		cout << r << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}