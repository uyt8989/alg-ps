#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, A;
vector<int> LIS;
int answer;

int main() {
	scanf("%d", &N);

	LIS.push_back(0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A);

		if (A > LIS.back()) {
			LIS.push_back(A);
			answer++;
		}
		else {
			vector<int>::iterator iter = lower_bound(LIS.begin(), LIS.end(), A);
			*iter = A;
		}
	}

	printf("%d\n", answer);

	return 0;
}
