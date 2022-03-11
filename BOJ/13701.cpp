#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int check[1 << 20];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int A;
	while (cin >> A) {
		int x = A >> 5;
		int y = 1 << (A & 31);

		if (!(check[x] & y)) {
			check[x] = check[x] | y;
			cout << A << " ";
		}
	}

	return 0;
}
