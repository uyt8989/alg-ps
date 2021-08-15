#include <stdio.h>
#include <stdlib.h>

int L, C;
char c[15];
int include[15] = { 0, };

int compare(const void* first, const void* second) {
	if (*(char*)first > *(char*)second) return 1;
	else if (*(char*)first < *(char*)second) return -1;
	else return 0;
}

void pick_c(int i, int n) {
	if (n == L) {
		int vowels = 0;
		int consonants = 0;

		for (int j = 1; j <= C; j++) {
			if (include[j] == 1) {
				if (c[j] == 'a' || c[j] == 'e' || c[j] == 'i' || c[j] == 'o' || c[j] == 'u')
					vowels++;
				else
					consonants++;
			}
		}

		if (vowels >= 1 && consonants >= 2) {
			for (int j = 1; j <= C; j++)
				if (include[j] == 1)
					printf("%c", c[j]);
			printf("\n");
		}

		return ;
	}
	else if(i < C) {
		include[i + 1] = 1;
		pick_c(i + 1, n + 1);
		include[i + 1] = 0;
		pick_c(i + 1, n); 
	}

	return;
}

int main() {
	scanf("%d %d", &L, &C);

	for (int i = 1; i <= C; i++)
		scanf(" %c", &c[i]);

	qsort(c, C + 1, sizeof(char), compare);

	pick_c(0, 0);

	return 0;
}
