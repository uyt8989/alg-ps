#include <iostream>

using namespace std;

int N;
char str[201];
char operand[4] = { '+', '-', '/', '*' };

int check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 4; j++) {
			if (str[i] == operand[j]) {
				if (2 * i + 1 > N) return 0;
			}
		}
	}

	return 1;
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
		cin >> N; 

		int num, lc, rc;
		char data;
		for (int i = 1; i <= N; i++) {
			cin >> num >> data;

			str[num] = data;


			if (2 * num <= N) cin >> lc;
			if (2 * num + 1 <= N) cin >> rc;
		}
		

		cout << '#' << test_case << ' ' << check() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}