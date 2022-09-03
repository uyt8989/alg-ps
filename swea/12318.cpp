#include <stdio.h>

typedef struct _Node {
    int x, y;
    int cnt;
}Node;

Node queue[101];
int front, rear;
int field[11][11];
int visit[11][11];
int size;

int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };

void push(int x, int y, int cnt) {
    queue[rear].x = x;
    queue[rear].y = y;
    queue[rear++].cnt = cnt;
}

Node pop() {
    return queue[front++];
}

bool in_bound(int x, int y) {
    return 0 < x && x <= size && 0 < y && y <= size;
}

void bfs_init(int map_size, int map[10][10]) {
    size = map_size;

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            field[i][j] = map[i-1][j-1];
        }
    }
}

int bfs(int y1, int x1, int y2, int x2) {
    int nx, ny;

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            visit[i][j] = false;
        }
    }

    front = rear = 0;

    push(x1, y1, 0);

    Node cur;
    while (front < rear) {
        cur = pop();

        for (int dir = 0; dir < 4; dir++) {
            nx = cur.x + next_x[dir];
            ny = cur.y + next_y[dir];

            if (in_bound(nx, ny)){
                if (field[nx][ny] != 1 && visit[nx][ny] != true) {
                    if (nx == x2 && ny  == y2) {
                        return cur.cnt + 1;
                    }
                    
                    push(nx, ny, cur.cnt + 1);
                    visit[nx][ny] = true;
                }
            }
        }
    }
    
    return -1;
}