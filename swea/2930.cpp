#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;

int N;
//priority_queue<int> pq;
int heap[MAX];
int heap_size;

void push(int x) {
	int cur = heap_size;
	heap[heap_size] = x;

	while (cur > 1 && heap[cur] > heap[cur/2]) {
		int temp = heap[cur];
		heap[cur] = heap[cur / 2];
		heap[cur / 2] = temp;
		cur = cur >> 1;
	}

	heap_size++;
}

int pop() {
	int ret = heap[1];
	int cur = 1;

	heap_size--;
	heap[1] = heap[heap_size];

	while (2 * cur < heap_size) {
		int child;

		if (2 * cur + 1 == heap_size) 
			child = 2 * cur;
		else
			child = heap[2 * cur] > heap[2 * cur + 1] ? 2 * cur : 2 * cur + 1;

		if (heap[cur] > heap[child]) break;

		int temp = heap[cur];
		heap[cur] = heap[child];
		heap[child] = temp;
		cur = child;
	}

	return ret;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		heap_size = 1;

		cout << "#" << test_case << ' ';

		int cmd;
		for (int i = 0; i < N; i++) {
			cin >> cmd;

			switch (cmd) {
			case 1:
				int x;
				cin >> x;
				push(x);
				break;
			case 2:
				if (heap_size <= 1) {
					cout << -1 << ' ';
				}

				else {
					cout << pop() << ' ';
				}
				break;
			}
		}

		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}