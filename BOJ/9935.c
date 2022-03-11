#include <stdio.h>
#include <string.h>

char str[1000001];
char EOD[1000001];
char bomb[37];

int main() {
	scanf("%s", str);
	scanf("%s", bomb);

	int idx = 0;
	int str_len = strlen(str);
	int bomb_len = strlen(bomb);

	for (int i = 0; i < str_len; i++) {
		EOD[idx++] = str[i];
		int bomb_idx = bomb_len -1;
		if (str[i] == bomb[bomb_idx]) {
			int flag = 1;
			int size = idx - bomb_len;
			for (int k = idx - 1; k >= size; k--)
				if (EOD[k] != bomb[bomb_idx--]) {
					flag = 0;
					break;
				}
			if (flag) idx -= bomb_len;
		}
	}

	if (!idx) printf("FRULA\n");
	else {
		for (int i = 0; i < idx; i++)
			printf("%c", EOD[i]);
		printf("\n");
	}

	return 0;
}
