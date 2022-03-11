#include <iostream>

using namespace std;

int N;
int inorder[100000], postorder[100000], idx[100001];

void printPreorder(int iStart, int iEnd, int pStart, int pEnd) {
	if (iStart > iEnd || pStart > pEnd) return;

	int rIdx = idx[postorder[pEnd]];
	cout << inorder[rIdx] << " ";

	printPreorder(iStart, rIdx - 1, pStart, pStart + rIdx - iStart - 1);
	printPreorder(rIdx + 1, iEnd, pStart + rIdx - iStart, pEnd - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inorder[i];
		idx[inorder[i]] = i;
	}

	for (int i = 0; i < N; i++) cin >> postorder[i];

	printPreorder(0, N - 1, 0, N - 1);

	return 0;
}
