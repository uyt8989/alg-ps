#include <iostream>
#include <cstring>

using namespace std;

typedef struct _Gear {
	int pole[8];
} Gear;

Gear gear[4];
int K, n, d;
char c;

void rotateGear(int idx, int dir) {
	if (dir == 1) {
		int temp = gear[idx].pole[7];
		for (int i = 7; i > 0; i--) {
			gear[idx].pole[i] = gear[idx].pole[i - 1];
		}
		gear[idx].pole[0] = temp;
	}
	else {
		int temp = gear[idx].pole[0];
		for (int i = 0; i < 7; i++) {
			gear[idx].pole[i] = gear[idx].pole[i + 1];
		}
		gear[idx].pole[7] = temp;
	}
}

int getScore() {
	int ret = 0;

	for (int i = 0; i < 4; i++)
		if (gear[i].pole[0] == 1) ret += (1 << i);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> c;
			gear[i].pole[j] = c - '0';
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> n >> d;

		rotateGear(n - 1, d);

		//오른쪽 방향
		int temp = d;
		for (int j = n - 1; j < 3; j++) {
			if (gear[j].pole[2 + temp] != gear[j + 1].pole[6]) {
				temp = -temp;
				rotateGear(j + 1, temp);
			}
			else break;
		}
		
		//왼쪽 방향
		temp = d;
		for (int j = n - 1; j > 0; j--) {
			if (gear[j].pole[6 + temp] != gear[j - 1].pole[2]) {
				temp = -temp;
				rotateGear(j - 1, temp);
			}
			else break;
		}
	}

	cout << getScore() << "\n";

	return 0;
}
