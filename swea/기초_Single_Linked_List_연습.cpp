#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = getNode(-1);
}

void addNode2Head(int data)
{
	Node* new_node = getNode(data);
	new_node->next = head->next;
	head->next = new_node;
}

void addNode2Tail(int data)
{
	Node* new_node = getNode(data);
	Node* t;
	for (t = head; t->next != nullptr; t = t->next);
	t->next = new_node;
}

void addNode2Num(int data, int num)
{
	Node* new_node = getNode(data);
	Node* t = head;
	for (int i = 1; i < num; i++)
		t = t->next;
	
	new_node->next = t->next;
	t->next = new_node;
}

void removeNode(int data)
{
	Node* t;
	for (t = head; t->next != nullptr; t = t->next) {
		if (t->next->data == data) {
			t->next = t->next->next;
			break;
		}
	}
}

int getList(int output[MAX_NODE])
{
	int idx = 0;
	for (Node* t = head; t->next != nullptr; t = t->next) {
		output[idx++] = t->next->data;
	}

	return idx;
}