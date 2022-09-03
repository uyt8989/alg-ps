#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int test_case;
	int T;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		scanf("%d %d", &N, &M);

		int mask = (1 << N) - 1;

		int res = M & mask;
		res ^= mask;

		printf("#%d ", test_case);
		if (res == 0) printf("ON\n");
		else printf("OFF\n");
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
