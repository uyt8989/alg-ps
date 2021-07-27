#include <stdio.h>
#include <string.h>

int N;
char nums[11][9];
int alpabet[26] = { 0 , };
int p[26] = { 0 , };

void priority() {
	int digit, max, max_index;

	for (int i = 0; i < N; i++) {
		digit = 1;
		for (int k = strlen(nums[i]) - 1; k >= 0; k--) {
			p[nums[i][k] - 'A'] += digit;
			digit *= 10;
		}
	}

	for (int i = 0; i < 10; i++) {
		max = p[0];
		max_index = 0;
		for (int j = 0; j < 26; j++) {
			if (p[j] > max) {
				max = p[j];
				max_index = j;
			}
		}
		if (!alpabet[max_index]) {
			alpabet[max_index] = 9 - i;
			p[max_index] = 0;
		}
	}
}

int calc(int i, int len) {
	int result = 0;
	int digit = 1;

	for (int k = len - 1; k >= 0; k--) {
		result += alpabet[nums[i][k] - 'A'] * digit;
		digit *= 10;
	}
	return result;
}

int main() {
	int result = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", nums[i]);

	priority();
	
	for (int i = 0; i < N; i++) 
		result += calc(i, strlen(nums[i]));
	printf("%d\n", result);

	return 0;
}
