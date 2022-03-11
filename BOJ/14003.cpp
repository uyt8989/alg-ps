#include <iostream>
#include <vector>

#define MAX 1000010

using namespace std;

int N;
int input[MAX], idx[MAX];
vector<int> LIS, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cin >> input[0];
	LIS.push_back(input[0]);
	idx[0] = 0;

	for (int i = 1; i < N; i++) {
		cin >> input[i];

		if (input[i] > LIS.back()) {
			LIS.push_back(input[i]);
			idx[i] = (LIS.size() - 1);
		}
		else {
			vector<int>::iterator iter = lower_bound(LIS.begin(), LIS.end(), input[i]);
			*iter = input[i];
			idx[i] = (iter - LIS.begin());
		}
	}

	int size = LIS.size();
	cout << size << '\n';
	
	int cur = size - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (cur == idx[i]) {
			ans.push_back(input[i]);
			cur--;
		}
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}

	cout << '\n';

	return 0;
}
