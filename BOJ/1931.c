#include <stdio.h>
#include <stdlib.h>

typedef struct Time {
	int start, end;
}Time;

int N;
Time arr[100001];
int ans = 0;
Time now;

int compare(const void* a, const void* b) {
	Time num1 = *(Time*)a;
	Time num2 = *(Time*)b;

	if (num1.end == num2.end)
		return num1.start - num2.start;

	return (num1.end) - (num2.end);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &arr[i].start, &arr[i].end);

	qsort(arr, N, sizeof(Time), compare);

	now = arr[0];
	for (int i = 1; i < N; i++) {
		if (now.end <= arr[i].start) {
			ans++;
			now = arr[i];
		}
	}

	printf("%d\n", ans + 1);
	return 0;
}
