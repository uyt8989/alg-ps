#include <stdio.h>
#define SWAP(a,b) {int t; t=a; a=b; b=t;}

int partition(int arr[], int low, int high) {
	int pivotitem = arr[low], i = low + 1, j = high;

	while (i <= j) {
		while (arr[i] < pivotitem) i++;
		while (arr[j] > pivotitem) j--;
		if (i < j) SWAP(arr[i], arr[j]);
	}
	SWAP(arr[low], arr[j]);

	return j;
}

int quicksort(int arr[], int low, int high) {
	int pivotpoint;
	if (low < high) {
		pivotpoint = partition(arr, low, high);
		quicksort(arr, low, pivotpoint - 1);
		quicksort(arr, pivotpoint + 1, high);
	}

	return 0;
}

int main() {
	int arr[10] = { 26, 5, 37, 1, 61, 11, 59, 15, 48 ,19 };

	printf("정렬 전 : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	quicksort(arr, 0, 9);

	printf("\n정렬 후 : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
