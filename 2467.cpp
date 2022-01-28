#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

int N;
int liquid[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> liquid[i];
	}

	int left = 0;
	int right = N - 1;
	int min = INT_MAX;
	int x = liquid[left];
	int y = liquid[right];

	while (left < right) {
		if (abs(liquid[left] + liquid[right]) < min) {
			min = abs(liquid[left] + liquid[right]);
			x = liquid[left];
			y = liquid[right];
		}

		if (liquid[left] + liquid[right] < 0) {
			left++;
		}
		else {
			right--;
		}

	}

	cout << x << ' ' << y << '\n';

	return 0;
}
