#include <iostream>
#include <queue>

using namespace std;

typedef struct _Number {
	int cnt;
	int left;

	bool operator<(const _Number& num) const {
		return cnt > num.cnt;
	}
}Number;

int N, K;
int A[10];
priority_queue<Number> pq;

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
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cin >> K;
		
		pq = priority_queue<Number>();

		cout << '#' << test_case << ' ';
		
		pq.push({ 0, K });
		while (pq.top().left) {
			Number cur = pq.top();
			pq.pop();

			for (int i = 0; i < N; i++) {
				pq.push({ cur.cnt + cur.left % A[i], cur.left / A[i] });
			}
			pq.push({ cur.cnt + cur.left, 0 });
			
		}

		cout << pq.top().cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
