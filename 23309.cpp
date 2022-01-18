#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

#define MAX_STATIONS 1000001

typedef struct _Node {
	int num;
	_Node* prev;
	_Node* next;
}Node;

Node node[MAX_STATIONS];
int arr[MAX_STATIONS];
int nodeCnt;
Node* head;
int N, M;

Node* getNode(int number) {
	node[number].num = number;
	node[number].prev = node[nodeCnt].next = nullptr;
	return &node[number];
}

void init() {
	nodeCnt = 0;
	head = getNode(-1);
}

void make_list() {
	Node* t = head;
	for (int i = 0; i < N - 1; i++) {
		Node* new_node = getNode(arr[i]);
		new_node->prev = t;
		new_node->next = t->next;
		t->next = new_node;
		t = new_node;
	}

	Node* new_node = getNode(arr[N - 1]);
	
	new_node->prev = t;
	new_node->next = head;
	t->next = new_node;
	head->prev = new_node;
}

void BN(int i, int j) {
	Node* new_node = getNode(j);
	Node* t = &node[i];

	if (t->next == head)
		printf("%d\n", head->next->num);
	else printf("%d\n", t->next->num);

	new_node->prev = t;
	new_node->next = t->next;
	t->next->prev = new_node;
	t->next = new_node;
}

void BP(int i, int j) {
	Node* new_node = getNode(j);
	Node* t = &node[i];

	if (t->prev == head)
		printf("%d\n", head->prev->num);
	else printf("%d\n", t->prev->num);

	new_node->prev = t->prev;
	new_node->next = t;
	t->prev->next = new_node;
	t->prev = new_node;
}

void CN(int i) {
	Node* t = &node[i];

	if (t->next == head) {
		printf("%d\n", head->next->num);
		t = head;
	}
	else printf("%d\n", t->next->num);

	t->next->next->prev = t;
	t->next = t->next->next;
}

void CP(int i) {
	Node* t = &node[i];

	if (t->prev == head) {
		printf("%d\n", head->prev->num);
		t = head;
	}
		
	else printf("%d\n", t->prev->num);
	
	t->prev->prev->next = t;
	t->prev = t->prev->prev;
}

int main() {
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init();

	make_list();

	string cmd;
	for (int k = 0; k < M; k++) {
		cin >> cmd;

		int i, j;
		if (cmd == "BN") {
			cin >> i >> j;
			BN(i, j);
		}
		else if (cmd == "BP") {
			cin >> i >> j;
			BP(i, j);
		}
		else if (cmd == "CP") {
			cin >> i;
			CP(i);
		}
		else if (cmd == "CN") {
			cin >> i;
			CN(i);
		}
	}
	
	return 0;
}
