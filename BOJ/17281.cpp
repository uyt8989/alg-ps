#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int inning[51][10], order[10];
int check;
int ans;

int calcScore() {
	bool base[4];
	int score = 0;
	int now = 1;

	for (int inn = 1; inn <= N; inn++) {
		int out = 0;
		memset(base, false, sizeof(base));

		while (out < 3) {
			switch (inning[inn][order[now]]) {
			case 0:
				out++;
				break;
			case 1:
				if (base[3] == true) score++;
				base[3] = base[2];
				base[2] = base[1];
				base[1] = true;
				break;
			case 2:
				if (base[3] == true) score++;
				if (base[2] == true) score++;
				base[3] = base[1];
				base[2] = true;
				base[1] = false;
				break;
			case 3:
				if (base[3] == true) score++;
				if (base[2] == true) score++;
				if (base[1] == true) score++;
				base[3] = true;
				base[2] = base[1] = false;
				break;
			case 4:
				score++;
				if (base[3] == true) score++;
				if (base[2] == true) score++;
				if (base[1] == true) score++;
				base[3] = base[2] = base[1] = false;
				break;
			}
			now = (now + 1) % 9;
			if (now == 0) now = 9;
		}
	}

	return score;
}

void makeOrder(int cur) {
	if (cur > 9) {
		int temp = calcScore();
		ans = max(ans, temp);
		return;
	}

	if (cur == 4) {
		makeOrder(cur + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if ((check & (1 << i)) == 0) {
				order[cur] = i;
				check = check | (1 << i);
				makeOrder(cur + 1);
				check = check & (~(1 << i));
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> inning[i][j];
		}
	}

	check = 0;
	check = check | (1 << 1);
	order[4] = 1;
	
	makeOrder(1);

	cout << ans;

	return 0;
}
