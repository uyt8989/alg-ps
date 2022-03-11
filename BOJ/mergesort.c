#include <stdio.h>

int merge(int arr[], int low, int mid, int high) {
	int i = low, j = mid + 1, k = low;
	int temp[8] = { 0, };

	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= high) temp[k++] = arr[j++];
	for (int a = low; a <= high; a++) arr[a] = temp[a];

	return 0;
}

int mergesort(int arr[], int low, int high) {
	int mid = (low + high) / 2;
	if (low < high) {
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}

	return 0;
}

int main() {
	int arr[8] = { 27, 10, 12, 20, 25, 13, 15, 22 };
	
	printf("정렬 전 : ");
	for (int i = 0; i < 8; i++) {
		printf("%d ", arr[i]);
	}
	
	mergesort(arr, 0, 7);

	printf("\n정렬 후 : ");
	for (int i = 0; i < 8; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
