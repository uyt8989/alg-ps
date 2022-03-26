#include <iostream>
#include <algorithm>

using namespace std;

int N, total, ans = 987654321;
int ppl[21][21];

int getDiff(int x, int y, int d1, int d2) {
	int sec[5] = { 0, };

	for (int r = 1; r <= N; r++) for (int c = 1; c <= N; c++) {
		if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) 
			sec[0] += ppl[r][c];
		else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) 
			sec[1] += ppl[r][c];
		else if (r >= x + d1 && c < y - d1 + d2 && 
			!(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) 
			sec[2] += ppl[r][c];
		else if (r > x + d2 && c >= y - d1 + d2 && 
			!(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) 
			sec[3] += ppl[r][c];
		else 
			sec[4] += ppl[r][c];
	}
	sort(sec, sec + 5);

	return sec[4] - sec[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int r = 1; r <= N; r++) for (int c = 1; c <= N; c++) 
		cin >> ppl[r][c];

	for (int d1 = 1; d1 <= N; d1++) {
		for (int d2 = 1; d2 <= N; d2++) {
			for (int x = 1; x <= N - d1 - d2; x++) {
				for (int y = 1 + d1; y <= N - d2; y++) {
					ans = min(ans, getDiff(x, y, d1, d2));
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
