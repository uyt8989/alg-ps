#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <vector>

#define MAX_N 1000
#define MAX_K 300
#define MAX_MAIL 10000
#define MAX_WORD 10000
#define MAX_WORD_LEN 11
#define MAX_WORD_IN_STR 10
#define MAX_STR_LEN MAX_WORD_LEN * MAX_WORD_IN_STR

using namespace std;

typedef struct _TRIE {
	int WordNum;
	_TRIE* next[26];

	int insert(const char* str);
	int find(const char* str);
}TRIE;

//유저 수, 받은 메일함 크기
int N, K;
//트라이 자료구조
TRIE TriePool[MAX_WORD * (MAX_WORD_LEN + 1) + 1];
TRIE* root;
//userID가 받은 메일함
vector<int> MailBox[MAX_N];
//받은 메일함의 크기
int MailBoxSize[MAX_N];
//메일 정보 저장
int Mail[MAX_MAIL][MAX_K];
//트라이 노드의 개수, 메일의 개수, 단어의 개수
int trie, mail, word;

//트라이에 노드 할당
TRIE* allocTRIE() {
	TRIE* newTRIE = &TriePool[trie++];
	newTRIE->WordNum = -1;
	for (int i = 0; i < 26; i++) {
		newTRIE->next[i] = NULL;
	}
	return newTRIE;
}

//트라이에 단어 삽입
int TRIE::insert(const char* str) {
	if (!(*str)) {
		//처음 들어온 단어라면 번호 부여
		if (this->WordNum == -1)
			this->WordNum = word++;
		//단어 번호 리턴
		return this->WordNum;
	}
	int c = *str - 'a';
	if (!next[c]) {
		next[c] = allocTRIE();
	}
	return next[c]->insert(str + 1);
}

//트라이에서 단어 검색
int TRIE::find(const char* str) {
	if (!(*str)) {
		//단어 번호 리턴, 없는 경우엔 -1
		return WordNum;
	}
	int c = *str - 'a';
	if (next[c] == NULL) return -1;
	return next[c]->find(str + 1);
}

//초기화 함수
void init(int Users, int Mails) {
	N = Users; K = Mails;
	trie = 0; mail = 0; word = 0;

	//받은 메일함 초기화
	for (int i = 0; i < MAX_N; i++)
		MailBox[i].clear();
	//받은 메일함 크기 초기화
	memset(MailBoxSize, 0, sizeof(MailBoxSize));
	//메일 정보 초기화
	memset(Mail, -1, sizeof(Mail));
	//트라이 루트 할당
	root = allocTRIE();
}

//subject를 parsing하는 함수
//str에 parse된 문자열 저장하고 str 길이 리턴
int parseSubject(char *subject, char *str) {
	int i = 0;

	//공백이나 널문자 만나면 종료
	while (subject[i] != ' ' && subject[i] != '\0') {
		str[i] = subject[i];
		i++;
	}
	str[i] = '\0';

	return i;
}


void sendMail(char subject[], int uID, int cnt, int rIDs[]) {
	char str[MAX_WORD_LEN];
	int i = 0, j = 0;

	//subject parsing -> 단어 번호 가져옴 -> 메일 정보 저장
	while (subject[i] != '\0') {
		//공백인 경우 인덱스를 하나 증가시킴
		if (subject[i] == ' ') i++;
		int t = parseSubject(subject + i, str);
		//이번 문자열의 길이가 0인 경우
		if (t == 0) break;
		int WordNum = root->insert(str);
		Mail[mail][j++] = WordNum;
		i += t;
	}

	//받은 메일함에 메일 추가
	for (int i = 0; i < cnt; i++) {
		int user = rIDs[i];
		
		if (MailBoxSize[user] >= K) {
			//받은 메일함이 꽉 찬 경우
			//가장 앞에 있는 메일 삭제
			MailBox[user].erase(MailBox[user].begin());
			MailBoxSize[user]--;
		}
		//받은 메일함에 이번 메일 추가
		MailBox[user].push_back(mail);
		//받은 메일함 크기 증가
		MailBoxSize[user]++;
	}

	//메일 개수 증가
	mail++;

	return;
}

//받은 메일함 크기 리턴
int getCount(int uID) {
	return MailBoxSize[uID];
}

int deleteMail(int uID, char subject[]) {
	char str[MAX_WORD_LEN];
	int i = 0, j = 0;
	//입력으로 들어온 subject에 있는 단어 번호 저장
	int temp[MAX_WORD_IN_STR];

	//subject parsing -> 단어 번호 가져옴 -> 메일 정보 저장
	while (subject[i] != '\0') {
		if (subject[i] == ' ') i++;
		int t = parseSubject(subject + i, str);
		if (t == 0) break;

		//트라이에서 단어 검색
		int WordNum = root->find(str);
		if (WordNum == -1) {
			//지금까지 들어온 적 없던 단어가 들어온 경우
			//당연히 받은 메일함에서 찾을 수 없음
			return 0;
		}
		temp[j++] = WordNum;

		i += t;
	}
	
	int ret = 0;
	//받은 메일함 따라가면서 subject랑 똑같은 문자열있으면 삭제
	vector<int>::iterator iter = MailBox[uID].begin();
	for (; iter != MailBox[uID].end();) {
		bool flag = true;
		int MailNum = *iter;
	
		if (Mail[MailNum][j] != -1) {
			++iter;
			continue;
		}

		//subject 길이만큼 for문
		for (int k = 0; k < j; k++) {
			//subject랑 단어가 다른 경우
			if (Mail[MailNum][k] != temp[k]) {
				flag = false;
				break;
			}
		}

		//두 문자열이 같은 경우 vector에서 삭제
		if (flag == true) {
			iter = MailBox[uID].erase(iter);
			MailBoxSize[uID]--;
			ret++;
			continue;
		}

		++iter;
	}

	return ret;
}

int searchMail(int uID, char text[]) {
	//MailBox 따라가면서 text를 포함하는 문자열 몇개인지 찾기
	int WordNum = root->find(text);
	if (WordNum == -1) 
		return 0;

	int ret = 0;
	vector<int>::iterator iter = MailBox[uID].begin();
	for (; iter != MailBox[uID].end();) {
		int MailNum = *iter;
		int j = 0;

		//메일 제목이 끝날 때까지
		while (Mail[MailNum][j] != -1) {
			//메일 제목에 text가 포함되어 있는 경우
			if (Mail[MailNum][j] == WordNum) {
				ret++;
				break;
			}

			j++;
		}

		++iter;
	}

	return ret;
}
