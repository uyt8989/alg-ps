#include <stdio.h>

int T, n;
int selected[100001];
int get_team[100001];
int done[100001];

int root;
int next;
int team;

void init() {
	for (int i = 0; i <= n; i++) {
		selected[i] = 0;
		get_team[i] = 0;
		done[i] = 0;
	}
}

void DFS(int student) {
	get_team[student] = 1;
	next = selected[student];
	if (!get_team[next]) 
		DFS(next);
	
	else if (!done[next]) {
		for (int i = next; i != student; i = selected[i])
			team++;
		team++;
	}
	
	done[student] = 1;
}

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		 
		init();
		team = 0;

		for (int i = 1; i <= n; i++)
			scanf("%d", &selected[i]);

		for (int i = 1; i <= n; i++)
			if (!get_team[i])
				DFS(i);

		printf("%d\n", n - team);
	}

	return 0;
}
