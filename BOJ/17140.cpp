#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int r, c, k;
int arr[MAX][MAX], temp[MAX][MAX], cnt[MAX];
vector<pair<int, int>> list;
int rows, cols;

bool check(int arr[][101]) {
	if (arr[r][c] == k) return true;
	return false;
}

void R() {
	int maxCol = 0;
	memset(temp, 0, sizeof(temp));

	//모든 행
	for (int i = 1; i <= rows; i++) {
		memset(cnt, 0, sizeof(cnt));
		list.clear();

		for (int j = 1; j <= cols; j++) {
			cnt[arr[i][j]]++;
		}
		for (int j = 1; j < MAX; j++) {
			if (cnt[j] == 0) continue;
			list.push_back({ cnt[j], j });
		}

		sort(list.begin(), list.end());

		int size = list.size();

		maxCol = max(maxCol , size * 2 + 1);

		int idx = 1;
		for (int j = 0; j < size; j++) {
			temp[i][idx++] = list[j].second;
			temp[i][idx++] = list[j].first;
		}
	}

	memcpy(arr, temp, sizeof(arr));
	cols = maxCol;
}

void C() {
	int maxRow = 0;
	memset(temp, 0, sizeof(temp));

	//모든 열
	for (int j = 1; j <= cols; j++) {
		memset(cnt, 0, sizeof(cnt));
		list.clear();

		for (int i = 1; i <= rows; i++) {
			cnt[arr[i][j]]++;
		}
		for (int i = 1; i < MAX; i++) {
			if (cnt[i] == 0) continue;
			list.push_back({ cnt[i], i });
		}

		sort(list.begin(), list.end());

		int size = list.size();

		maxRow = max(maxRow, size * 2 + 1);

		int idx = 1;
		for (int i = 0; i < size; i++) {
			temp[idx++][j] = list[i].second;
			temp[idx++][j] = list[i].first;
		}
	}

	memcpy(arr, temp, sizeof(arr));
	rows = maxRow;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) 
			cin >> arr[i][j];
	
	rows = 3; cols = 3;

	for (int i = 0; i <= 100; i++) {
		if (check(arr)) {
			cout << i <<"\n";
			return 0;
		}

		if (rows >= cols) R();
		else C();
	}
	
	cout << "-1\n";

	return 0;
}
