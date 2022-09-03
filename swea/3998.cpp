#include<iostream>

using namespace std;

int A[100000];
int sorted[100000];
int index[100001];
long long cnt;

void merge(int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int k = l;

	while (i <= m && j <= r) {
		if (A[i] < A[j]) {
			sorted[k++] = A[i++];
		}
		else {
			cnt += m - i + 1;
			sorted[k++] = A[j++];
		}
	}

	while (i <= m) {
		sorted[k++] = A[i++];
	}

	while (j <= r) {
		sorted[k++] = A[j++];
	}

	for (int t = l; t <= r; t++)
		A[t] = sorted[t];
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
		int N;
		cin >> N; 

		cnt = 0;

		for (int i = 0; i < N; i++) {
			cin >> A[i];
			index[A[i]] = i;
		}

		msort(0, N-1);

		cout << '#' << test_case << ' ';
		cout << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}