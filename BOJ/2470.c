#include <stdio.h>
#include <stdlib.h>

#define INF 2087654321

int N;
int solution[100000];
int min = INF;
int i, j;
int idx1, idx2;

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환

    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환

    return 0;    // a와 b가 같을 때는 0 반환
}

int main() {
	scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &solution[i]);
    }

    qsort(solution, N, sizeof(int), compare);

    i = 0; 
    j = N - 1;

    while (i < j) {
        int sum = solution[i] + solution[j];

        if (abs(sum) < min) {
            min = abs(sum);
            idx1 = i;
            idx2 = j;
        }
        if (sum < 0) i++;
        else j--;
    }

    printf("%d %d", solution[idx1], solution[idx2]);

	return 0;
}
