#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <string.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Trie {
	bool isEnd;
	int rID;
	Trie* children[26];

	void insert(const char*);
	int findRestaurant(const char*);
};

typedef struct _Restaurant {
	int score;
	int CityID;
} Restaurant;

int N, M;
int adj[51][51];
//top3 ������ �ƴ϶� ������� ��ȣ�� �����س��߰ڴ�.
int Top3[51][3];
Restaurant R[10001]; int rCount;
Trie TriePool[50000]; int tCount;
Trie* root;

Trie* allocTrie() {
	Trie* newTrie = &TriePool[tCount++];
	newTrie->isEnd = false;
	newTrie->rID = -1;
	for (int i = 0; i < 26; i++)
		newTrie->children[i] = NULL;
	return newTrie;
}

void Trie::insert(const char* str) {
	if (!(*str)) {
		this->isEnd = true;
		this->rID = rCount;
		return;
	}
	int index = *str - 'a';
	if (!children[index]) children[index] = allocTrie();
	children[index]->insert(str + 1);
}

int Trie::findRestaurant(const char* str) {
	if (!(*str))
		return this->rID;
	else if (isEnd)
		return -1;
	return children[(*str)-'a']->findRestaurant(str + 1);
}

void init(int _N, int _M, int mRoads[][2])
{
	N = _N, M = _M;
	memset(adj, 0, sizeof(adj));
	memset(R, 0, sizeof(R)); rCount = 1;
	memset(Top3, 0, sizeof(Top3));

	tCount = 0; root = allocTrie();

	for (int i = 0; i < M; i++) {
		adj[mRoads[i][0]][mRoads[i][1]] = 1;
		adj[mRoads[i][1]][mRoads[i][0]] = 1;
	}
}

void addRestaurant(int mCityID, char mName[])
{
	//trie�� mName �߰�
	root->insert(mName);

	//��������� ���� ��ȣ �߰�
	R[rCount].CityID = mCityID;

	//������� ���� �ʱ�ȭ
	R[rCount].score = 0;

	//������� ���� ������Ʈ
	rCount++;
}

void addValue(char mName[], int mScore)
{
	//trie���� ������� ��ȣ ã��
	int rID = root->findRestaurant(mName);

	//�ش� ������� ��ȣ�� mScore ����
	R[rID].score += mScore;

	//���ÿ��� top3 ������� ������ �ִ� ��� �ݿ�
	//�׳� ������ ������ ���ϸ� �ȵǰ� ������� ��ȣ�� ���ߵ�

	//��������� �ִ� ���� ��ȣ
	int CityID = R[rID].CityID;

	//Top3[CityID] ��������
	bool flag = false;
	int rank = 3;
	for (int i = 0; i < 3; i++) {
		if (Top3[CityID][i] == rID) {
			flag = true;
			rank = i;
			break;
		}
	}
	//rank�� �ʱⰪ�� 3���� �ָ� Top3�� 
	//�̹� �ش� ��������� �ִ� ��� ���� ��� �� �� Ŀ�� ����
	for (int i = 0; i < rank; i++) {
		//���� ������ �Ͼ�� ���
		if (R[Top3[CityID][i]].score < R[rID].score) {
			for (int j = 2; j > i; j--) {
				Top3[CityID][j] = Top3[CityID][j - 1];
			}
			Top3[CityID][i] = rID;
			break;
		}
	}
}

int bestValue(char mStr[])
{
	int best = 0;
	//�� �߶󰡸鼭 trie���� ������� ã�ƺ�
	for (int i = 0; i < strlen(mStr); i++) {
		int rID = root->findRestaurant(mStr + i);
		//�ش� �̸��� ��������� �̸��� �ִ� ��쿡 best �� ����
		if (rID != -1) {
			best = max(best, R[rID].score);
		}
	}

	//�� �߶󰡸鼭 trie���� ������� ã�ƺ�
	char temp[6];
	strcpy(temp, mStr);
	for (int i = strlen(mStr) - 1; i > 0; i--) {
		temp[i] = '\0';
		int rID = root->findRestaurant(temp);
		//�ش� �̸��� ��������� �̸��� �ִ� ��쿡 best �� ����
		if (rID != -1) {
			best = max(best, R[rID].score);
		}
	}

	return best;
}

int regionalValue(int mCityID, int mDist)
{
	//BFS�� �׷��� Ž���ϸ鼭 �ش� ���ÿ��� top3 �迭 Ž��
	queue<int> q;
	//�׳� heap���ٰ� ����ְ� �������� 3�� ���� ���ݾ�
	priority_queue<int> pq;
	bool visited[50]; memset(visited, false, sizeof(visited));

	q.push(mCityID);
	visited[mCityID] = true;

	for (int i = 0; i < 3; i++) {
		if (q.empty()) break;

		int curCity = q.front(); q.pop();

		for (int i = 1; i <= N; i++) {
			if (adj[curCity][i] == 1 && !visited[i])
				q.push(i);
		}

		//���� ���� top3�� ��� pq�� ���� ����
		for (int i = 0; i < 3; i++) {
			if (Top3[curCity] == 0) break;
			pq.push(R[Top3[curCity][i]].score);
		}
	}
	
	
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		if (pq.empty()) break;
		ans += pq.top(); pq.pop();
	}

	return ans;
}