#include <stdio.h>

int N;
char DNA[1000001] = { 0 , };
int A[1000001] = { 0 , };
int B[1000001] = { 0 , };

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int main(){
	scanf("%d", &N);
	scanf("\n");
	for (int i = 1; i <= N; i++)
		scanf("%c", &DNA[i]);

	for (int i = 1; i <= N; i++) {
		if (DNA[i] == 'A') {
			if (A[i - 1] <= B[i - 1]) {
				A[i] = A[i - 1];
				B[i] = A[i - 1] + 1;
			}
			else {
				A[i] = B[i] = B[i - 1] + 1;
			}
		}
		else {//DNA[i] == 'B'
			if (A[i - 1] < B[i - 1]) {
				A[i] = B[i] = A[i - 1] + 1;
			}
			else {
				A[i] = B[i - 1] + 1;
				B[i] = B[i - 1];
			}
		}
	}

	printf("%d\n", A[N]);

	return 0;
}
