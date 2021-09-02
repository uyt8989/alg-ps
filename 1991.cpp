#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
	T value;
	Node* left;
	Node* right;
	Node* root;

public:
	Node() : value(0), left(nullptr), right(nullptr), root(nullptr) {};
	Node(T _value) :value(_value), right(nullptr), root(nullptr) {};
	Node(T _value, Node* _left, Node* _right) :
	value(_value), left(_left), right(_right), root(nullptr) {
		if (nullptr != _left) 
			_left->root = this; 
		if (nullptr != _right) 
			_right->root = this;
	};

	~Node() {};
	
	void SetLeft(Node* node) { this->left = node; }
	void SetRight(Node* node) { this->right = node; }
	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
	T GetValue() { return value; }
};

template <typename T>
void preorder(Node<T>* node) {
	if (node == nullptr)
		return;
	
	cout << node->GetValue();
	preorder(node->GetLeft());
	preorder(node->GetRight());
}

template <typename T>
void inorder(Node<T>* node) {
	if (node == nullptr)
		return;

	inorder(node->GetLeft());
	cout << node->GetValue();
	inorder(node->GetRight());
}

template <typename T>
void postorder(Node<T>* node) {
	if (node == nullptr)
		return;
	
	postorder(node->GetLeft());
	postorder(node->GetRight());
	cout << node->GetValue();
}

int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Node<char>* node[26];

	cin >> N;
	for (int i = 0; i < N; i++)
		node[i] = new Node<char>('A' + i);


	char P, L, R;
	for (int i = 0; i < N; i++) {
		cin >> P >> L >> R;
		if (L != '.')
			node[P - 'A']->SetLeft(node[L - 'A']);
		if (R != '.')
			node[P - 'A']->SetRight(node[R - 'A']);
	}

	preorder(node[0]);
	cout << endl;
	inorder(node[0]);
	cout << endl;
	postorder(node[0]);
	cout << endl;


	return 0;
}
