#include <string.h>
#include <stdio.h>

#define MAX_H 301
#define MAX_W 301

typedef struct _Node {
	char _c;
	_Node* prev, *next;
} Node;

Node NodePool[MAX_H * MAX_W + 2]; int nodeCnt;
Node *rStart[MAX_H];
int mCount[MAX_H][26], mLen[MAX_H], prevChar[26];
int nowRow, nowCol, H, W, Total;
Node* Cur;
Node* head, *tail;

void allocNode(Node* now, char c) {
	NodePool[nodeCnt]._c = c;
	Node* tmp = &NodePool[nodeCnt++];
	tmp->next = now->next; tmp->prev = now;
	now->next->prev = tmp; now->next = tmp;
	Total++;
}

void print() {

	for (int row = 1; mLen[row] != 0; row++) {
		printf("%d: ", row);
		Node* cur = rStart[row];
		for (int i = 0; i < mLen[row]; i++) {
			if (cur->next == tail) break;
			printf("%c ", cur->next->_c);
			cur = cur->next;
		}
		printf("\n");
	}
}

int start;
void init(int _H, int _W, char mStr[])
{
	if (start == 0) {
		head = new Node(); tail = new Node();
		start = 1;
	}

	nodeCnt = 0;
	nowRow = nowCol = 1;
	Total = 0;
	H = _H; W = _W;
	head->next = tail; tail->prev = head;
	Cur = head;
	memset(mCount, 0, sizeof(mCount));
	memset(mLen, 0, sizeof(mLen));
	memset(prevChar, 0, sizeof(prevChar));
	
	rStart[1] = head;

	Node* cur = head;
	for (int i = 1; mStr[i - 1] != 0; i++) {
		int Row = (i - 1) / W + 1;
		allocNode(cur, mStr[i - 1]);
		mCount[Row][mStr[i - 1] - 'a']++;
		mLen[Row]++;
		cur = cur->next;
		if (i % W == 0) {
			rStart[Row + 1] = cur;
		}
	}

	//print();
}

void insert(char mChar)
{
	allocNode(Cur, mChar);
	mCount[nowRow][mChar - 'a']++;
	mLen[nowRow]++;
	prevChar[mChar - 'a']++;

	for (int i = nowRow; i <= H; i++) {
		if (mLen[i] <= W) {
			if (mLen[i] == W) {
				rStart[i + 1] = tail->prev;
			}

			break;
		}

		mCount[i][rStart[i + 1]->_c - 'a']--;
		mLen[i]--;
		mCount[i + 1][rStart[i + 1]->_c - 'a']++;
		mLen[i + 1]++;
		rStart[i + 1] = rStart[i + 1]->prev;

	}

	nowCol++;
	if (nowCol > W) {
		nowRow++; nowCol = 1;
		memset(prevChar, 0, sizeof(prevChar));
		//Cur = rStart[nowRow];
	}
	Cur = Cur->next;
	//print();
}

char moveCursor(int mRow, int mCol)
{
	memset(prevChar, 0, sizeof(prevChar));
	nowRow = mRow; nowCol = mCol;

	if ((mRow - 1) * W + mCol > Total) {
		nowRow = (Total) / W + 1;
		nowCol = (Total) % W + 1;
	}

	Cur = rStart[nowRow];

	for (int i = 0; i < nowCol - 1; i++) {
		if (Cur->next == tail) return '$';
		prevChar[Cur->next->_c - 'a']++;
		Cur = Cur->next;
	} 
	if (Cur->next == tail) return '$';
	
	return Cur->next->_c;
}

int countCharacter(char mChar)
{
	int ret = 0;
	for (int i = nowRow; mLen[i] != 0; i++) {
		ret += mCount[i][mChar - 'a'];
	}
	return ret - prevChar[mChar - 'a'];
}
