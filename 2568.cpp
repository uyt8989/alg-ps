#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define MAX 500010

using namespace std;

int N;
vector<pair<int, int>> connect;
vector<int> LIS, idx, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int A, B;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		connect.push_back({ A, B });
	}

	sort(connect.begin(), connect.end());

	LIS.push_back(connect[0].second);
	idx.push_back(0);

	for(int i = 1; i < N; i++) {
		int cur = connect[i].second;

		//선을 자르지 않아도 됨
		if (LIS.back() < cur) {
			idx.push_back(LIS.size());
			LIS.push_back(cur);
		}
		//선을 잘라야 함
		else {
			vector<int>::iterator iter = lower_bound(LIS.begin(), LIS.end(), cur);
			*iter = cur;
			idx.push_back(iter - LIS.begin());
		}
	}

	cout << N - LIS.size() << '\n';

	//LIS의 뒤에서부터
	//인덱스가 맞지 않는 경우엔 잘린 선
	int cur = LIS.size() - 1;
	for (int i = idx.size() - 1; i >= 0; i--) {
		if (cur == idx[i]) cur--;
		else ans.push_back(connect[i].first);
	}

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << "\n";

	return 0;
}
