#include <stdio.h>

#define True 1
#define False 0
#define MAX_SCHEDULE 10

int deadline[MAX_SCHEDULE] = { 0, 3, 1, 1, 3, 1, 3, 2 };
int profit[MAX_SCHEDULE] = { 0, 40, 35, 30, 25, 20, 15, 10 };
int J[MAX_SCHEDULE] = { 0, };
int lenJ = 0;

int feasible(int K[],int lenK) {
	for (int i = 1; i < lenK + 1; i++) {
		if (i > deadline[K[i - 1]])
			return False;
	}
	return True;
}

int insert(int K[], int i) {
	int lenK = 0;
	int j;

	for (int k = 0; k < lenJ; k++)
		K[k] = J[k];
	
	lenK = lenJ;

	for (j = lenJ; j > 0; j--) {
		if (deadline[i] >= deadline[K[j - 1]]) {
			j++;
			break;
		}
	}

	int y = 0;
	if (j - 1 < 0) j = 1;

	for (int x = 0; x < lenJ + 1; x++) {
		if (x == j - 1) K[x] = i;
		else K[x] = J[y++];
	}
	lenK++;

	return lenK;
}

void schedule() {
	int n = 7;
	
	J[0] = 1;
	lenJ++;

	for (int i = 2; i < n + 1; i++) {
		int K[MAX_SCHEDULE] = { 0, };
		int lenK = 0;
		lenK = insert(K, i);

		printf("K = ");
		for (int j = 0; j < lenK; j++)
			printf("%d ", K[j]);

		if (feasible(K, lenK)) {
			printf("feasible");
			for (int j = 0; j < lenK; j++)
				J[j] = K[j];
			lenJ = lenK;
		}
		else
			printf("not feasible");
		
		printf("\tJ = ");
		for (int j = 0; j < lenJ; j++)
			printf("%d ", J[j]);
		printf("\n");
	}
}

int main() {
	int maxprofit = 0;

	schedule();

	for (int i = 0; i < lenJ; i++)
		maxprofit += profit[J[i]];

	printf("Schedule : ");
	for (int i = 0; i < lenJ; i++)
		printf("%d ", J[i]);
	printf("\n");

	printf("%d\n", maxprofit);

	return 0;
}