#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<pair<int, int>> s(16);

int DP(int day) {
	int a = 0, b = 0;

	if (day > N) return 0;

	a = DP(day + 1);
	
	if (day + s[day].first - 1 <= N)
		b = DP(day + s[day].first) + s[day].second;

	return max(a, b);
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) 
		scanf("%d %d", &s[i].first, &s[i].second);

	printf("%d\n", DP(1));

	return 0;
}
