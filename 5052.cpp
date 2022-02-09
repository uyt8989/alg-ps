#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_INPUT 10000
#define MAX_LEN 11
#define MAX_NODE MAX_INPUT * MAX_LEN

using namespace std;

struct Trie {
	bool end;
	Trie* node[MAX_LEN];

	void insert(const char* s);
	bool check(const char* s);
};

int T, N, tries;
vector<string> input;
Trie TriePool[MAX_NODE];
Trie* root;

Trie* allocTrie() {
	Trie* newTrie = &TriePool[tries++];
	newTrie->end = false;
	for (int i = 0; i < MAX_LEN; i++)
		newTrie->node[i] = NULL;
	return newTrie;
}

void Trie::insert(const char* s) {
	if (!*s) {
		this->end = true;
		return;
	}

	int number = *s - '0';
	if (!node[number]) node[number] = allocTrie();
	node[number]->insert(s + 1);
}

bool Trie::check(const char* s) {
	if (!*s) {
		return true;
	}
	if (end) {
		
		return false;
	}
	return node[*s - '0']->check(s + 1);
}

void init() {
	tries = 0;
	root = allocTrie();
}

bool compare(string a, string b)
{
	return a.size() > b.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		bool flag = true;

		init();

		input.clear();

		cin >> N;

		string temp;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			input.push_back(temp);
			root->insert(temp.c_str());
		}

		sort(input.begin(), input.end(), compare);

		for (int i = 0; i < N; i++) {
			if (!root->check(input[i].c_str())) {
				flag = false;
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
