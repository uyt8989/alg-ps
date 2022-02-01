#include <iostream>
#include <tuple>
#include <algorithm>
#include <stack>

#define MAX 50001

using namespace std;

int N, M, K;
int arr[51][51];
tuple<int, int, int> R[7];
int answer = MAX;

void rotateArr(int r, int s, int c) {
	int i, x, y;
	int temp1, temp2;

	temp1 = arr[r - c][s + c];
	for (i = 0, 
		x = r - c, 
		y = s + c;
		i < 2 * c; i++, y--) {
		arr[x][y] = arr[x][y - 1];
	}

	temp2 = arr[r + c][s + c];
	for (i = 0,
		x = r + c,
		y = s + c;
		i < 2 * c - 1; i++, x--) {
		arr[x][y] = arr[x - 1][y];
	}
	arr[r - c + 1][s + c] = temp1;

	temp1 = arr[r + c][s - c];
	for (i = 0,
		x = r + c,
		y = s - c;
		i < 2 * c - 1; i++, y++) {
		arr[x][y] = arr[x][y + 1];
	}
	arr[r + c][s + c - 1] = temp2;

	for (i = 0,
		x = r - c,
		y = s - c;
		i < 2 * c - 1; i++, x++) {
		arr[x][y] = arr[x+1][y];
	}
	arr[r + c - 1][s - c] = temp1;
}

int getValue() {
	int ans = MAX;

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += arr[i][j];
		}
		ans = min(ans, sum);
	}

	return ans;
}

void makeOrder(int i, int used) {
	int temp[51][51];
	
	if (i == K) {
		answer = min(answer, getValue());
	}

	else {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		for (int k = 0; k < K; k++) {
			if ((used & (1 << k)) == 0) {
				for (int t = get<2>(R[k]); t > 0; t--) {
					rotateArr(get<0>(R[k]), get<1>(R[k]), t);
				}

				makeOrder(i + 1, (used | (1 << k)));

				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= M; j++) {
						arr[i][j] = temp[i][j];
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	int r, s, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> s >> c;
		R[i] = { r, s, c };
	}

	makeOrder(0, 0);

	cout << answer << '\n';
	
	return 0;
}
