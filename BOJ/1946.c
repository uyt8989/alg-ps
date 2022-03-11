#include <stdio.h>

int main() {
	int T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		int apc[100001];
		int doc, itv;
		int count = 0;
		int cut;

		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d %d", &doc, &itv);
			apc[doc] = itv;
		}

		cut = 1;
		for (int i = 2; i <= N; i++) {
			if (apc[i] < apc[cut]) {
				count++;
				cut = i;
			}
			if (apc[i] == 1) break;
		}
		printf("%d\n", count + 1);
	}

	return 0;
}