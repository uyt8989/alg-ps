#include <iostream>

using namespace std;

long long A, B, C;
long long ans = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	while (B > 0) {
		if (B & 1) {
			ans = ans * A;
			ans = ans % C;
		}

		A = A * A;
		A = A % C;
		B = B >> 1;
	}

	cout << ans << "\n";

	return 0;
}
