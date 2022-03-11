#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int N, r, c;

int func(int size, int srow, int scol) {
	if (size == 2) {
		if (srow == r && scol == c) {
			printf("%d\n", count); 
			return 0;
		}
		else if (srow == r && (scol + 1) == c) {
			printf("%d\n", count + 1);
			return 0;
		}
		else if ((srow + 1) == r && scol == c) {
			printf("%d\n", count + 2);
			return 0;
		}
		else if ((srow + 1) == r && (scol + 1) == c) {
			printf("%d\n", count + 3);
			return 0;
		}
		else count += 4;

		return 0;
	}

	int mrow = srow + size / 2, mcol = scol + size / 2;
	

	if(r < mrow && c < mcol) func(size/2, srow, scol);
	else if (r < mrow && c >= mcol) {
		count += (size/2)*(size/2);
		func(size / 2, srow, mcol);
		
	}
	else if (r >= mrow && c < mcol) {
		count += (size / 2) * (size / 2) * 2;
		func(size / 2, mrow, scol);
	}
	else {
		count += (size / 2) * (size / 2) * 3;
		func(size / 2, mrow, mcol);
	}

	return 0;
}

int main() {
	int size=1;

	scanf("%d %d %d", &N, &r, &c);
	
	for (int i = 0; i < N; i++) {
		size = size * 2;
	}

	func(size, 0, 0);

	return 0;
}
