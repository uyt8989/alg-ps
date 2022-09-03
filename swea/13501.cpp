#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

#define MAX_NODES 3000

using namespace std;

typedef struct _Node {
	int data;
	_Node* next;
}Node;

int nodeCnt;
Node node[MAX_NODES];
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init() {
	nodeCnt = 0;
	head = getNode(-1);
}

void make_list(int N, int arr[]) {
	Node* t = head;
	for (int i = 0; i < N; i++) {
		Node* new_node = getNode(arr[i]);
 		t->next = new_node;
		t = new_node;
	}
}

Node* find_node(int x) {
	Node* t = head->next;
	for (int i = 0; i < x - 1; i++) {
		t = t->next;
	}
	return t;
}

void Insert(int x, int data) {
	Node *t = find_node(x);
	Node *new_node = getNode(data);

	new_node->next = t->next;
	t->next = new_node;
}

void Delete(int x) { 
	Node* t = find_node(x);

	t->next = t->next->next;
}

void Change(int x, int data) {
	Node* t = find_node(x);
	t->next->data = data;
}

void answer(int tc, int L) {
	Node* t = head->next;

	printf("#%d ", tc);
	
	for (int i = 0; i < L; i++) {
		if (t == nullptr) {
			printf("-1\n");
			return;
		}
		t = t->next;
	}

	printf("%d\n", t->data);
	return;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M, L, a, b;
		int arr[1000] = { 0, };
		char cmd;

		init();

		scanf("%d %d %d", &N, &M, &L);

		for (int i = 0; i < N; i++)
			cin >> arr[i];
		make_list(N, arr);

		for (int i = 0; i < M; i++) {
			cin >> cmd;

			switch (cmd) {
			case 'I':
				scanf("%d %d", &a, &b);
				Insert(a, b);
				break;
			case 'D':
				scanf("%d", &a);
				Delete(a);
				break;
			case 'C':
				scanf("%d %d", &a, &b);
				Change(a, b);
				break;
			}
		}

		answer(test_case, L);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
