#include <iostream>

using namespace std;

int N, B, C, temp;
long long ans;
int A[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> A[i];
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		temp = A[i] - B;
		if (temp) {
			ans += temp % C == 0 ? temp / C : temp / C + 1;
		}
	}

	cout << ans + N << "\n";

	return 0;
}
