#include <iostream>
#include <string.h>
#include <limits.h>

#define MAX_LEN 2502

using namespace std;

int N;
char input[MAX_LEN];
bool isPal[MAX_LEN][MAX_LEN];
int DP[MAX_LEN];

void makePal() {
	for (int i = 1; i <= N; i++) {
		isPal[i][i] = true;
	}

	for (int i = 1; i < N; i++) {
		if (input[i] == input[i + 1]) isPal[i][i + 1] = true;
	}

	for (int l = 3; l <= N; l++) {
		for (int i = 1; i + l <= N + 1; i++) {
			int e = i + l - 1;
			if (input[i] == input[e] && isPal[i + 1][e - 1]) 
				isPal[i][e] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input + 1;

	N = strlen(input + 1);

	makePal();

	for (int i = 1; i <= N; i++) {
		DP[i] = INT_MAX - 1;
		for (int j = 1; j <= i; j++) {
			if (isPal[j][i]) {
				DP[i] = min(DP[i], DP[j - 1] + 1);
			}
		}
	}

	cout << DP[N];

	return 0;
}
