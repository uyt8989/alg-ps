#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#define MAX_NODES 1000001

using namespace std;

typedef struct _Node {
	int data;
	_Node* next;
}Node;

Node node[MAX_NODES];
int nodeCnt;
Node* head;
Node* tail;
Node* mid;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init() {
	nodeCnt = 0;
	head = getNode(-1);
	tail = head;
}

void find_node(int idx) {
	Node* t = head;
	for (int i = 1; i < idx; i++)
		t = t->next;
	mid = t;
}

void push_back(int data) {
	Node* new_node = getNode(data);
	tail->next = new_node;
	tail = new_node;
}

void push_mid(int data) {
	Node* new_node = getNode(data);
	new_node->next = mid->next;
	mid->next = new_node;
	mid = new_node;
}

void delete_nodes(int num) {
	mid = mid->next;
	for (int i = 0; i < num; i++) {
		mid->next = mid->next->next;
	}
	//mid->next = t;
}

void print_ten() {
	Node* t = head;

	for (int i = 0; i < 10; i++) {
		printf("%d ", t->next->data);
		t = t->next;
	}

	printf("\n");
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, num;
		int x, y, s;
		char cmd;

		init();

		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			push_back(num);
		}

		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			cin >> cmd;

			switch (cmd) {
			case 'I': 
				scanf("%d %d", &x, &y);
				find_node(x);
				for (int j = 0; j < y; j++) {
					scanf("%d", &s);
					push_mid(s);
				}
				print_ten();
				
				break;
			case 'D': 
				scanf("%d %d", &x, &y);
				find_node(x);
				delete_nodes(y);
				print_ten();
				break;
			case 'A': 
				scanf("%d", &y);
				for (int j = 0; j < y; j++) {
					scanf("%d", &s);
					push_back(s);
				}
				print_ten();
				break;
			}
		}


		printf("#%d ", test_case);
		print_ten();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}