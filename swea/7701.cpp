#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> str;
vector<string> sorted;

bool cmp(string A, string B) {
	if (A.length() < B.length())
		return true;
	else if (A.length() == B.length())
		return A < B;
	else if (A.length() > B.length())
		return false;
}

void merge(int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int k = l;

	while (i <= m && j <= r) {
		if (str[i].compare(str[j]) <= 0)
			sorted[k++] = str[i++];
		else
			sorted[k++] = str[j++];
	}

	if (i > m) {
		while (j <= r) {
			sorted[k++] = str[j++];
		}
	}
	else {
		while (i <= m) {
			sorted[k++] = str[i++];
		}
	}

	for (int t = l; t <= r; t++) {
		str[t] = sorted[t];
	}

	return;
}

void msort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;

		msort(l, m);
		msort(m + 1, r);
		merge(l, m, r);
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		str.resize(N);
		sorted.resize(N);

		for (int i = 0; i < N; i++)
			cin >> str[i];

		//msort(0, N - 1);
		sort(str.begin(), .end(), cmp);

		cout << "#" << test_case << "\n";
		cout << str[0] << '\n';
		for (int i = 1; i < N; i++) {
			if (str[i - 1] != str[i])
				cout << str[i] << "\n";
		}
	}
	return 0;
}