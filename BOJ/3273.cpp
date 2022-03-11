#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X;
vector<int> numbers;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	numbers.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	cin >> X;

	int ans = 0;
	int left = 0, right = N - 1;

	sort(numbers.begin(), numbers.end());

	while (left < right) {
		int sum = numbers[left] + numbers[right];

		if (sum == X) {
			left++;
			right--;
			ans++;
		}
		else if (sum < X) 
			left++;
		else 
			right--;
	}

	cout << ans << '\n';

	return 0;
}
