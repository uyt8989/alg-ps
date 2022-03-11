#include <iostream>
#include <map>

using namespace std;

int N, S;
long long ans;
int numbers[40];
map<int, int> m;

void Left(int idx, int sum) {
	if (idx == N / 2) {
		m[sum]++;
		return;
	}
	Left(idx + 1, sum);
	Left(idx + 1, sum + numbers[idx]);
}

void Right(int idx, int sum) {
	if (idx == N) {
		ans += m[S - sum];
		return;
	}
	Right(idx + 1, sum);
	Right(idx + 1, sum + numbers[idx]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	Left(0, 0);
	Right(N / 2, 0);

	if (S == 0) cout << ans - 1;
	else cout << ans;

	return 0;
}
