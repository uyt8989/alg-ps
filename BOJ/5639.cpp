#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

typedef struct _Node {
	int n;
	_Node* left, * right;
} Node;

Node nodePool[10001]; int cnt;
Node* root;
int num;

Node* getNode() {
	Node* temp = &nodePool[cnt++];
	temp->n = 0;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

Node* insert(Node *cur, int n) {
	if (cur == NULL) {
		cur = getNode();
		cur->n = n;
		return cur;
	}
	
	if (n < cur->n) cur->left = insert(cur->left, n);
	else cur->right = insert(cur->right, n);

	return cur;
}

void postorder(Node* cur) {
	if (cur->left) postorder(cur->left);
	if (cur->right) postorder(cur->right);
	printf("%d\n", cur->n);
}

int main() {
	while (scanf("%d", &num) != EOF) {
		root = insert(root, num); 
	}

	postorder(root);
	
	return 0;
}
