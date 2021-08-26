#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Arr {
	int data;
	int idx;
}Arr;

int N;
Arr a[500001];
Arr sorted[500001];

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int compare(const void* a, const void* b) {
	Arr num1 = *(Arr*)a;   
	Arr num2 = *(Arr*)b;
	if (num1.data < num2.data)  
		return -1;     
	if (num1.data > num2.data)    
		return 1;
	return num1.idx - num2.idx;   
}

int binary_search(int key, int idx) {
	int start = 1;
	int end = N;
	int mid;
	while (1) {
		mid = (start + end) / 2;
		if (sorted[mid].data < key)
			start = mid + 1;
		else if (sorted[mid].data > key)
			end = mid - 1;
		else {
			if (sorted[mid].idx < idx)
				start = mid + 1;
			else if (sorted[mid].idx > idx)
				end = mid - 1;
			else
				break;
		}
	}

	return mid;
}


int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i].data);
		a[i].idx = i;
		sorted[i].data = a[i].data;
		sorted[i].idx = i;
	}
	
	qsort(sorted, N+1, sizeof(Arr), compare);

	int ans = 0;
	int sorted_idx;
	for (int i = 1; i <= N; i++) {
		sorted_idx = binary_search(a[i].data, i);
		if (sorted_idx < i) ans = MAX(ans, i - sorted_idx);
	}
	printf("%d\n", ans + 1);

	return 0;
}
