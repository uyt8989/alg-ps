int child[100][5];
int child_cnt[100];

void dfs_init(int N, int path[100][2])
{
	for (int i = 0; i < 100; i++) {
		child_cnt[i] = 0;
		for (int j = 0; j < 5; j++) {
			child[i][j] = 0;
		}
	}
	
	int p, c;
	for (int i = 0; i < N - 1; i++) {
		p = path[i][0]; c = path[i][1];
		child[p][child_cnt[p]++] = c;
	}

}

int find(int king, int n) {
	int ret = -1;

	for (int i = 0; i < child_cnt[n]; i++) {
		if (child[n][i] != 0) {
			if (child[n][i] > king) return child[n][i];
			ret = find(king, child[n][i]);
			if (ret > king) return ret;
		}
	}

	return ret;
}

int dfs(int n)
{
	return find(n, n);
}
