#include <stdio.h>
#include <stdlib.h>

int N;
int S[21][21];
int team[21];
int min = 987654321;


int MIN(int a, int b) {
	if (a < b) return a;
	return b;
}

void make_team(int idx, int team1, int team2) {
	int team_S[3];
	
	if (idx == N) {
		team_S[1] = 0;
		team_S[2] = 0;
		for (int t = 1; t <= 2; t++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (team[i] == t && team[j] == t) {
						team_S[t] += S[i][j];
					}
				}
			}
		}

		min = MIN(min, abs(team_S[1] - team_S[2]));

		return;
	}

	if (team1 < N / 2) {
		team[idx + 1] = 1;
		make_team(idx + 1, team1 + 1, team2);
	}
	if (team2 < N / 2) {
		team[idx + 1] = 2;
		make_team(idx + 1, team1, team2 + 1);
	}

	return;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &S[i][j]);

	make_team(0, 0, 0);

	printf("%d\n", min);

	return 0;
}
