#include <cstring>

#define MAX_N 1001
#define MAX_POST 100001

typedef struct _Post {
	int uID;
	int like = 0;
	int timestamp;
}Post;

bool following[MAX_N][MAX_N];
Post post[MAX_POST];
int last_pID;

bool check_follow(int uID1, int uID2) {
	return following[uID1][uID2];
}

void init(int N)
{
	memset(following, false, sizeof(following));
	for (int i = 1; i <= N; i++)
		following[i][i] = true;
	memset(post, 0, sizeof(post));
	last_pID = 0;
}

void follow(int uID1, int uID2, int timestamp)
{
	following[uID1][uID2] = true;
}

void makePost(int uID, int pID, int timestamp)
{
	post[pID].uID = uID;
	post[pID].like = 0;
	post[pID].timestamp = timestamp;
	last_pID++;
}

void like(int pID, int timestamp)
{
	post[pID].like++;
}

void getFeed(int uID, int timestamp, int pIDList[])
{
	int last_feed = -1;

	for (int i = 0; i < 10; i++) {
		pIDList[i] = 0;
	}

	for (int insert_pID = last_pID; insert_pID > 0; insert_pID--) {
		//follow하는 user의 post만 체크
		if (check_follow(uID, post[insert_pID].uID) == true) {
			//1000초 이내에 작성된 글일 경우
			if (timestamp - post[insert_pID].timestamp <= 1000) {
				//아직 feed에 아무것도 없는 경우
				if (last_feed == -1) {
					pIDList[0] = insert_pID;
					last_feed++;
				}
				else {
					//like 기준으로 삽입정렬
					int insert_idx = -1;
					for (int i = 0; i <= last_feed; i++) {
						int compare_pID = pIDList[i];
						if (post[compare_pID].like < post[insert_pID].like) {
							insert_idx = i;
							break;
						}
					}

					//삽입될 자리를 찾은 경우
					if (insert_idx != -1) {
						//feed가 아직 비어있는 경우
						for (int i = 9; i > insert_idx; i--) {
							pIDList[i] = pIDList[i - 1];
						}
						pIDList[insert_idx] = insert_pID;
						if (last_feed < 9) last_feed++;
					}
					//삽입될 자리는 못 찾았는데 아직 feed에 빈자리가 있는 경우
					else if (last_feed < 9) {
						pIDList[++last_feed] = insert_pID;
					}
				}
			}
			//이번 글이 1000초 이내에 작성되지 않은 경우엔 
			//다음 글들도 모두 1000초 초과임
			else {
				if (last_feed < 9)  
					pIDList[++last_feed] = insert_pID;
				else
					return;
			}
		}
	}
	return;
}
