#include <iostream>

#define ll long long

ll x1, _y1, x2, y2, x3, y3, x4, y4;

int CCW(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll temp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (temp < 0) return -1;
	else if (temp > 0) return 1;
	return 0;
}

int isCross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	if (CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4) <= 0 &&
		CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2) <= 0) {
		if ((x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) ||
			(x3 > x1 && x3 > x2 && x4 > x1 && x4 > x2)) return 0;
		else if ((y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) ||
			(y3 > y1 && y3 > y2 && y4 > y1 && y4 > y2)) return 0;
		return 1;
	}

	return 0;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> x1 >> _y1 >> x2 >> y2;
	std::cin >> x3 >> y3 >> x4 >> y4;

	std::cout << isCross(x1, _y1, x2, y2, x3, y3, x4, y4) << '\n';

	return 0;
}
