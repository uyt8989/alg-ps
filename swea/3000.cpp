#include <iostream>
#include <queue>

#define MOD 20171109

using namespace std;

int N, A;
int answer;
priority_queue<int> left_pq;
priority_queue<int, vector<int>, greater<int>> right_pq;



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
		answer = 0;
		left_pq = priority_queue<int> ();
		right_pq = priority_queue<int, vector<int>, greater<int>> ();

		cin >> N >> A;

		int X, Y;
		for (int i = 0; i < N; i++) {
			cin >> X >> Y;
			
			if (X < A) 
				left_pq.push(X);
			else 
				right_pq.push(X);
			
			
			if (Y < A) 
				left_pq.push(Y);
			else 
				right_pq.push(Y);

			if (left_pq.size() > right_pq.size()) {
				right_pq.push(A);
				A = left_pq.top();
				left_pq.pop();
			}
			else if (left_pq.size() < right_pq.size()) {
				left_pq.push(A);
				A = right_pq.top();
				right_pq.pop();
			}
			answer = (answer + A) % MOD;
		}
		
		cout << "#" << test_case << ' ' << answer << '\n';
	}
	return 0;
}
