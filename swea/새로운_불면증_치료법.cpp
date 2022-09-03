#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, ten = 1;
		int check = 0;
		int cur = 0, digit;

		cin >> N;

		cur = N;
		while (check != (1 << 10) - 1) {
			ten = 1;
			while (ten <= cur) {
				digit = (cur % (ten * 10) - cur % ten) / ten;
				check |= (1 << digit);
				ten *= 10;
			}
			cur += N;
		}

		printf("#%d %d\n", test_case, cur - N);
	}
	return 0;
}
