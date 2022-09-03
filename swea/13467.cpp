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
//top3 점수가 아니라 레스토랑 번호를 저장해놔야겠다.
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
	//trie에 mName 추가
	root->insert(mName);

	//레스토랑에 도시 번호 추가
	R[rCount].CityID = mCityID;

	//레스토랑 점수 초기화
	R[rCount].score = 0;

	//레스토랑 개수 업데이트
	rCount++;
}

void addValue(char mName[], int mScore)
{
	//trie에서 레스토랑 번호 찾음
	int rID = root->findRestaurant(mName);

	//해당 레스토랑 번호에 mScore 더함
	R[rID].score += mScore;

	//도시에서 top3 레스토랑 변동이 있는 경우 반영
	//그냥 무지성 점수만 비교하면 안되고 레스토랑 번호도 봐야됨

	//레스토랑이 있는 도시 번호
	int CityID = R[rID].CityID;

	//Top3[CityID] 갱신해줌
	bool flag = false;
	int rank = 3;
	for (int i = 0; i < 3; i++) {
		if (Top3[CityID][i] == rID) {
			flag = true;
			rank = i;
			break;
		}
	}
	//rank의 초기값을 3으로 주면 Top3에 
	//이미 해당 레스토랑이 있는 경우 없는 경우 둘 다 커버 가능
	for (int i = 0; i < rank; i++) {
		//순위 변동이 일어나는 경우
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
	//앞 잘라가면서 trie에서 레스토랑 찾아봄
	for (int i = 0; i < strlen(mStr); i++) {
		int rID = root->findRestaurant(mStr + i);
		//해당 이름의 레스토랑의 이름이 있는 경우에 best 값 갱신
		if (rID != -1) {
			best = max(best, R[rID].score);
		}
	}

	//뒤 잘라가면서 trie에서 레스토랑 찾아봄
	char temp[6];
	strcpy(temp, mStr);
	for (int i = strlen(mStr) - 1; i > 0; i--) {
		temp[i] = '\0';
		int rID = root->findRestaurant(temp);
		//해당 이름의 레스토랑의 이름이 있는 경우에 best 값 갱신
		if (rID != -1) {
			best = max(best, R[rID].score);
		}
	}

	return best;
}

int regionalValue(int mCityID, int mDist)
{
	//BFS로 그래프 탐색하면서 해당 도시에서 top3 배열 탐색
	queue<int> q;
	//그냥 heap에다가 집어넣고 마지막에 3개 빼면 되잖아
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

		//현재 도시 top3를 모두 pq에 집어 넣음
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