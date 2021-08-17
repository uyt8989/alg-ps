#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate {
	int x, y;
}coordinate;

int N;
int sea[21][21];
int visit[21][21];
int survive_time = 0;
coordinate baby;
coordinate now;
int size = 2;
int xp = 0;

int next_x[4] = { -1, 0, 0, 1 };
int next_y[4] = { 0, -1, 1, 0 };

coordinate queue[500];
int front = 0, rear = 0;

void enqueue(int x, int y) {
	queue[rear].x = x;
	queue[rear++].y = y;
}

coordinate dequeue() {
	coordinate temp;
	temp.x = -1;
	temp.y = -1;

	if (front < rear)
		return queue[front++];
	return temp;
}

void init_queue() {
	front = 0; rear = 0;
}

int in_boundary(int x, int y) {
	if (x >= 1 && x <= N && y >= 1 && y <= N)
		return 1;
	return 0;
}

void init_visit(int x, int y) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			visit[i][j] = 0;
	visit[x][y] = 1;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &sea[i][j]);
			if (sea[i][j] == 9) {
				baby.x = i; baby.y = j;
			}
		}
	}

	enqueue(baby.x, baby.y);
	visit[baby.x][baby.y] = 1;


	while (front < rear) {
		now = dequeue();

		if (sea[now.x][now.y] != 0 && sea[now.x][now.y] < size) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (visit[now.x][now.y] == visit[i][j]) {
						if (now.x >= i && sea[i][j] != 0 && sea[i][j] < size) {
							//printf("change!\n");
							now.x = i;
							now.y = j;
							goto EXIT;
						}
					}
				}
			}
			EXIT:

			sea[baby.x][baby.y] = 0;
			sea[now.x][now.y] = 0;
			xp++;
			survive_time = survive_time + visit[now.x][now.y] - 1;
			baby.x = now.x; baby.y = now.y;
			sea[baby.x][baby.y] = 9;

			if (size == xp) {
				xp = 0;
				size++;
			}

			init_visit(baby.x, baby.y);
			init_queue();
		}

		int nx, ny;

		for (int i = 0; i < 4; i++) {
			nx = now.x + next_x[i];
			ny = now.y + next_y[i];

			if (in_boundary(nx, ny))
				if (sea[nx][ny] <= size && !visit[nx][ny]) {
					visit[nx][ny] = visit[now.x][now.y] + 1;

					enqueue(nx, ny);
				}
		}
	}

	printf("%d\n", survive_time);

	return 0;
}
